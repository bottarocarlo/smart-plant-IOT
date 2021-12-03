#include "Arduino.h"
#include "Thermistor.h"

Thermistor::Thermistor(int pin)
{
  pinMode(pin, OUTPUT); //Set output to get out power
    _pin = pin;
}

double Thermistor::conversion(int value)
{
  double Temp;
  Temp = log(10000.0 * ((1024.0 / value - 1)));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
  Temp = Temp - 273.15;
  return Temp;  
}

void Thermistor::getTemp()
{
  digitalWrite(_pin, LOW);
  for (int i = 0; i < 100; i++) {
    double Temperature = conversion(analogRead(A0));
    Serial.println(Temperature);
  }
  digitalWrite(_pin, HIGH);
  delay(10000);
}

