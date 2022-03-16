import serial
import time
import cv2
import numpy as np


def communicate(data):  # DATA IS NOT SUPPOSED TO END WITH \N
    try:    
        serial_port = serial.Serial('/dev/ttyUSB0', 9600)
        time.sleep(2)
        if serial_port.isOpen():
            data += '\n'
            serial_port.write(data.encode())
            serial_port.close()
        return True
    except:
        print("Something wrong with the serial_port! Please check your device!")
        return False

        
def catch_frames():
    capture_L = cv2.VideoCapture(2)
    _, frame_L = capture_L.read()
    cv2.imwrite("images/unmarked/frame_L.jpg", frame_L)
    print("Done writing frame_L.jpg")
    capture_L.release()

    capture_D = cv2.VideoCapture(4)
    _, frame_D = capture_D.read()
    frame_D = cv2.flip(frame_D, -1)
    cv2.imwrite("images/unmarked/frame_D1.jpg", frame_D)
    print("Done writing frame_D1.jpg")
    capture_D.release()
    communicate('D2')

    capture_D = cv2.VideoCapture(4)
    _, frame_D2 = capture_D.read()
    frame_D2 = cv2.flip(frame_D2, -1)
    cv2.imwrite("images/unmarked/frame_D2.jpg", frame_D2)
    print("Done writing frame_D2.jpg")
    capture_D.release()
    communicate('D2')
    
    capture_B = cv2.VideoCapture(6)
    _, frame_B = capture_B.read()
    cv2.imwrite("images/unmarked/frame_B.jpg", frame_B)
    print("Done writing frame_B.jpg")
    capture_B.release()


def cal_hsv(temp_point_list, temp_HSV):
    temp = []
    for i in range(temp_point_list[0][0], temp_point_list[1][0] + 1):
        for j in range(temp_point_list[0][1], temp_point_list[1][1] + 1):
            if temp_HSV[j, i][1] > 200 and temp_HSV[j, i][0] > 125:
                temp_HSV[j, i][0] = 0
            temp.append(temp_HSV[j, i])
    return list(np.mean(temp, axis=0))


def check_hsv(temp_point_list, temp_HSV):
    for i in range(temp_point_list[0][0], temp_point_list[1][0] + 1):
        for j in range(temp_point_list[0][1], temp_point_list[1][1] + 1):
            print(temp_HSV[j, i])


