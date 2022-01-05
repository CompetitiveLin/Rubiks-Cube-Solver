import serial
import time 
# import kociemba


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

        



if __name__ == '__main__':
    test_data = "F B L R U D D' U' R' L' B' F'"
    communicate(test_data)
