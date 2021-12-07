#ifndef config_h
#define config_h

// WiFi
#define ssid     "Universitari"			// Add wifi name
#define password "UniversitarioMatto.2020$"	// Add wifi passowrd

// Initialize Telegram BOT
#define BOTtoken "2142355090:AAGgN6cov95TfNgBSPHevaTcp2sR6L6VxcM"	// replace this with your bot token
#define CHAT_ID "189749700"		//replace with your telegram user ID

//SENSOR & ATTUATOR
const int ledPin = D2;
bool ledState = LOW;
const int pump = LED_BUILTIN;

#endif
