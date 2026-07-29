import cv2
import tkinter as tk
from tkinter import ttk, filedialog, messagebox
from PIL import Image, ImageTk
import numpy as np
import matplotlib
from canny import run_canny
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
# Enhanced Image Processing Functions

def preprocess_image(img):
    """
    Comprehensive preprocessing pipeline that handles both color and grayscale images.
    """
    check = True
    for i in range((img.shape[0])):
        for j in range(img.shape[1]):
            if len(set(img[i][j])) <= 1:
                check = False
            else:
                check = True
    print(img.shape)
    if  check:
        # Color image preprocessing
        # 1. White balance correction
        img = white_balance_advanced(img)

        # 2. Noise reduction
        img = cv2.bilateralFilter(img, 9, 75, 75)

        # 3. Convert to grayscale for edge detection
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    else:
        print("in gray")

        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        # 3. (Optional) Blur to help Otsu find a cleaner threshold
        blur = cv2.GaussianBlur(gray, (5, 5), 0)

        # 4. Otsu’s thresholding
        _, gray = cv2.threshold(
            blur,
            0,                       # ignored when using THRESH_OTSU
            255,                     # max value for THRESH_BINARY
            cv2.THRESH_BINARY + cv2.THRESH_OTSU
        )

    return gray, img


def white_balance_advanced(img):
    """
    Advanced white balance using Gray World assumption with color temperature correction.
    """
    result = img.astype(np.float64)

    # Gray World assumption: the average of the image should be gray
    avg_b = np.mean(result[:, :, 0])
    avg_g = np.mean(result[:, :, 1])
    avg_r = np.mean(result[:, :, 2])

    # Calculate scaling factors
    avg_gray = (avg_b + avg_g + avg_r) / 3

    if avg_b > 0 and avg_g > 0 and avg_r > 0:
        result[:, :, 0] *= avg_gray / avg_b
        result[:, :, 1] *= avg_gray / avg_g
        result[:, :, 2] *= avg_gray / avg_r

    # Clip values to valid range
    result = np.clip(result, 0, 255)
    return result.astype(np.uint8)



def optimized_hough_transform(edges, theta_resolution=1):
    """
    Highly optimized Hough transform using vectorized operations.
    """
    height, width = edges.shape

    # Use smaller theta resolution for speed while maintaining accuracy
    thetas = np.deg2rad(np.arange(-90, 90, theta_resolution))

    # Calculate diagonal length
    diag_len = int(np.ceil(np.sqrt(height ** 2 + width ** 2)))
    rho_max = diag_len
    rho_resolution = 1

    # Create rho array
    rhos = np.arange(-rho_max, rho_max + 1, rho_resolution)

    # Initialize accumulator
    accumulator = np.zeros((len(rhos), len(thetas)), dtype=np.int32)

    # Get edge pixel coordinates
    edge_pixels = np.where(edges > 0)
    y_coords, x_coords = edge_pixels

    if len(x_coords) == 0:
        return accumulator, thetas, rhos, edges

    # Vectorized computation
    cos_thetas = np.cos(thetas)
    sin_thetas = np.sin(thetas)

    # Process in batches to avoid memory issues
    batch_size = 1000
    for i in range(0, len(x_coords), batch_size):
        end_idx = min(i + batch_size, len(x_coords))
        x_batch = x_coords[i:end_idx]
        y_batch = y_coords[i:end_idx]

        # Calculate rho for all combinations of pixels and angles
        x_expanded = x_batch[:, np.newaxis]
        y_expanded = y_batch[:, np.newaxis]

        rho_values = x_expanded * cos_thetas + y_expanded * sin_thetas
        rho_indices = np.round(rho_values).astype(int) + rho_max

        # Clip to valid range
        valid_mask = (rho_indices >= 0) & (rho_indices < len(rhos))

        for j in range(len(thetas)):
            valid_rhos = rho_indices[valid_mask[:, j], j]
            if len(valid_rhos) > 0:
                np.add.at(accumulator[:, j], valid_rhos, 1)

    return accumulator, thetas, rhos, edges