def mark_img(image_D1, image_D2, image_L, image_B):
    d1 = cv2.rectangle(image_D1, (235, 345), (250, 360), (0, 255, 0), 2)

    d9 = cv2.rectangle(image_D1, (415, 345), (430, 360), (0, 255, 0), 2)

    cv2.rectangle(image_L, (445, 240), (480, 265), (0, 255, 0), 2)
    f1 = np.array([[445, 240], [480, 230], [480, 265], [445, 280]], np.int32)
    f1 = f1.reshape((-1, 1, 2))
    cv2.polylines(image_L, [f1], True, (0, 0, 255))

    cv2.rectangle(image_D1, (245, 130), (270, 145), (0, 255, 0), 2)
    f2 = np.array([[245, 130], [270, 115], [270, 145], [250, 160]], np.int32)
    f2 = f2.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [f2], True, (0, 0, 255))

    cv2.rectangle(image_D1, (285, 95), (325, 110), (0, 255, 0), 2)
    f3 = np.array([[285, 95], [325, 70], [325, 110], [285, 135]], np.int32)
    f3 = f3.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [f3], True, (0, 0, 255))

    cv2.rectangle(image_D1, (185, 225), (205, 255), (0, 255, 0), 2)
    f4 = np.array([[185, 225], [205, 225], [205, 255], [185, 265]], np.int32)
    f4 = f4.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [f4], True, (0, 0, 255))

    cv2.rectangle(image_D1, (285, 165), (325, 180), (0, 255, 0), 2)
    f6 = np.array([[285, 165], [325, 140], [325, 180], [285, 205]], np.int32)
    f6 = f6.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [f6], True, (0, 0, 255))

    cv2.rectangle(image_D1, (180, 290), (205, 310), (0, 255, 0), 2)
    f7 = np.array([[180, 290], [205, 275], [205, 310], [180, 325]], np.int32)
    f7 = f7.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [f7], True, (0, 0, 255))

    cv2.rectangle(image_D1, (225, 265), (260, 285), (0, 255, 0), 2)
    f8 = np.array([[225, 265], [260, 245], [260, 285], [225, 305]], np.int32)
    f8 = f8.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [f8], True, (0, 0, 255))

    cv2.rectangle(image_D1, (285, 230), (325, 245), (0, 255, 0), 2)
    f9 = np.array([[285, 230], [325, 205], [325, 245], [285, 270]], np.int32)
    f9 = f9.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [f9], True, (0, 0, 255))

    cv2.rectangle(image_D1, (260, 315), (295, 330), (0, 255, 0), 2)
    d2 = np.array([[275, 305], [310, 325], [280, 340], [240, 325]], np.int32)
    d2 = d2.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [d2], True, (0, 0, 255))

    cv2.rectangle(image_D1, (320, 285), (350, 307), (0, 255, 0), 2)
    d3 = np.array([[335, 275], [370, 295], [335, 315], [295, 295]], np.int32)
    d3 = d3.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [d3], True, (0, 0, 255))

    cv2.rectangle(image_D2, (375, 315), (415, 330), (0, 255, 0), 2)
    d4 = np.array([[390, 305], [430, 325], [400, 340], [365, 320]], np.int32)
    d4 = d4.reshape((-1, 1, 2))
    cv2.polylines(image_D2, [d4], True, (0, 0, 255))

    cv2.rectangle(image_D1, (375, 315), (415, 330), (0, 255, 0), 2)
    d6 = np.array([[390, 305], [430, 325], [400, 340], [365, 320]], np.int32)
    d6 = d6.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [d6], True, (0, 0, 255))

    cv2.rectangle(image_D2, (320, 285), (350, 307), (0, 255, 0), 2)
    d7 = np.array([[335, 275], [370, 295], [335, 315], [295, 295]], np.int32)
    d7 = d7.reshape((-1, 1, 2))
    cv2.polylines(image_D2, [d7], True, (0, 0, 255))

    cv2.rectangle(image_D2, (260, 315), (295, 330), (0, 255, 0), 2)
    d8 = np.array([[275, 305], [310, 325], [280, 340], [240, 325]], np.int32)
    d8 = d8.reshape((-1, 1, 2))
    cv2.polylines(image_D2, [d8], True, (0, 0, 255))

    cv2.rectangle(image_L, (280, 170), (310, 185), (0, 255, 0), 2)
    l1 = np.array([[280, 145], [310, 170], [310, 210], [280, 185]], np.int32)
    l1 = l1.reshape((-1, 1, 2))
    cv2.polylines(image_L, [l1], True, (0, 0, 255))

    cv2.rectangle(image_L, (330, 200), (365, 215), (0, 255, 0), 2)
    l2 = np.array([[330, 175], [365, 200], [365, 240], [330, 215]], np.int32)
    l2 = l2.reshape((-1, 1, 2))
    cv2.polylines(image_L, [l2], True, (0, 0, 255))

    cv2.rectangle(image_L, (385, 240), (420, 255), (0, 255, 0), 2)
    l3 = np.array([[385, 215], [420, 240], [420, 280], [385, 255]], np.int32)
    l3 = l3.reshape((-1, 1, 2))
    cv2.polylines(image_L, [l3], True, (0, 0, 255))

    cv2.rectangle(image_L, (280, 230), (305, 250), (0, 255, 0), 2)
    l4 = np.array([[280, 210], [305, 230], [305, 250], [280, 230]], np.int32)
    l4 = l4.reshape((-1, 1, 2))
    cv2.polylines(image_L, [l4], True, (0, 0, 255))

    cv2.rectangle(image_L, (380, 315), (415, 325), (0, 255, 0), 2)
    l6 = np.array([[380, 290], [415, 315], [415, 350], [380, 325]], np.int32)
    l6 = l6.reshape((-1, 1, 2))
    cv2.polylines(image_L, [l6], True, (0, 0, 255))

    cv2.rectangle(image_D2, (345, 230), (380, 245), (0, 255, 0), 2)
    l7 = np.array([[345, 205], [380, 230], [380, 270], [345, 245]], np.int32)
    l7 = l7.reshape((-1, 1, 2))
    cv2.polylines(image_D2, [l7], True, (0, 0, 255))

    cv2.rectangle(image_L, (335, 340), (360, 355), (0, 255, 0), 2)
    l8 = np.array([[335, 330], [360, 340], [360, 375], [335, 355]], np.int32)
    l8 = l8.reshape((-1, 1, 2))
    cv2.polylines(image_L, [l8], True, (0, 0, 255))

    cv2.rectangle(image_L, (375, 372), (410, 387), (0, 255, 0), 2)
    l9 = np.array([[375, 355], [410, 380], [410, 410], [375, 385]], np.int32)
    l9 = l9.reshape((-1, 1, 2))
    cv2.polylines(image_L, [l9], True, (0, 0, 255))

    cv2.rectangle(image_L, (305, 125), (350, 135), (0, 255, 0), 2)
    u1 = np.array([[295, 130], [330, 115], [360, 135], [320, 145]], np.int32)
    u1 = u1.reshape((-1, 1, 2))
    cv2.polylines(image_L, [u1], True, (0, 0, 255))

    cv2.rectangle(image_B, (435, 160), (475, 175), (0, 255, 0), 2)
    u2 = np.array([[455, 155], [485, 165], [455, 180], [425, 170]], np.int32)
    u2 = u2.reshape((-1, 1, 2))
    cv2.polylines(image_B, [u2], True, (0, 0, 255))

    cv2.rectangle(image_B, (375, 185), (415, 200), (0, 255, 0), 2)
    u3 = np.array([[360, 190], [395, 175], [430, 195], [390, 210]], np.int32)
    u3 = u3.reshape((-1, 1, 2))
    cv2.polylines(image_B, [u3], True, (0, 0, 255))

    cv2.rectangle(image_L, (355, 155), (395, 170), (0, 255, 0), 2)
    u4 = np.array([[340, 160], [375, 145], [405, 165], [375, 180]], np.int32)
    u4 = u4.reshape((-1, 1, 2))
    cv2.polylines(image_L, [u4], True, (0, 0, 255))

    cv2.rectangle(image_B, (310, 155), (355, 170), (0, 255, 0), 2)
    u6 = np.array([[300, 160], [340, 150], [365, 165], [330, 180]], np.int32)
    u6 = u6.reshape((-1, 1, 2))
    cv2.polylines(image_B, [u6], True, (0, 0, 255))

    cv2.rectangle(image_L, (410, 185), (460, 205), (0, 255, 0), 2)
    u7 = np.array([[395, 190], [430, 180], [470, 200], [430, 215]], np.int32)
    u7 = u7.reshape((-1, 1, 2))
    cv2.polylines(image_L, [u7], True, (0, 0, 255))

    cv2.rectangle(image_L, (475, 160), (520, 175), (0, 255, 0), 2)
    u8 = np.array([[465, 165], [500, 150], [530, 170], [495, 190]], np.int32)
    u8 = u8.reshape((-1, 1, 2))
    cv2.polylines(image_L, [u8], True, (0, 0, 255))

    cv2.rectangle(image_L, (530, 137), (570, 152), (0, 255, 0), 2)
    u9 = np.array([[515, 140], [545, 130], [580, 150], [550, 160]], np.int32)
    u9 = u9.reshape((-1, 1, 2))
    cv2.polylines(image_L, [u9], True, (0, 0, 255))

    cv2.rectangle(image_B, (245, 170), (270, 195), (0, 255, 0), 2)
    r1 = np.array([[245, 155], [270, 170], [270, 210], [245, 195]], np.int32)
    r1 = r1.reshape((-1, 1, 2))
    cv2.polylines(image_B, [r1], True, (0, 0, 255))

    cv2.rectangle(image_B, (290, 195), (320, 220), (0, 255, 0), 2)
    r2 = np.array([[290, 180], [320, 195], [320, 235], [290, 220]], np.int32)
    r2 = r2.reshape((-1, 1, 2))
    cv2.polylines(image_B, [r2], True, (0, 0, 255))

    cv2.rectangle(image_B, (345, 225), (375, 255), (0, 255, 0), 2)
    r3 = np.array([[345, 210], [375, 225], [375, 270], [345, 255]], np.int32)
    r3 = r3.reshape((-1, 1, 2))
    cv2.polylines(image_B, [r3], True, (0, 0, 255))

    cv2.rectangle(image_D1, (345, 165), (380, 185), (0, 255, 0), 2)
    r4 = np.array([[345, 140], [380, 165], [380, 205], [345, 185]], np.int32)
    r4 = r4.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [r4], True, (0, 0, 255))

    cv2.rectangle(image_B, (345, 300), (375, 325), (0, 255, 0), 2)
    r6 = np.array([[345, 280], [375, 300], [375, 345], [345, 325]], np.int32)
    r6 = r6.reshape((-1, 1, 2))
    cv2.polylines(image_B, [r6], True, (0, 0, 255))

    cv2.rectangle(image_D1, (345, 230), (380, 245), (0, 255, 0), 2)
    r7 = np.array([[345, 205], [380, 230], [380, 270], [345, 245]], np.int32)
    r7 = r7.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [r7], True, (0, 0, 255))

    cv2.rectangle(image_D1, (405, 270), (435, 280), (0, 255, 0), 2)
    r8 = np.array([[405, 250], [435, 270], [435, 300], [405, 280]], np.int32)
    r8 = r8.reshape((-1, 1, 2))
    cv2.polylines(image_D1, [r8], True, (0, 0, 255))

    cv2.rectangle(image_B, (345, 365), (375, 385), (0, 255, 0), 2)
    r9 = np.array([[345, 345], [375, 365], [375, 405], [345, 385]], np.int32)
    r9 = r9.reshape((-1, 1, 2))
    cv2.polylines(image_B, [r9], True, (0, 0, 255))

    cv2.rectangle(image_B, (400, 235), (440, 260), (0, 255, 0), 2)
    b1 = np.array([[400, 235], [440, 215], [440, 260], [400, 280]], np.int32)
    b1 = b1.reshape((-1, 1, 2))
    cv2.polylines(image_B, [b1], True, (0, 0, 255))

    cv2.rectangle(image_B, (465, 205), (495, 225), (0, 255, 0), 2)
    b2 = np.array([[465, 205], [500, 185], [495, 225], [460, 245]], np.int32)
    b2 = b2.reshape((-1, 1, 2))
    cv2.polylines(image_B, [b2], True, (0, 0, 255))

    cv2.rectangle(image_B, (520, 175), (540, 210), (0, 255, 0), 2)
    b3 = np.array([[520, 175], [550, 165], [540, 210], [510, 220]], np.int32)
    b3 = b3.reshape((-1, 1, 2))
    cv2.polylines(image_B, [b3], True, (0, 0, 255))

    cv2.rectangle(image_B, (400, 305), (435, 325), (0, 255, 0), 2)
    b4 = np.array([[400, 305], [440, 285], [435, 325], [395, 345]], np.int32)
    b4 = b4.reshape((-1, 1, 2))
    cv2.polylines(image_B, [b4], True, (0, 0, 255))

    cv2.rectangle(image_B, (515, 240), (535, 260), (0, 255, 0), 2)
    b6 = np.array([[515, 240], [535, 230], [535, 260], [515, 260]], np.int32)
    b6 = b6.reshape((-1, 1, 2))
    cv2.polylines(image_B, [b6], True, (0, 0, 255))

    cv2.rectangle(image_B, (400, 370), (430, 390), (0, 255, 0), 2)
    b7 = np.array([[400, 370], [430, 355], [430, 390], [400, 405]], np.int32)
    b7 = b7.reshape((-1, 1, 2))
    cv2.polylines(image_B, [b7], True, (0, 0, 255))

    cv2.rectangle(image_B, (450, 345), (475, 360), (0, 255, 0), 2)
    b8 = np.array([[450, 345], [475, 335], [475, 360], [450, 370]], np.int32)
    b8 = b8.reshape((-1, 1, 2))
    cv2.polylines(image_B, [b8], True, (0, 0, 255))

    cv2.rectangle(image_D2, (285, 230), (325, 245), (0, 255, 0), 2)
    b9 = np.array([[285, 230], [325, 205], [325, 245], [285, 270]], np.int32)
    b9 = b9.reshape((-1, 1, 2))
    cv2.polylines(image_D2, [b9], True, (0, 0, 255))

    return image_D1, image_D2, image_L, image_B


