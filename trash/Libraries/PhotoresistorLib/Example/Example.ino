#include <Photoresistor.h>



Photoresistor photoresistor(D2);

void setup(){
  Serial.begin(115200);
  }

void loop(){
    thermistor.getLux();
  }
