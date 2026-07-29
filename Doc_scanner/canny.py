import numpy as np
import cv2
import matplotlib
matplotlib.use('TkAgg') # because problems of plot in pycharm
import matplotlib.pyplot as plt
from scipy.signal import convolve2d


def gaussian_kernel(size, sigma):
    """Generates a (size x size) Gaussian kernel."""
    ax = np.linspace(-(size // 2), size // 2, size)
    x, y = np.meshgrid(ax, ax)
    kernel = np.exp(-(x ** 2 + y ** 2) / (2 * sigma ** 2)) #Here we neglected the 1/2*pi*sigma^2 because we normalize afterwards so useless.
    kernel /= np.sum(kernel)
    return kernel


def convolve(image, kernel):
    """Performs 2D convolution using scipy."""
    return convolve2d(image, np.flip(kernel, axis=(0, 1)), mode='same', boundary='symm')


def sobel_filters(img):
    """Applies Sobel filters to find gradients."""
    Kx = np.array([[1, 0, -1],
                   [2, 0, -2],
                   [1, 0, -1]])
    Ky = np.array([[1, 2, 1],
                   [0, 0, 0],
                   [-1, -2, -1]])

    Ix = convolve(img, Kx)
    Iy = convolve(img, Ky)

    G = np.hypot(Ix, Iy)
    theta = np.arctan2(Iy, Ix)
    return G, theta


def non_max_suppression(G, theta):
    """Thins edges using non-maximum suppression."""
    M, N = G.shape
    Z = np.zeros((M, N), dtype=np.int32)
    angle = theta * 180. / np.pi
    angle[angle < 0] += 180

    for i in range(1, M - 1):
        for j in range(1, N - 1):
            q = r = 255
            if (0 <= angle[i, j] < 22.5) or (157.5 <= angle[i, j] <= 180):
                q = G[i, j + 1]
                r = G[i, j - 1]
            elif (22.5 <= angle[i, j] < 67.5):
                q = G[i + 1, j - 1]
                r = G[i - 1, j + 1]
            elif (67.5 <= angle[i, j] < 112.5):
                q = G[i + 1, j]
                r = G[i - 1, j]
            elif (112.5 <= angle[i, j] < 157.5):
                q = G[i - 1, j - 1]
                r = G[i + 1, j + 1]
            if G[i, j] >= q and G[i, j] >= r:
                Z[i, j] = G[i, j]
    return Z


def double_thresholding(G, lowRatio, highRatio):
    """Classify pixels into strong and weak edges using double thresholding."""
    high = G.max() * highRatio
    low = high * lowRatio #By scaling thresholds relative to the max gradient value, the algorithm is adaptive to image brightness and contrast

    strong_edges = np.zeros_like(G)
    weak_edges = np.zeros_like(G)

    strong_edges[G >= high] = 255
    weak_edges[(G >= low) & (G < high)] = 75

    return strong_edges, weak_edges


def edge_tracking_by_hysteresis(strong_edges, weak_edges):
    """Link weak edges to strong edges if connected."""
    M, N = strong_edges.shape
    result = np.copy(strong_edges)

    for i in range(1, M - 1):
        for j in range(1, N - 1):
            if weak_edges[i, j] == 75:
                if np.any(strong_edges[i - 1:i + 2, j - 1:j + 2] == 255):
                    result[i, j] = 255
                else:
                    result[i, j] = 0
    return result


def run_canny(img, gaussian_size=5, gaussian_sigma=1.4, low_thresh_ratio=0.05, high_thresh_ratio=0.15):
    """Run the full Canny Edge Detection algorithm."""
    blurred = convolve(img, gaussian_kernel(gaussian_size, gaussian_sigma))
    G, theta = sobel_filters(blurred)
    G_nms = non_max_suppression(G, theta)
    strong, weak = double_thresholding(G_nms, low_thresh_ratio, high_thresh_ratio)
    edges = edge_tracking_by_hysteresis(strong, weak)
    return edges


# === MAIN ===
if __name__ == "__main__":
    img = cv2.imread('test_image.jpg', cv2.IMREAD_GRAYSCALE)

    canny_img = run_canny(img,
                          gaussian_size=5,
                          gaussian_sigma=1.4,
                          low_thresh_ratio=0.05,
                          high_thresh_ratio=0.15)

    plt.imshow(canny_img, cmap='gray')
    plt.title('Canny Edge Detection')
    plt.axis('off')
    plt.show()