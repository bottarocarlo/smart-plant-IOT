# Smart Plant IoT 🌱
This project was created by [@bottarocarlo](https://github.com/bottarocarlo) and [@lorenzocanciani](https://github.com/lorenzocanciani) for an assignment that we are currently completing for the project Embedded Software for the Internet of Things Unitn course 2021/2022
Having plants require to take care of them and give them water everyday. But when you have to work around the clock, you don't have the time or just can forget to water your plant. To evoid letting the plants die, I have created a system to water them automatically.

![Image of how the system looks]

## Hardware 🛠️

To build this system, we used:
- **1 [NodeMCU ESP8266]** IoT board which runs on the ESP8266 Wi-Fi SoC
- **1 [Arduino]** development board used for analog input
- **1 [Soil Humdity sensor]** 
- **1 [Brightness sensor]** photoresistor💡 
- **1 [Temperature sensor]** thermistor🌡️ 
- **1 [Water level sensor]** 🌊
- **1 [Humidity sensor]** ☁️
- **1 [3,3-5V water pump]** 💦
- **1 [5V Relè]**  
- **7 F-F Dupont cables**
- **1 micro USB cable**
- **1 USB charger**

plus:
- **1 glass jar** for the water
- **1 our little plant ina** common plant bought from Orvea

![Photo of varius object]

## Software 💻
Telegram API + Twitter + ThingsBoard

## Libraries📚
- ** ESP8266WiFi**
- ** TimeLib **
- ** UniversalTelegramBot **
- ** ArduinoJson **
- ** NTPClient **
- ** ThingsBoard **
- ** SoftwareSerial**
- 
## NodeMCU & ThingsBoard


## Circuit and wiring

![Fritzing Circuit diagram]




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