hsv_dic = {}


def detect():

    image_D1 = cv2.imread('images/unmarked/frame_D1.jpg')
    HSV_D1 = cv2.cvtColor(image_D1, cv2.COLOR_BGR2HSV)
    image_D2 = cv2.imread('images/unmarked/frame_D2.jpg')
    HSV_D2 = cv2.cvtColor(image_D2, cv2.COLOR_BGR2HSV)
    image_L = cv2.imread('images/unmarked/frame_L.jpg')
    HSV_L = cv2.cvtColor(image_L, cv2.COLOR_BGR2HSV)
    image_B = cv2.imread('images/unmarked/frame_B.jpg')
    HSV_B = cv2.cvtColor(image_B, cv2.COLOR_BGR2HSV)

    point_list = [[445, 240], [480, 265]]
    hsv_dic["f1"] = cal_hsv(point_list, HSV_L)

    point_list = [[245, 130], [270, 145]]
    hsv_dic["f2"] = cal_hsv(point_list, HSV_D1)

    point_list = [[285, 95], [325, 110]]
    hsv_dic["f3"] = cal_hsv(point_list, HSV_D1)

    point_list = [[185, 225], [205, 255]]
    hsv_dic["f4"] = cal_hsv(point_list, HSV_D1)

    point_list = [[285, 165], [325, 180]]
    hsv_dic["f6"] = cal_hsv(point_list, HSV_D1)

    point_list = [[180, 290], [205, 310]]
    hsv_dic["f7"] = cal_hsv(point_list, HSV_D1)
    # check_hsv(point_list, HSV_D1)
    point_list = [[225, 265], [260, 285]]
    hsv_dic["f8"] = cal_hsv(point_list, HSV_D1)

    point_list = [[285, 230], [325, 245]]
    hsv_dic["f9"] = cal_hsv(point_list, HSV_D1)

    #############################################

    point_list = [[280, 170], [310, 185]]
    hsv_dic["l1"] = cal_hsv(point_list, HSV_L)

    point_list = [[330, 200], [365, 215]]
    hsv_dic["l2"] = cal_hsv(point_list, HSV_L)

    point_list = [[385, 240], [420, 255]]
    hsv_dic["l3"] = cal_hsv(point_list, HSV_L)

    point_list = [[280, 230], [305, 250]]
    hsv_dic["l4"] = cal_hsv(point_list, HSV_L)

    point_list = [[380, 315], [415, 325]]
    hsv_dic["l6"] = cal_hsv(point_list, HSV_L)

    point_list = [[345, 230], [380, 245]]
    hsv_dic["l7"] = cal_hsv(point_list, HSV_D2)

    point_list = [[335, 340], [360, 355]]
    hsv_dic["l8"] = cal_hsv(point_list, HSV_L)

    point_list = [[375, 372], [410, 387]]
    hsv_dic["l9"] = cal_hsv(point_list, HSV_L)

    #############################################

    point_list = [[245, 170], [270, 195]]
    hsv_dic["r1"] = cal_hsv(point_list, HSV_B)

    point_list = [[290, 195], [320, 220]]
    hsv_dic["r2"] = cal_hsv(point_list, HSV_B)

    point_list = [[345, 225], [375, 255]]
    hsv_dic["r3"] = cal_hsv(point_list, HSV_B)

    point_list = [[345, 165], [380, 185]]
    hsv_dic["r4"] = cal_hsv(point_list, HSV_D1)

    point_list = [[345, 300], [375, 325]]
    hsv_dic["r6"] = cal_hsv(point_list, HSV_B)

    point_list = [[345, 230], [380, 245]]
    hsv_dic["r7"] = cal_hsv(point_list, HSV_D1)

    point_list = [[405, 270], [435, 280]]
    hsv_dic["r8"] = cal_hsv(point_list, HSV_D1)

    point_list = [[345, 365], [375, 385]]
    hsv_dic["r9"] = cal_hsv(point_list, HSV_B)

    #############################################

    point_list = [[235, 345], [250, 360]]
    hsv_dic["d1"] = cal_hsv(point_list, HSV_D1)

    point_list = [[260, 315], [295, 330]]
    hsv_dic["d2"] = cal_hsv(point_list, HSV_D1)

    point_list = [[320, 285], [350, 307]]
    hsv_dic["d3"] = cal_hsv(point_list, HSV_D1)

    point_list = [[375, 315], [415, 330]]
    hsv_dic["d4"] = cal_hsv(point_list, HSV_D2)

    point_list = [[375, 315], [415, 330]]
    hsv_dic["d6"] = cal_hsv(point_list, HSV_D1)

    point_list = [[320, 285], [350, 307]]
    hsv_dic["d7"] = cal_hsv(point_list, HSV_D2)

    point_list = [[260, 315], [295, 330]]
    hsv_dic["d8"] = cal_hsv(point_list, HSV_D2)

    point_list = [[415, 345], [430, 360]]
    hsv_dic["d9"] = cal_hsv(point_list, HSV_D1)
    # check_hsv(point_list, HSV_D1)
    ##############################################

    point_list = [[305, 125], [350, 135]]
    hsv_dic["u1"] = cal_hsv(point_list, HSV_L)

    point_list = [[435, 160], [475, 175]]
    hsv_dic["u2"] = cal_hsv(point_list, HSV_B)

    point_list = [[375, 185], [415, 200]]
    hsv_dic["u3"] = cal_hsv(point_list, HSV_B)

    point_list = [[355, 155], [395, 170]]
    hsv_dic["u4"] = cal_hsv(point_list, HSV_L)

    point_list = [[310, 155], [355, 170]]
    hsv_dic["u6"] = cal_hsv(point_list, HSV_B)

    point_list = [[410, 185], [460, 205]]
    hsv_dic["u7"] = cal_hsv(point_list, HSV_L)

    point_list = [[475, 160], [520, 175]]
    hsv_dic["u8"] = cal_hsv(point_list, HSV_L)

    point_list = [[530, 137], [570, 152]]
    hsv_dic["u9"] = cal_hsv(point_list, HSV_L)

    ############################################

    point_list = [[400, 235], [440, 260]]
    hsv_dic["b1"] = cal_hsv(point_list, HSV_B)

    point_list = [[465, 205], [495, 225]]
    hsv_dic["b2"] = cal_hsv(point_list, HSV_B)

    point_list = [[520, 175], [540, 210]]
    hsv_dic["b3"] = cal_hsv(point_list, HSV_B)
    # check_hsv(point_list, HSV_B)
    point_list = [[400, 305], [435, 325]]
    hsv_dic["b4"] = cal_hsv(point_list, HSV_B)

    point_list = [[515, 240], [535, 260]]
    hsv_dic["b6"] = cal_hsv(point_list, HSV_B)

    point_list = [[400, 370], [430, 390]]
    hsv_dic["b7"] = cal_hsv(point_list, HSV_B)

    point_list = [[450, 345], [475, 360]]
    hsv_dic["b8"] = cal_hsv(point_list, HSV_B)

    point_list = [[285, 230], [325, 245]]
    hsv_dic["b9"] = cal_hsv(point_list, HSV_D2)

    # print_hsv()

    image_D1, image_D2, image_L, image_B = mark_img(image_D1, image_D2, image_L, image_B)

    cv2.imwrite('images/marked/image_D1.jpg', image_D1)
    cv2.imwrite('images/marked/image_D2.jpg', image_D2)
    cv2.imwrite('images/marked/image_L.jpg', image_L)
    cv2.imwrite('images/marked/image_B.jpg', image_B)

    return hsv_dic


