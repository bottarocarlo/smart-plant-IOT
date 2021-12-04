#include "Arduino.h"
#include "Moisture.h"

Moisture::Moisture(int pin)
{
  pinMode(pin, OUTPUT); //Set output to get out power
    _pin = pin;
}

float Moisture::getMoisture()
{
  digitalWrite(_pin, LOW);
  for (int i = 0; i < 100; i++) {
    float Moisture = analogRead(A0);
    Serial.println(Moisture);
  }
  digitalWrite(_pin, HIGH);
  delay(10000);
}
