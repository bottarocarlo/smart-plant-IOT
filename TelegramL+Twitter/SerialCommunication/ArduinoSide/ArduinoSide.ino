#include "conversion.h"
#include <SoftwareSerial.h>


SoftwareSerial output(5, 6); //rx, tx


volatile float tempArr = 0.00;
volatile float luxArr = 0.00;
volatile float waterArr = 0.00;
volatile float soilHumArr = 0.00;

int state = 0;




//============

void setup() {

  while (millis() < 5000) {
    
  }
  Serial.begin(115200);
  output.begin(115200);
  pinMode(3, INPUT);

  attachInterrupt(digitalPinToInterrupt(3), sendData, RISING);


}

//============

void loop() {


  if (state == 1) {
    tempArr = analogRead(A0);
    tempArr = TempConversion(tempArr);
    luxArr = analogRead(A1);
    luxArr = LuxConversion(luxArr);
    //waterArr = analogRead(A2);
    //waterArr = map(waterArr, 0, 300, 0, 100);
    soilHumArr = analogRead(A3);
    soilHumArr = map(soilHumArr, 600, 150, 0, 100);
    String valori = "<" + (String)tempArr + "," + (String)luxArr + "," + (String)waterArr + "," + (String)soilHumArr + ">";
    Serial.println(valori); //For debug, to check if the values are correct on Arduino Side
    output.println(valori);
    state = 0;
    attachInterrupt(digitalPinToInterrupt(3), sendData, RISING);
  }

}

void sendData() {
  state = 1;
  detachInterrupt(digitalPinToInterrupt(3));
}
