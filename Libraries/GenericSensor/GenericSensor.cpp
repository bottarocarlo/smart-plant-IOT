#include "Arduino.h"
#include "GenericSensor.h"

GenericSensor::GenericSensor(int pin)
{
  pinMode(pin, OUTPUT); //Set output to get out power
    _pin = pin;
}

float GenericSensor::getValue()
{
  digitalWrite(_pin, LOW);
  for (int i = 0; i < 100; i++) {
    float value = analogRead(A0);
    //Serial.println(value);
    return value;
  }
  digitalWrite(_pin, HIGH);
  delay(10000);
}
