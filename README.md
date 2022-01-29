#TODO
Pulire coda messaggi bot al primo avvio?
Pulire input.serial prima della lettura dei dati?


# smart-plant-IOT🪴
This project was created for an assignment that we are currently completing for the project Embedded Software for the Internet of Things Unitn course 2021/2022
Having plants require to take care of them and give them water everyday. But when you have to work around the clock, you don't have the time or just can forget to water your plant. To evoid letting the plants die, I have created a system to water them automatically.

## sensors
### ambiente
🌡️ Temperature (thermistor) A0 <br /> 
💡 Brightness (photoresistor) A1 <br />

### terreno
☁️ Soil moisture A3

### service 🛠️
🌊 Water level 

## attuator
💦Water Pump


Telegram API + Twitter + ThingsBoard



![Alt text](img/circuito.jpg?raw=true "Title")




### GPIO INFO --> D0 to D8
GPIO0: It oscillates and stabilizes HIGH after ~100ms. Boot Failure if pulled LOW <br />
GPIO1: LOW for ~50ms, then HIGH, Boot Failure if Pulled LOW. <br />
GPIO2: It oscillates and stabilize HIGH after ~100ms, Boot Failure if Pulled LOW. <br />
GPIO3: LOW for ~50ms, then HIGH. <br />
GPIO9: Pin is HIGH at Boot. <br />
GPIO10: Pin is HIGH at Boot. <br />
GPIO15: LOW, Boot failure if Pulled HIGH <br/>
GPIO16: HIGH during Boot and Falls to ~1Volt. <br/>

GPIO2 (D4 pin) if connected make the flash fail

## Linux
to run on usb port run firstly <br/>
sudo chmod a+rw /dev/ttyUSB0 <br/>
don know why <br/>
add to preferences: https://arduino.esp8266.com/stable/package_esp8266com_index.json <br/>
add board libreries ESP8266 <br/>
add file .zip https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot <br/>
install from library manager arduinoJson, and select your board from tool > board <br/>


https://github.com/amcewen/HttpClient/releases <br/>

