import serial
import time 
# import kociemba
import cv2

def communicate(data): # DATA IS NOT SUPOOSED TO END WITH \N
    try:    
        serial_port = serial.Serial('/dev/ttyUSB0',9600)
        time.sleep(2)
        if serial_port.isOpen():
            data += '\n'
            serial_port.write(data.encode())
            serial_port.close()
    except:
        print("Something wrong with the serial_port! Please check your device!")

        
def catch_frames():
    capture_L = cv2.VideoCapture(2)
    _,frame_L = capture_L.read()
    cv2.imwrite("frame_L.jpg",frame_L)
    print("Done writing frame_L.jpg")
    capture_L.release()

    capture_D = cv2.VideoCapture(4)
    _,frame_D = capture_D.read()
    frame_D = cv2.flip(frame_D,-1)
    cv2.imwrite("frame_D1.jpg",frame_D)
    print("Done writing frame_D1.jpg")
    capture_D.release()
    communicate('D2')

    capture_D = cv2.VideoCapture(4)
    _,frame_D2 = capture_D.read()
    frame_D2 = cv2.flip(frame_D2,-1)
    cv2.imwrite("frame_D2.jpg",frame_D2)
    print("Done writing frame_D2.jpg")
    capture_D.release()
    communicate('D2')
    
    capture_R = cv2.VideoCapture(6)
    _,frame_R = capture_R.read()
    cv2.imwrite("frame_R.jpg",frame_R)
    print("Done writing frame_R.jpg")
    capture_R.release()


if __name__ == '__main__':
    catch_frames()