# Main Application Class (Enhanced)

class DocumentScannerApp:
    def __init__(self, window):
        self.window = window
        self.window.title("Enhanced Document Scanner")
        self.window.geometry("1200x800")
        self.window.minsize(1000, 700)

        # --- Class Attributes ---
        self.cap = None
        self.running = False
        self.original_image = None
        self.preprocessed_image = None  # Store preprocessed version
        self.last_scanned = None
        self.ordered_corners = None

        # --- UI and Processing Variables ---
        self.camera_selected_option = tk.StringVar(value="0")
        self.sharpen_checkbox = tk.BooleanVar(value=True)
        self.threshold_ratio = tk.DoubleVar(value=0.45)
        self.preprocessing_enabled = tk.BooleanVar(value=True)
        self.kernel_sharp = np.array([[0, -1, 0], [-1, 5, -1], [0, -1, 0]])

        self.setup_styles()
        self.setup_ui()
        self.warped_page = None  # full page after perspective warp

    def setup_styles(self):
        """Configures ttk styles for the application."""
        style = ttk.Style()
        style.theme_use('clam')
        style.configure("TLabel", font=("Helvetica", 10))
        style.configure("TButton", font=("Helvetica", 10))
        style.configure("TEntry", font=("Helvetica", 10))
        style.configure("Accent.TButton", font=("Helvetica", 10, "bold"), foreground="white", background="#0078D7")
        style.configure("TLabelframe.Label", font=("Helvetica", 11, "bold"))

    def setup_ui(self):
        """Builds the main UI layout."""
        self.window.columnconfigure(0, weight=1)
        self.window.rowconfigure(1, weight=1)

        # Top Control Panel
        control_frame = ttk.Frame(self.window, padding="10")
        control_frame.grid(row=0, column=0, sticky="ew", padx=10, pady=5)
        self.create_control_panel(control_frame)

        # Main Content Area
        main_paned_window = ttk.PanedWindow(self.window, orient="horizontal")
        main_paned_window.grid(row=1, column=0, sticky="nsew", padx=10, pady=(0, 10))

        # Image Display Panel
        image_display_frame = ttk.Frame(main_paned_window)
        main_paned_window.add(image_display_frame, weight=3)
        self.create_image_display_panel(image_display_frame)

        # Controls Panel
        controls_frame = ttk.Frame(main_paned_window, width=380)
        main_paned_window.add(controls_frame, weight=1)
        self.create_scanning_controls(controls_frame)
        controls_frame.pack_propagate(False)

        # Status Bar
        self.status_var = tk.StringVar(value="Ready. Please import an image or start the camera.")
        status_bar = ttk.Label(self.window, textvariable=self.status_var, relief="sunken", anchor="w", padding="5")
        status_bar.grid(row=2, column=0, sticky="ew", padx=10, pady=(2, 5))

        self.window.protocol("WM_DELETE_WINDOW", self.on_closing)

    def create_control_panel(self, parent):
        """Creates the top control panel."""
        parent.columnconfigure(1, weight=1)

        # Camera Controls
        camera_frame = ttk.LabelFrame(parent, text="Camera", padding="10")
        camera_frame.grid(row=0, column=0, sticky="w", padx=(0, 10))

        ttk.Label(camera_frame, text="Device:").grid(row=0, column=0, sticky="w", padx=(0, 5))
        camera_combo = ttk.Combobox(camera_frame, textvariable=self.camera_selected_option,
                                    values=["0", "1", "2"], width=3, state="readonly")
        camera_combo.grid(row=0, column=1, padx=(0, 10))
        ttk.Button(camera_frame, text="Start", command=self.start_camera).grid(row=0, column=2, padx=2)
        ttk.Button(camera_frame, text="Capture", command=self.capture_frame).grid(row=0, column=3, padx=2)
        ttk.Button(camera_frame, text="Reset", command=self.reset_camera).grid(row=0, column=4, padx=2)

        # File Operations
        file_frame = ttk.LabelFrame(parent, text="File", padding="10")
        file_frame.grid(row=0, column=1, sticky="ew")

        ttk.Button(file_frame, text="Import Image", command=self.import_file).pack(side="left", padx=2)
        ttk.Button(file_frame, text="Save Scanned", command=self.save_scanned_document).pack(side="left", padx=2)
        ttk.Button(file_frame, text="Exit", command=self.on_closing).pack(side="right", padx=2)

    def create_image_display_panel(self, parent):
        """Creates the image display panel."""
        parent.columnconfigure(0, weight=1)
        parent.rowconfigure(0, weight=1)

        self.image_label = ttk.Label(parent, text="No Image Loaded", anchor="center",
                                     background="white", relief="sunken")
        self.image_label.grid(row=0, column=0, sticky="nsew")

    def create_scanning_controls(self, parent):
        """Creates the scanning controls panel."""
        parent.columnconfigure(0, weight=1)

        # Preprocessing Section
        preprocess_frame = ttk.LabelFrame(parent, text="Preprocessing", padding="10")
        preprocess_frame.grid(row=0, column=0, sticky="ew", padx=10, pady=10)
        preprocess_frame.columnconfigure(0, weight=1)

        ttk.Checkbutton(preprocess_frame, text="Enable Advanced Preprocessing",
                        variable=self.preprocessing_enabled).grid(row=0, column=0, sticky="w", pady=5)
        ttk.Button(preprocess_frame, text="Show Preprocessed",
                   command=self.show_preprocessed).grid(row=1, column=0, sticky="ew", pady=5)

        # Scanning Section
        scan_frame = ttk.LabelFrame(parent, text="Scan Controls", padding="10")
        scan_frame.grid(row=1, column=0, sticky="ew", padx=10, pady=10)
        scan_frame.columnconfigure(1, weight=1)

        ttk.Label(scan_frame, text="Line Detection Threshold:").grid(row=0, column=0, sticky="w", pady=5)
        ttk.Scale(scan_frame, from_=0.1, to=1.0, orient="horizontal",
                  variable=self.threshold_ratio).grid(row=0, column=1, sticky="ew", padx=5)

        ttk.Checkbutton(scan_frame, text="Apply Sharpen Filter",
                        variable=self.sharpen_checkbox).grid(row=1, column=0, columnspan=2, sticky="w", pady=5)

        ttk.Button(scan_frame, text="Scan Document", command=self.scan_document,
                   style="Accent.TButton").grid(row=2, column=0, columnspan=2, sticky="ew", pady=10)

        # Adjustment Section
        adjust_frame = ttk.LabelFrame(parent, text="Fine Adjustments", padding="10")
        adjust_frame.grid(row=2, column=0, sticky="ew", padx=10, pady=10)
        adjust_frame.columnconfigure(1, weight=1)

        self.crop_x_left = tk.IntVar(value=0)
        self.crop_y_left = tk.IntVar(value=0)
        self.crop_x_right = tk.IntVar(value=0)
        self.crop_y_right = tk.IntVar(value=0)

        ttk.Label(adjust_frame, text="Top-Left (x, y):").grid(row=0, column=0, sticky="w")
        ttk.Entry(adjust_frame, textvariable=self.crop_x_left, width=5).grid(row=0, column=1, sticky="e", padx=2)
        ttk.Entry(adjust_frame, textvariable=self.crop_y_left, width=5).grid(row=0, column=2, sticky="e")

        ttk.Label(adjust_frame, text="Bottom-Right (x, y):").grid(row=1, column=0, sticky="w", pady=5)
        ttk.Entry(adjust_frame, textvariable=self.crop_x_right, width=5).grid(row=1, column=1, sticky="e", padx=2)
        ttk.Entry(adjust_frame, textvariable=self.crop_y_right, width=5).grid(row=1, column=2, sticky="e")
        ttk.Button(adjust_frame, text="Apply Crop",
                   command=self.crop_current).grid(row=2, column=0, columnspan=3, sticky="ew", pady=10)



    def update_status(self, message):
        """Updates the status bar."""
        self.status_var.set(message)
        self.window.update_idletasks()

    def start_camera(self):
        """Starts the camera feed."""
        if self.running:
            self.update_status("Camera is already running.")
            return

        try:
            camera_index = int(self.camera_selected_option.get())
            self.cap = cv2.VideoCapture(camera_index)
            if not self.cap.isOpened():
                raise IOError(f"Cannot open camera {camera_index}")

            self.running = True
            self.update_status(f"Camera {camera_index} started.")
            self._update_frame()
        except (ValueError, IOError) as e:
            messagebox.showerror("Camera Error", f"Failed to start camera: {e}")
            self.update_status("Error: Could not start camera.")

    def _update_frame(self):
        """Updates camera frames."""
        if self.running and self.cap:
            ret, frame = self.cap.read()
            if ret:
                self.display_image(frame, self.image_label)
            self.window.after(15, self._update_frame)

    def display_image(self, img, label_widget):
        """Displays an image on a label widget."""
        if img is None or not hasattr(label_widget, 'winfo_width'):
            return

        label_width = label_widget.winfo_width()
        label_height = label_widget.winfo_height()

        if label_width <= 1 or label_height <= 1:
            label_widget.after(20, lambda: self.display_image(img, label_widget))
            return

        # Convert color space
        if len(img.shape) == 3:
            img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        else:
            img_rgb = cv2.cvtColor(img, cv2.COLOR_GRAY2RGB)

        # Scale to fit
        img_height, img_width = img_rgb.shape[:2]
        scale = min(label_width / img_width, label_height / img_height, 1.0)
        new_width = int(img_width * scale)
        new_height = int(img_height * scale)

        img_pil = Image.fromarray(img_rgb).resize((new_width, new_height), Image.Resampling.LANCZOS)
        imgtk = ImageTk.PhotoImage(image=img_pil)

        label_widget.configure(image=imgtk, text="")
        label_widget.image = imgtk

    def capture_frame(self):
        """Captures a frame from the camera."""
        if not self.running or not self.cap or not self.cap.isOpened():
            messagebox.showwarning("Capture Warning", "Camera not started.")
            return

        ret, frame = self.cap.read()
        if ret:
            self.original_image = frame.copy()
            self.reset_camera()
            self.display_image(self.original_image, self.image_label)
            self.update_status("Image captured successfully.")
        else:
            messagebox.showerror("Capture Error", "Failed to capture frame.")

    def reset_camera(self):
        """Resets the camera."""
        self.running = False
        if self.cap:
            self.cap.release()
            self.cap = None
        self.update_status("Camera reset.")

    def import_file(self):
        """Imports an image file."""
        file_path = filedialog.askopenfilename(
            title="Select an Image",
            filetypes=[("Image Files", "*.jpg *.jpeg *.png *.bmp *.tiff"), ("All files", "*.*")]
        )
        if not file_path:
            return

        try:
            img = cv2.imread(file_path)
            if img is None:
                raise ValueError("Invalid image file.")

            self.reset_camera()
            self.original_image = img
            self.display_image(self.original_image, self.image_label)
            self.update_status(f"Imported: {file_path.split('/')[-1]}")
        except (IOError, ValueError) as e:
            messagebox.showerror("Import Error", f"Failed to import: {e}")

    def show_preprocessed(self):
        """Shows the preprocessed image."""
        if self.original_image is None:
            messagebox.showwarning("Warning", "No image loaded.")
            return

        try:
            if self.preprocessing_enabled.get():
                gray, processed_color = preprocess_image(self.original_image)
                self.show_result_window(processed_color, "Preprocessed Image")
            else:
                self.show_result_window(self.original_image, "Original Image")
        except Exception as e:
            messagebox.showerror("Error", f"Preprocessing failed: {e}")

    def scan_document(self):
        """Enhanced document scanning pipeline."""
        if self.original_image is None:
            messagebox.showwarning("Warning", "No image to scan.")
            return

        self.update_status("Scanning... Preprocessing image...")

        try:
            # Step 1: Preprocessing
            if self.preprocessing_enabled.get():
                gray, processed_color = preprocess_image(self.original_image)
                self.preprocessed_image = processed_color
            else:
                if len(self.original_image.shape) == 3:
                    gray = cv2.cvtColor(self.original_image, cv2.COLOR_BGR2GRAY)
                else:
                    gray = self.original_image
                self.preprocessed_image = self.original_image

            edges = run_canny(gray,
                          gaussian_size=5,
                          gaussian_sigma=1.4,
                          low_thresh_ratio=0.05,
                          high_thresh_ratio=0.15)
            # Step 3: Optimized Hough transform

            accumulator, thetas, rhos, _ = optimized_hough_transform(edges)

            # Step 4: Find orthogonal lines
            orthogonal_pairs = self.find_orthogonal_lines(accumulator, thetas, rhos, self.threshold_ratio.get())

            if not orthogonal_pairs:
                messagebox.showwarning("Scan Failed", "No document edges detected.")
                self.update_status("Scan failed: No lines found.")
                return

            lines_img = self.draw_detected_lines(self.preprocessed_image, orthogonal_pairs)
            self.show_result_window(lines_img, "Detected Lines")

            # Step 5: Find intersections and corners
            self.update_status("Scanning... Finding corners...")
            corners = self.find_intersections(orthogonal_pairs)
            if len(corners) < 4:
                messagebox.showwarning("Scan Failed", "Could not find 4 corners.")
                self.update_status("Scan failed: Not enough corners.")
                return

            # Step 6: Filter and order corners
            corners = self.filter_corner_points(corners)
            self.ordered_corners = self.order_corners(corners)

            # Step 7: Perspective transform (no crop)
            self.update_status("Scanning... Applying perspective transform...")
            self.warped_page = self.perspective_transform(self.preprocessed_image,
                                                          self.ordered_corners)
            scanned_img = self.warped_page.copy()
            # Step 8: Post-processing
            if self.sharpen_checkbox.get():
                scanned_img = cv2.filter2D(scanned_img, -1, self.kernel_sharp)

            self.last_scanned = scanned_img
            self.show_result_window(self.last_scanned, "Final Scanned Document")
            self.update_status("Document scanned successfully!")

        except Exception as e:
            messagebox.showerror("Scanning Error", f"Scanning failed: {e}")
            self.update_status("Scanning failed.")

    def crop_current(self):
        """Crop self.warped_page using the margin fields."""
        if self.warped_page is None:
            messagebox.showwarning("Warning", "Please scan a document first.")
            return

        try:
            left = max(0, int(self.crop_x_left.get()))
            top = max(0, int(self.crop_y_left.get()))
            right = max(0, int(self.crop_x_right.get()))
            bottom = max(0, int(self.crop_y_right.get()))
        except tk.TclError:
            messagebox.showerror("Error", "Invalid crop values.")
            return

        h, w = self.warped_page.shape[:2]
        x0, y0 = left, top
        x1, y1 = w - right, h - bottom

        if x1 <= x0 or y1 <= y0:
            messagebox.showerror("Crop Error", "Crop rectangle is empty.")
            return

        cropped = self.warped_page[y0:y1, x0:x1].copy()

        if self.sharpen_checkbox.get():
            cropped = cv2.filter2D(cropped, -1, self.kernel_sharp)

        self.last_scanned = cropped
        self.show_result_window(cropped, "Cropped Document")
        self.update_status("Cropped successfully.")

    def find_orthogonal_lines(self, accumulator, thetas, rhos, threshold_ratio):
        """Finds orthogonal line pairs from the Hough accumulator."""
        max_votes = np.max(accumulator)
        threshold = int(threshold_ratio * max_votes)

        # Find peaks in the accumulator
        rho_indices, theta_indices = np.where(accumulator >= threshold)

        lines = []
        for i in range(len(rho_indices)):
            lines.append((rhos[rho_indices[i]], thetas[theta_indices[i]]))

        # Find orthogonal pairs
        orthogonal_pairs = []
        for i in range(len(lines)):
            for j in range(i + 1, len(lines)):
                _, theta1 = lines[i]
                _, theta2 = lines[j]
                angle_diff = abs(np.rad2deg(theta1 - theta2))

                # Check for orthogonality (90 degrees ± tolerance)
                if abs(angle_diff - 90) < 10 or abs(angle_diff - 90) > 170:
                    orthogonal_pairs.append((lines[i], lines[j]))

        return orthogonal_pairs

    def draw_detected_lines(self, img, orthogonal_pairs):
        """Draws detected lines on the image."""
        lines_img = img.copy()
        for pair in orthogonal_pairs:
            for rho, theta in pair:
                a, b = np.cos(theta), np.sin(theta)
                x0, y0 = a * rho, b * rho
                pt1 = (int(x0 + 2000 * (-b)), int(y0 + 2000 * (a)))
                pt2 = (int(x0 - 2000 * (-b)), int(y0 - 2000 * (a)))
                cv2.line(lines_img, pt1, pt2, (0, 255, 0), 2, cv2.LINE_AA)
        return lines_img

    def find_intersections(self, orthogonal_pairs):
        """Finds intersection points of orthogonal line pairs."""
        intersections = []
        for (rho1, theta1), (rho2, theta2) in orthogonal_pairs:
            A = np.array([
                [np.cos(theta1), np.sin(theta1)],
                [np.cos(theta2), np.sin(theta2)]
            ])
            b = np.array([[rho1], [rho2]])

            det = np.linalg.det(A)
            if abs(det) > 1e-10:  # Avoid singular matrices
                px,py = np.linalg.solve(A, b)
                x, y = int(px), int(py)

                # Filter out points that are too far outside the image
                height, width = self.original_image.shape[:2]
                if -width * 0.1 <= x <= width * 1.1 and -height * 0.1 <= y <= height * 1.1:
                    intersections.append((x, y))

        return intersections

    def filter_corner_points(self, corners):
        """Filters corner points to find the document boundary."""
        if len(corners) < 4:
            return corners

        points = np.array(corners, dtype="float32")

        # Use convex hull to find the outermost points
        hull = cv2.convexHull(points)
        epsilon = 0.02 * cv2.arcLength(hull, True)
        approx = cv2.approxPolyDP(hull, epsilon, True)

        # If we don't get exactly 4 points, find the 4 corner points manually
        if len(approx) != 4:
            # Find the 4 extreme points
            points = hull.reshape(-1, 2)

            # Find centroid
            centroid = np.mean(points, axis=0)

            # Calculate angles from centroid to each point
            angles = np.arctan2(points[:, 1] - centroid[1], points[:, 0] - centroid[0])

            # Sort points by angle and take 4 most separated points
            sorted_indices = np.argsort(angles)
            sorted_points = points[sorted_indices]

            # Select 4 points that are most spread out
            if len(sorted_points) >= 4:
                step = len(sorted_points) // 4
                selected_indices = [0, step, 2 * step, 3 * step]
                selected_points = [sorted_points[i] for i in selected_indices]
                return [(int(pt[0]), int(pt[1])) for pt in selected_points]

        return [tuple(pt) for pt in approx.reshape(-1, 2)]

    def order_corners(self, corners):
        """
        Orders corner points consistently: top-left, top-right, bottom-right, bottom-left.
        """
        pts = np.array(corners, dtype="float32")
        ordered = np.zeros((4, 2), dtype="float32")

        # Top-left has smallest sum, bottom-right has largest sum
        s = pts.sum(axis=1)
        ordered[0] = pts[np.argmin(s)]  # top-left
        ordered[2] = pts[np.argmax(s)]  # bottom-right

        # Top-right has smallest difference (x-y), bottom-left has largest difference
        diff = np.diff(pts, axis=1)
        ordered[1] = pts[np.argmin(diff)]  # top-right
        ordered[3] = pts[np.argmax(diff)]  # bottom-left

        return ordered

    def perspective_transform(self, img, corners):
        """
        Deskew the page. No cropping – returns the full, rectangular page.
        """
        ordered = self.order_corners(corners)  # tl, tr, br, bl
        (tl, tr, br, bl) = ordered

        # page size
        width = int(max(np.linalg.norm(tr - tl), np.linalg.norm(br - bl)))
        height = int(max(np.linalg.norm(bl - tl), np.linalg.norm(br - tr)))
        width = max(width, 100)
        height = max(height, 100)

        dst = np.array([[0, 0],
                        [width - 1, 0],
                        [width - 1, height - 1],
                        [0, height - 1]], dtype="float32")

        M = cv2.getPerspectiveTransform(ordered, dst)
        return cv2.warpPerspective(img, M, (width, height))
    def adjust_document(self):
        """Applies fine adjustments to the scanned document."""
        if self.original_image is None or self.ordered_corners is None:
            messagebox.showwarning("Warning", "Please scan a document first.")
            return

        try:
            x_left = int(self.crop_x_left.get())
            y_left = int(self.crop_y_left.get())
            x_right = int(self.crop_x_right.get())
            y_right = int(self.crop_y_right.get())

            adjusted_img = self.perspective_transform_fixed(
                self.preprocessed_image,
                self.ordered_corners,
                x_left, y_left, x_right, y_right
            )

            if self.sharpen_checkbox.get():
                adjusted_img = cv2.filter2D(adjusted_img, -1, self.kernel_sharp)

            self.last_scanned = adjusted_img
            self.show_result_window(self.last_scanned, "Adjusted Document")
            self.update_status("Document adjusted successfully.")

        except tk.TclError:
            messagebox.showerror("Error", "Invalid adjustment values.")
        except Exception as e:
            messagebox.showerror("Error", f"Adjustment failed: {e}")

    def save_scanned_document(self):
        """Saves the scanned document."""
        if self.last_scanned is None:
            messagebox.showwarning("Warning", "No scanned document to save.")
            return

        filepath = filedialog.asksaveasfilename(
            defaultextension=".png",
            filetypes=[("PNG file", "*.png"), ("JPEG file", "*.jpg"), ("All files", "*.*")],
            title="Save Scanned Document"
        )
        if not filepath:
            return

        try:
            cv2.imwrite(filepath, self.last_scanned)
            self.update_status(f"Document saved: {filepath.split('/')[-1]}")
            messagebox.showinfo("Success", "Document saved successfully!")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to save: {e}")

    def on_closing(self):
        """Cleanup when closing the application."""
        self.running = False
        if self.cap:
            self.cap.release()
        self.window.destroy()

    def show_result_window(self, img, title="Result"):
        """Shows an image in a new window."""
        result_window = tk.Toplevel(self.window)
        result_window.title(title)
        result_window.geometry("800x600")

        result_window.columnconfigure(0, weight=1)
        result_window.rowconfigure(0, weight=1)

        label = ttk.Label(result_window, background="gray")
        label.grid(row=0, column=0, sticky="nsew", padx=5, pady=5)

        # Bind resize event
        label.bind('<Configure>', lambda event, i=img, l=label: self.display_image(i, l))

        # Initial display
        self.display_image(img, label)



if __name__ == "__main__":
    root = tk.Tk()
    app = DocumentScannerApp(root)
    root.mainloop()
