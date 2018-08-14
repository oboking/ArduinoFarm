import MySQLdb
import serial
import time
import datetime
from datetime import timedelta

ser = serial.Serial('/dev/ttyACM0', 9600)
db = MySQLdb.connect("localhost", "admin", "password", "SensorData")
cursor = db.cursor()

open('/home/pi/script_runs', 'w+')

while 1:
	print("Waiting for data...")
	print("")
	lux = ser.readline()
	print("Collecting data...")
	print("")
	time.sleep(1)
	lux = float(lux)
	temp = float(ser.readline())
	time.sleep(1)
	hum = float(ser.readline())
	time.sleep(1)

	print("Sending data to DB...")
	print("")
	time.sleep(1)
	now = datetime.datetime.now() + timedelta(hours=2)
	dateAsList = ["%02d" % now.year,"%02d" % now.month,"%02d" % now.day,"%02d" % now.hour,"%02d" % now.minute,"%02d" % now.second]
	date = int(''.join(map(str,dateAsList)))
	print(date)
	sql =  "INSERT INTO ArduinoData(date, temperature, humidity, waterlevel, light) VALUES (%d,%d,%d,%d,%d)" %(date,temp,hum,10.0,lux)
	cursor.execute(sql)
	db.commit()
	
