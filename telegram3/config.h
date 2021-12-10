#ifndef config_h
#define config_h

  // WiFi
#define ssid     "Universitari"			// Add wifi name
#define password "UniversitarioMatto.2020$"	// Add wifi passowrd

// Initialize Telegram BOT
#define BOTtoken "2142355090:AAGgN6cov95TfNgBSPHevaTcp2sR6L6VxcM"	// replace this with your bot token
#define CHAT_ID "189749700"		//replace with your telegram user ID

  //MODE
int mode = 0;
/*
*0-manual 
*1-automatic
*2-timer
*/

  //SENSOR & ATTUATOR
const int ledPin = D2;
bool ledState = LOW;
const int pump = LED_BUILTIN;
const int NUMSENS = 4;
String sensValue[NUMSENS];
/*
 * sensValue[0]==Thermoresistor
 * sensValue[1]==Photoresistor
 * sensValue[2]==Waterlevel
 * sensValue[3]==SoilHumidity
 */
int sensPos = 0; //Posizione nell'array
String data;
String valori;

  // BOT time.
int bot_delay = 1000;
unsigned long lastTimeBotRan;





#endif
