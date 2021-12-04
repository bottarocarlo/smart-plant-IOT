#include <GenericSensor.h>

GenericSensor sensor(D0);

void setup(){
  Serial.begin(115200);
  }

void loop(){
    float casa = sensor.getValue();
    Serial.print("VALORE STAMPATO --> ");
    Serial.println(casa);

    delay(10000);
  }
