import serial
import time 
import kociemba


def solve():
    serial_port = serial.Serial('/dev/ttyUSB0',9600)
    time.sleep(2)
    if serial_port.isOpen():
        serial_port.write("F2\n".encode())
        serial_port.close()



if __name__ == '__main__':
    solve()
