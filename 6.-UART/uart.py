from time import sleep
import serial

ser = serial.Serial("COM6", 19200, timeout=1)
value = 1

while( 1 ):
    SerialRead = ser.read( 1 )
    print(SerialRead)
    sleep(0.1)
    InputData = str(value)
    dataToSend = InputData.encode()
    ser.write(dataToSend)
    if value == 1:
        value -= 1
    else:
        value += 1   
    sleep(1)
