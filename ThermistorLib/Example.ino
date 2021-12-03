#include <Thermistor.h>


Thermistor thermistor(D2);

void setup(){
  Serial.begin(115200);
  }

void loop(){
    thermistor.getTemp();
  }
