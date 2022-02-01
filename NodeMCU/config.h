#ifndef config_h
#define config_h

  // WiFi
  

 #define ssid     "xxxxxxxxxx"            // Add wifi name
 #define password "xxxxxxxxxx"            // Add wifi passowrd

// Initialize Telegram BOT
#define BOTtoken "aaaaaaaaaaaaa:aaaaaaaaaaaaaaa"  // replace this with your bot token 
  
String chat_id;

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
const int pump = D0;
const int NUMSENS = 4;
String sensValue[NUMSENS];
int sensPos = 0; //Posizione nell'array
String data;
String valori;
String sensors;

  // BOT time.
int bot_delay = 1000;
unsigned long lastTimeBotRan=0;
unsigned long lastTimeforTimer=0;
unsigned long timer=-1;
unsigned long exmillis =0;

  //SERIAL
SoftwareSerial input(D4, D5); // rx , tx


const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

// variables to hold the parsed data
float temp = 0.00;
float lux = 0.00;
float water = 100.00;
float soilHum = 19.00;

#endif


  //TWITTER
#define TWITTERINFO
// Values below are just a placeholder
#ifdef TWITTERINFO  // Obtain these by creating an app @ https://apps.twitter.com/
  int TwitterMaxChars = 280;
  static char const consumer_key[]    = "xxxxxxxxxxxxxx";
  static char const consumer_sec[]    = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
  static char const accesstoken[]     = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
  static char const accesstoken_sec[] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
#endif

  //THINGSBOARD
#define thingsboard_TOKEN   "xxxxxxxxxxxxxxxxxxxxxxx"
#define thingsboard_SERVER  "demo.thingsboard.io"
 
