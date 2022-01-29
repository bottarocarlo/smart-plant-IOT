#ifndef config_h
#define config_h

  // WiFi
  
  /*
   * #define ssid     "Universitari"			// Add wifi name
   * #define password "UniversitarioMatto.2020$"	// Add wifi passowrd
   * 
   * #define ssid     "iPhone di Lorenzo"      // Add wifi name
   * #define password "lorenzo123456789"            // Add wifi passowrd
   */


#define ssid     "LORENZOPC"      // Add wifi name
#define password "12345678"            // Add wifi passowrd

  // Initialize Telegram BOT
#define BOTtoken "5044399842:AAHpXZ7vP6ehEIfekzb5lEpmMKgkpkhzxqM"  // replace this with your bot token casadolcecasa
//#define BOTtoken "2142355090:AAGgN6cov95TfNgBSPHevaTcp2sR6L6VxcM"	// replace this with your bot token BOOTARLO
//#define CHAT_ID "250893524"		//replace with your telegram user ID
#define CHAT_ID "1244599727"    //replace with your telegram user ID //BAZZ
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
float water = 0.00;
float soilHum = 0.00;

#endif


  //TWITTER
#define TWITTERINFO
// Values below are just a placeholder
#ifdef TWITTERINFO  // Obtain these by creating an app @ https://apps.twitter.com/
  int TwitterMaxChars = 280;
  static char const consumer_key[]    = "3rJR6Kt1n5MvalIVDBhwvoqDy";
  static char const consumer_sec[]    = "Zr0vD8wZvdRApTB2DeZXQ0VmRWg471lTABEqw4PxEy6LNiZvan";
  static char const accesstoken[]     = "1204390758117183488-KGcFWM1VrIZwINLb4qfpkQNmXFXSXC";
  static char const accesstoken_sec[] = "0oZ0NAOODbBbk7TfBWzhMW3NrNlbc90A5uL2mCPzYEO13";
#endif

  //THINGSBOARD
#define thingsboard_TOKEN   "swpDc8FImFeYbSGpwv2y"
#define thingsboard_SERVER  "demo.thingsboard.io"
 
