#ifdef ESP32
#include <WiFi.h>
#else
#include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include "SoftwareSerial.h"
#include "config.h"

#ifdef ESP8266
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif

boolean newData = false;

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);


//============

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

  while (input.available() > 0 && newData == false) {
    rc = input.read();



    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      }
      else {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
        //Serial.print("Ricevuto: ");
        //Serial.println(receivedChars);
      }
    }

    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}

//============
void sendInterrupt() {
  digitalWrite(D7, HIGH);
  delay(10); // short delay
  digitalWrite(D7, LOW);
  //Serial.println("Interrupt inviato");
}
//============

void parseData() {      // split the data into its parts

  //Serial.println("Entrato nel parsing");

  char * strtokIndx; // this is used by strtok() as an index

  strtokIndx = strtok(tempChars, ","); // this continues where the previous call left off
  temp = atof(strtokIndx);     // convert this part to an integer
  //Serial.println(temp);

  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  lux = atof(strtokIndx);     // convert this part to an integer
  //Serial.println(lux);

  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  water = atof(strtokIndx);     // convert this part to an integer
  //Serial.println(water);


  strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
  soilHum = atof(strtokIndx);     // convert this part to an integer
  //Serial.println(soilHum);

}

//============

void showParsedData() {

String sensors = "Temp: " + (String)temp + "\n";
      sensors += "Lux: " + (String)lux + "\n";
      sensors += "Water: " + (String)water + "\n";
      sensors += "SoilHum: " + (String)soilHum + "\n";
      bot.sendMessage(chat_id, sensors, "");
  
  /*
    bot.sendMessage(chat_id, "Temp: " + (String)temp, "");
    bot.sendMessage(chat_id, "Lux: " + (String)lux, "");
    bot.sendMessage(chat_id, "Water: " + (String)water, "");
    bot.sendMessage(chat_id, "SoilHum: " + (String)soilHum, "");
  */
    
}

//============

void giveWater() {
  // Pumps works for 2 seconds
  digitalWrite(D0, HIGH);
  delay(2000);
  digitalWrite(D0, LOW);
}

//============

void setupOutput() {
  // Declaration GPIO
  pinMode(ledPin, OUTPUT);
  pinMode(D0, OUTPUT);
  digitalWrite(ledPin, ledState);
  digitalWrite(D0, LOW);
}

//============

void setupWiFi() {
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

//============

void handleNewMessages(int numNewMessages) {  // Handle what happens when you receive new messages
  for (int i = 0; i < numNewMessages; i++) {
    // Chat id of the requester
    chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID) {
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }

    // Print the received message
    String user_text = bot.messages[i].text;
    Serial.println(user_text);

    String your_name = bot.messages[i].from_name;

    // START
    if (user_text == "/start") {
      bot.sendChatAction(chat_id, "typing");
      delay(2000);
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

    //MANUAL mode=0
    if (user_text == "/manual") {
      String welcome = "Mode is now set to MANUAL\n";
      welcome += "Use the command /water to control your plant!🪴🪴\n";
      bot.sendMessage(chat_id, welcome, "");

      mode = 0;
    }

    //AUTOMATIC mode=1
    if (user_text == "/automatic") {
      bot.sendMessage(chat_id, "Mode is now set to AUTOMATIC", "");
      mode = 1;
    }

    //TIMER mode=2
    if (user_text == "/timer") {
      bot.sendMessage(chat_id, "Mode is now set to TIMER,\nSend every x hours", "");
      mode = 2;
    }

    //GET_MODE
    if (user_text == "/get_mode") {
      if (mode == 0) {
        bot.sendMessage(chat_id, "Mode set to MANUAL", "");
      } else if (mode == 1) {
        bot.sendMessage(chat_id, "Mode set to AUTOMATIC", "");
      } else if (mode == 2) {
        bot.sendMessage(chat_id, "Mode set to TIMER", "");
      } else {
        bot.sendMessage(chat_id, "Mode not set yet, Error 001", "");
      }
    }

    //GET_STATE
    if (user_text == "/get_state") {
      int success = 0;
      bot.sendMessage(chat_id, "Working on it, wait few seconds..", "");

      while (success != 1) {
        sendInterrupt();

        recvWithStartEndMarkers();

        if (newData == true) {
          strcpy(tempChars, receivedChars);
          parseData();
          showParsedData();
          newData = false;
          success = 1;
          Serial.println(" ");
          Serial.println(" ");
        }
      }

    }

    //WATER MANUAL MODE
    if (user_text == "/water"  && mode == 0) {
      giveWater();
      bot.sendMessage(chat_id, "I'll give your plant some water", "");
    } else if (user_text == "/water"  && mode != 0) {
      bot.sendMessage(chat_id, "Error try to change mode to MANUAL to give water!", "");
    }


    //WATER TIMER MODE
    if (user_text.toInt() > 0 && user_text.toInt() < 100 && mode == 2) {
      // Print the received message
      String user_text = bot.messages[i].text;

      timer = user_text.toInt();
      Serial.println(timer);

      if (timer > 0) {  // tests if myChar is a digit
        timer = timer * 10000;
        String setTimer = "Timer is set for " + (String)timer + " hour(s)";
        //DA MODIFICARE CON 3600000 PER LE ORE!! COS^ SONO MOMENTANEAMENTE SECONDI
        bot.sendMessage(chat_id, setTimer, "");
        lastTimeforTimer = millis();
      }
      else {
        bot.sendMessage(chat_id, "Mattachione!", "");
      }

    }
  }
}

//============

void bot_setup() {
  const String commands = F("["
                            "{\"command\":\"start\", \"description\":\"Message sent when you open a chat with a bot\"},"
                            "{\"command\":\"automatic\",  \"description\":\"to water in autonomous way your plant\"},"
                            "{\"command\":\"manual\", \"description\":\"to manual water your plant when you want\"},"
                            "{\"command\":\"timer\",  \"description\":\"to water your plant every xx minutes\"},"
                            "{\"command\":\"get_mode\",  \"description\":\"----------------\"},"
                            "{\"command\":\"get_state\", \"description\":\"----------------\"},"
                            "{\"command\":\"help\",\"description\":\"---------------\"}" // no comma on last command
                            "]");
  bot.setMyCommands(commands);
}

//============

void setup() {
  Serial.begin(115200);
  input.begin(115200);
  pinMode(D7, OUTPUT);
  digitalWrite(D7, LOW);


#ifdef ESP8266
  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
#endif


  setupOutput();
  setupWiFi();
  bot_setup();
}

//============

void loop() {
  if (millis() > lastTimeBotRan + bot_delay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages) {
      Serial.println("Got Response!");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }

  if (mode == 2 && millis() > (lastTimeforTimer + timer)) {
    bot.sendMessage(chat_id, "gave some water", "");
    giveWater();
    lastTimeforTimer = millis();
  }


}