def print_hsv():
    print("f1-HSV:", hsv_dic["f1"])
    print("f2-HSV:", hsv_dic["f2"])
    print("f3-HSV:", hsv_dic["f3"])
    print("f4-HSV:", hsv_dic["f4"])
    print("f6-HSV:", hsv_dic["f6"])
    print("f7-HSV:", hsv_dic["f7"])
    print("f8-HSV:", hsv_dic["f8"])
    print("f9-HSV:", hsv_dic["f9"])
    print("l1-HSV:", hsv_dic["l1"])
    print("l2-HSV:", hsv_dic["l2"])
    print("l3-HSV:", hsv_dic["l3"])
    print("l4-HSV:", hsv_dic["l4"])
    print("l6-HSV:", hsv_dic["l6"])
    print("l7-HSV:", hsv_dic["l7"])
    print("l8-HSV:", hsv_dic["l8"])
    print("l9-HSV:", hsv_dic["l9"])
    print("r1-HSV:", hsv_dic["r1"])
    print("r2-HSV:", hsv_dic["r2"])
    print("r3-HSV:", hsv_dic["r3"])
    print("r4-HSV:", hsv_dic["r4"])
    print("r6-HSV:", hsv_dic["r6"])
    print("r7-HSV:", hsv_dic["r7"])
    print("r8-HSV:", hsv_dic["r8"])
    print("r9-HSV:", hsv_dic["r9"])
    print("d1-HSV:", hsv_dic["d1"])
    print("d2-HSV:", hsv_dic["d2"])
    print("d3-HSV:", hsv_dic["d3"])
    print("d4-HSV:", hsv_dic["d4"])
    print("d6-HSV:", hsv_dic["d6"])
    print("d7-HSV:", hsv_dic["d7"])
    print("d8-HSV:", hsv_dic["d8"])
    print("d9-HSV:", hsv_dic["d9"])
    print("u1-HSV:", hsv_dic["u1"])
    print("u2-HSV:", hsv_dic["u2"])
    print("u3-HSV:", hsv_dic["u3"])
    print("u4-HSV:", hsv_dic["u4"])
    print("u6-HSV:", hsv_dic["u6"])
    print("u7-HSV:", hsv_dic["u7"])
    print("u8-HSV:", hsv_dic["u8"])
    print("u9-HSV:", hsv_dic["u9"])
    print("b1-HSV:", hsv_dic["b1"])
    print("b2-HSV:", hsv_dic["b2"])
    print("b3-HSV:", hsv_dic["b3"])
    print("b4-HSV:", hsv_dic["b4"])
    print("b6-HSV:", hsv_dic["b6"])
    print("b7-HSV:", hsv_dic["b7"])
    print("b8-HSV:", hsv_dic["b8"])
    print("b9-HSV:", hsv_dic["b9"])


if __name__ == '__main__':
    if communicate(""):
        catch_frames()
        detect()
    else:
        detect()
