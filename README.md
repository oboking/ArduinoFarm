# Arduino garden
The monitoring system I use for my mini hydroponic garden.
As of now, the system uses **temperature**, **humidity**, **light**, and **water level** sensors, however more sensors like pH could easily be added.

![alt text](https://i.imgur.com/H1nqutQ.png)

The raw values are read from the sensors connected to the Arduino. It is connected to a Raspberry PI which constantly reads values over a usb bus to the Arduino. 

The reason for a PI is that we can use it as a server for a database, but also it has public network access and can post to our database if it's not located on the PI. One could use a WIFI-shield on the arduino and not use the PI at all. 

The PI posts the values it reads over the usb cable to the server via a python script which runs at all times.

![alt text](https://i.imgur.com/1xJGT5v.png)