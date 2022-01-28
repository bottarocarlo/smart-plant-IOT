#ifndef config_h
#define config_h

  // WiFi
  
  /*
   * 
   * #define ssid     "Universitari"			// Add wifi name
   * #define password "UniversitarioMatto.2020$"	// Add wifi passowrd
   * 
   */
#define ssid     "iPhone di Carlo"      // Add wifi name
#define password "carletto2"            // Add wifi passowrd

// Initialize Telegram BOT
#define BOTtoken "2142355090:AAGgN6cov95TfNgBSPHevaTcp2sR6L6VxcM"	// replace this with your bot token
#define CHAT_ID "189749700"		//replace with your telegram user ID
String chat_id;

  //MODE
int mode = 0;
/*
 * starting mode MANUAL
 * 
 * 0-manual s
 * 1-automatic
 * 2-timer
 */

  //SENSOR & ATTUATOR
const int ledPin = D2;
bool ledState = LOW;
const int pump = D0;


  // BOT time.
int bot_delay = 1000;
unsigned long lastTimeBotRan=0;
unsigned long lastTimeforTimer=0;
unsigned long timer=-1;

//SERIAL

SoftwareSerial input(D4, D5); // rx , tx
boolean newData = false;

const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

// variables to hold the parsed data
float temp = 0.0;
float lux = 0.0;
float water = 0.0;
float soilHum = 0.0;




#endif
