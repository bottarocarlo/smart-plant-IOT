#include <Moisture.h>





Moisture photoresistor(D2);

void setup(){
  Serial.begin(115200);
  }

void loop(){
    Serial.println(photoresistor.getMoisture());
  }
