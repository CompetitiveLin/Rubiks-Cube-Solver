import cv2

def getposHsv_D1(event, x, y, flags, param):
    print("HSV is", HSV_D1[y, x])

def getposHsv_D2(event, x, y, flags, param):
    print("HSV is", HSV_D2[y, x])

def getposHsv_L(event, x, y, flags, param):
    print("HSV is", HSV_L[y, x])

def getposHsv_B(event, x, y, flags, param):
    print("HSV is", HSV_B[y, x])

image_D1 = cv2.imread('images/unmarked/frame_D1.jpg')
HSV_D1 = cv2.cvtColor(image_D1, cv2.COLOR_BGR2HSV)

cv2.imshow('image_D1', image_D1)
cv2.setMouseCallback("image_D1", getposHsv_D1)

image_D2 = cv2.imread('images/unmarked/frame_D2.jpg')
HSV_D2 = cv2.cvtColor(image_D2, cv2.COLOR_BGR2HSV)

cv2.imshow('image_D2', image_D2)
cv2.setMouseCallback("image_D2", getposHsv_D2)

image_L = cv2.imread('images/unmarked/frame_L.jpg')
HSV_L = cv2.cvtColor(image_L, cv2.COLOR_BGR2HSV)

cv2.imshow('image_L', image_L)
cv2.setMouseCallback("image_L", getposHsv_L)

image_B = cv2.imread('images/unmarked/frame_B.jpg')
HSV_B = cv2.cvtColor(image_B, cv2.COLOR_BGR2HSV)

cv2.imshow('image_B', image_B)
cv2.setMouseCallback("image_B", getposHsv_B)
cv2.waitKey(0)
