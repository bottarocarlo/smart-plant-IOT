#ifndef config_h
#define config_h

  // WiFi
  
  /*
   * 
   * #define ssid     "Universitari"			// Add wifi name
   * #define password "UniversitarioMatto.2020$"	// Add wifi passowrd
   * 
   */
#define ssid     "iPhone di Lorenzo"      // Add wifi name
#define password "lorenzo123456789"            // Add wifi passowrd

// Initialize Telegram BOT
#define BOTtoken "2114616836:AAENrzwFoBEzlcyvKl2N89dOf95QXnUszIk"	// replace this with your bot token
#define CHAT_ID "250893524"		//replace with your telegram user ID
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
/*
 * sensValue[0]==Photoresistor
 * sensValue[1]==Waterlevel
 * sensValue[2]==SoilHumidity
 * sensValue[3]==Thermoresistor
 */
int sensPos = 0; //Posizione nell'array
String data;
String valori;

  // BOT time.
int bot_delay = 1000;
unsigned long lastTimeBotRan=0;
unsigned long lastTimeforTimer=0;
unsigned long timer=-1;

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
