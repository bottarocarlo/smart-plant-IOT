# smart-plant-IOT🪴


## sensori
### ambiente
🌡️Temperature (thermistor) ---- libreria dedicata <br /> 
💡Brightness (photoresistor) ---- libreria dedicata<br />

### terreno
☁️Soil moisture ---- libreria generale

### service 🛠️
🌊 Water level ---- libreria generale

## attuatori
💦Water Pump


Telegram API + Twitter + Web Server



Led errori


![Alt text](circuito.jpg?raw=true "Title")




### GPIO INFO --> D0 to D8
GPIO0: It oscillates and stabilizes HIGH after ~100ms. Boot Failure if pulled LOW <br />
GPIO1: LOW for ~50ms, then HIGH, Boot Failure if Pulled LOW. <br />
GPIO2: It oscillates and stabilize HIGH after ~100ms, Boot Failure if Pulled LOW. <br />
GPIO3: LOW for ~50ms, then HIGH. <br />
GPIO9: Pin is HIGH at Boot. <br />
GPIO10: Pin is HIGH at Boot. <br />
GPIO15: LOW, Boot failure if Pulled HIGH <br/>
GPIO16: HIGH during Boot and Falls to ~1Volt. <br/>

## Linux
to run on usb port run firstly <br/>
sudo chmod a+rw /dev/ttyUSB0 <br/>
don know why

