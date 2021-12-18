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

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);


void water() {

  //Serial.println("OK BRO");
  /*
    digitalWrite(pump, HIGH);
    delay(2000);
    digitalWrite(pump, LOW);
  */
}

void setupOutput() {
  //dichiarazione GPIO
  pinMode(ledPin, OUTPUT);
  pinMode(pump, OUTPUT);
  digitalWrite(ledPin, ledState);
  digitalWrite(pump, LOW);
}

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

// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  for (int i = 0; i < numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID) {
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }

    // Print the received message
    String user_text = bot.messages[i].text;
    Serial.println(user_text);

    String your_name = bot.messages[i].from_name;

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
      //bot.sendMessage(chat_id, "Mode is now set to TIMER", "");


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
      bot.sendMessage(chat_id, "Working on it, wait few seconds..", "");
      if (Serial.available() > 0)
      {
        delay(5);  // wait for all 4 bytes
        byte buf[4];
        byte* bp = buf;
        while (Serial.available()) {
          *bp = Serial.read();
          if (bp - buf < 3) bp++;
        }
        float received = * (float*)buf;
        sensValue[3] = received;
        bot.sendMessage(chat_id, "Temp: " + sensValue[3], "");
        //Serial.print("TEMP --> ");
        //Serial.println(received, 3); // printing the result to the serial monitor

      }
      delay(100); // not really required, should be smaller than sender cycle that is set to 3k
      if (Lux.available() > 0)
      {
        delay(5);  // wait for all 4 bytes
        byte buf[4];
        byte* bp = buf;
        while (Lux.available()) {
          *bp = Lux.read();
          if (bp - buf < 3) bp++;
        }
        float received = * (float*)buf;
        sensValue[0] = received;
        bot.sendMessage(chat_id, "Lum: " + sensValue[0], "");
        //Serial.print("LUX --> ");
        //Serial.println(received, 3); // printing the result to the serial monitor

      }
      delay(100);
      if (Water.available() > 0)
      {
        delay(5);  // wait for all 4 bytes
        byte buf[4];
        byte* bp = buf;
        while (Water.available()) {
          *bp = Water.read();
          if (bp - buf < 3) bp++;
        }
        float received = * (float*)buf;
        sensValue[1] = received;
        bot.sendMessage(chat_id, "Water: " + sensValue[1], "");
        //Serial.print("WATER --> ");
        //Serial.println(received, 3); // printing the result to the serial monitor


        delay(100);
        if (SoilHum.available() > 0)
        {
          delay(5);  // wait for all 4 bytes
          byte buf[4];
          byte* bp = buf;
          while (SoilHum.available()) {
            *bp = SoilHum.read();
            if (bp - buf < 3) bp++;
          }
          float received = * (float*)buf;
          sensValue[2] = received;
          bot.sendMessage(chat_id, "SoilHum: " + sensValue[2], "");
          //Serial.print("SOILHUM --> ");
          //Serial.println(received, 3); // printing the result to the serial monitor

        }
      }


    }
    //WATER
    if (user_text == "/water"  && mode == 0) {
      water();
      bot.sendMessage(chat_id, "I'll give your plant some water", "");
    } else if (user_text == "/water"  && mode != 0) {
      bot.sendMessage(chat_id, "Error try to change mode to MANUAL to give water!", "");
    }



    if (user_text == "/options")
    {
      String keyboardJson = "[[\"/ledon\", \"/ledoff\"],[\"/status\"]]";
      bot.sendMessageWithReplyKeyboard(chat_id, "Choose from one of the following options", "", keyboardJson, true);
    }

    if(user_text.toInt() > 0 && user_text.toInt()< 100) {
      

      // Print the received message
        String user_text = bot.messages[i].text;
        
        timer = user_text.toInt();
        Serial.println("SONO IO");
        Serial.println(timer);

        if (timer > 0) {  // tests if myChar is a digit
          timer = timer * 10000;
          Serial.println(timer);
          Serial.println(millis());
          //DA MODIFICARE CON 3600000 PER LE ORE!! COS^ SONO MOMENTANEAMENTE SECONDI
          lastTimeforTimer = millis();
        }
        else {
          bot.sendMessage(chat_id, "Mattachione!", "");
        }

    }
  }
}

void bot_setup()
{
  const String commands = F("["
                            "{\"command\":\"start\", \"description\":\"Message sent when you open a chat with a bot\"},"
                            "{\"command\":\"get_mode\",  \"description\":\"Get bot usage help\"},"
                            "{\"command\":\"get_state\", \"description\":\"Message sent when you open a chat with a bot\"},"
                            "{\"command\":\"help\",\"description\":\"not done yet\"}" // no comma on last command
                            "]");
  bot.setMyCommands(commands);
  //bot.sendMessage("25235518", "Hola amigo!", "Markdown");
}

void setup() {
  Serial.begin(115200);
  Lux.begin(115200);
  Water.begin(115200);
  SoilHum.begin(115200);

#ifdef ESP8266
  configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
  client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
#endif


  setupOutput();
  setupWiFi();
  bot_setup();
}



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
    water();
    lastTimeforTimer = millis();
  }


}
