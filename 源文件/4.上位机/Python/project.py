import cv2
capture_L = cv2.VideoCapture(2)
_,frame_L = capture_L.read()
cv2.imwrite("frame_L.jpg",frame_L)
capture_L.release()

capture_D = cv2.VideoCapture(4)
_,frame_D = capture_D.read()
frame_D = cv2.flip(frame_D,-1)
cv2.imwrite("frame_D.jpg",frame_D)
capture_D.release()

capture_R = cv2.VideoCapture(6)
_,frame_R = capture_R.read()
cv2.imwrite("frame_R.jpg",frame_R)
capture_R.release()
