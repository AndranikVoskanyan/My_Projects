This rep is opened for image processing project "document scanner"
Owner manual:
1 run  gui.py :
        python gui.py 
2 press start to run camera 
3 press capture to capture image 
4 press scan for running haugh algorithm and document scanning 
if you want extra sharpeness in picture just enable sharpen filter checkbox
if you already have pretaken picture press import file and import your picture 
if you don't like algorithm result you can adjust threshold scan again (time consuming) or adjust result sizes by using adjust_x/y_from_left_right boxes:
        positive value adding value beyond detected corners 
        negative value craping more 
        name identical to cutting or adjusting side 
if you wnat to retake picture press reset 
if you want to finish programm press stop 


GUI elements and meanings

Start - runing device camera 
0/1 - choosing camera 0 is default camera 1 external (can be phone if user have necessarry application )
Capture - Taking picture for future use 
Scan - running scanning algorithm
Sharpen filter checkbox - adding extra sharpness to picture
adjust_x/y_from_left_right -   positive value adding value beyond detected corners,  negative value craping more  , name identical to cutting or adjusting side 
Crap -  extra changes after algorithm output result if needed
threshold ratio  - strenth of orthogonal line to be taken into account
Save - save last output result
Reset - reset camera (after captured image or if you want to change camera)
Stop -  close program (not working during process)
Import file - import pretaken image for future scaning 