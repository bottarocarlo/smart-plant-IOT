#include "conversion.h"
#include <SoftwareSerial.h>

SoftwareSerial output(5, 6); //rx, tx

float tempArr = 0.0;
float luxArr = 0.0;
float waterArr = 0.0;
float soilHumArr = 0.0;




//============

void setup() {
  Serial.begin(115200);
  output.begin(115200); 
  
}

//============

void loop() {
  tempArr = analogRead(A0);
  tempArr = TempConversion(tempArr);
  luxArr = analogRead(A1);
  luxArr = LuxConversion(luxArr);
  waterArr = analogRead(A2);
  waterArr = map(waterArr, 0, 300, 0, 100);
  soilHumArr = analogRead(A3);
  soilHumArr = map(soilHumArr, 600, 150, 0, 100);
  String valori = "<" + (String)tempArr + "," + (String)luxArr + "," + (String)waterArr + "," + (String)soilHumArr + ">";
  Serial.println(valori); //For debug, to check if the values are correct on Arduino Side
  output.println(valori);
  delay(10000);
}
