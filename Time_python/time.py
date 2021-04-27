import time 
curr_time = time.localtime() 
curr_clock = time.strftime("%H:%M:%S", curr_time) 
print(curr_clock) 

  
import serial
with serial.Serial('COM4', 9600) as ser:
	x = ser.readline()
	print(x)
	ser.write(curr_clock.encode())
	y = ser.readline()
	print(y)
	
	ser.close()