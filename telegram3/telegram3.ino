#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   
#include <ArduinoJson.h>


// Replace with your network credentials
const char* ssid = "iPhone di Carlo";
const char* password = "carletto2";

// Initialize Telegram BOT
#define BOTtoken "2142355090:AAGgN6cov95TfNgBSPHevaTcp2sR6L6VxcM"  // replace this with your bot token

#define CHAT_ID "189749700"  //replace with your telegram user ID

#ifdef ESP8266
  X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int bot_delay = 1000;
unsigned long lastTimeBotRan;

const int ledPin = D2;
bool ledState = LOW;
int mode = NULL;
/*
*0-manual 
*1-automatic
*2-timer
*/

// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  Serial.println("New Message");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    
    // Print the received message
    String user_text = bot.messages[i].text;
    Serial.println(user_text);

    String your_name = bot.messages[i].from_name;

    if (user_text == "/start") {
      String welcome = "Welcome, " + your_name + ".\n";
      welcome += "Use the following commands to control your plants!🪴🪴\n";
      welcome += "You can now choose how to water your plant \n";
      welcome += "Send /automatic to water in autonomous way your plant \n";
      welcome += "Send /manual to manual water your plant when you want\n";
      welcome += "Send /timer to water your plant every xx minutes \n";
      welcome += "Send /get_state to request current state \n";
      welcome += "Send /get_mode to request current mode \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (user_text == "/led2_on") {
      bot.sendMessage(chat_id, "LED state set to ON", "");
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
    }
    
    if (user_text == "/led2_off") {
      bot.sendMessage(chat_id, "LED state is set to OFF", "");
      ledState = LOW;
      digitalWrite(ledPin, ledState);
    }
    
    if (user_text == "/get") {
      if (digitalRead(ledPin)){
        bot.sendMessage(chat_id, "LED is ON", "");
      }
      else{
        bot.sendMessage(chat_id, "LED is OFF", "");
      }
    }

    
    if (user_text == "/manual") {
      bot.sendMessage(chat_id, "Mode is now set to MANUAL", "");
      mode =0;
    }
    if (user_text == "/automatic") {
      bot.sendMessage(chat_id, "Mode is now set to AUTOMATIC", "");
      mode =1;
    }
    if (user_text == "/timer") {
      bot.sendMessage(chat_id, "Mode is now set to TIMER", "");
      mode =2;
    }
    if (user_text == "/get_mode") {
      if(mode==0){
        bot.sendMessage(chat_id, "Mode set to MANUAL", "");
      }else if(mode==1){
        bot.sendMessage(chat_id, "Mode set to AUTOMATIC", "");
      }else if(mode==2){
        bot.sendMessage(chat_id, "Mode set to TIMER", "");
      }else{
        bot.sendMessage(chat_id, "Mode not set yet, Error 001", "");
      }
      
    }
    if (user_text == "/get_state") {
      bot.sendMessage(chat_id, "Working on it..", "");
    }
       
  }
}

void setup() {
  Serial.begin(115200);

  #ifdef ESP8266
    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
    client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  #endif

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  #ifdef ESP32
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  #endif
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());
}

void loop() {
  if (millis() > lastTimeBotRan + bot_delay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages) {
      Serial.println("Got Response!");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}
