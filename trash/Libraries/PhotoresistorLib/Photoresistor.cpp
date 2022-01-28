#include "Arduino.h"
#include "Photoresistor.h"

Photoresistor::Photoresistor(int pin)
{
  pinMode(pin, OUTPUT); //Set output to get out power
    _pin = pin;
}

double Photoresistor::conversion(int value)
{
float voltage = float(value) * (3.3 / float(1023)); //3.3V? con 5V va --> TEST
float resistence = (1000 * (3.3 - voltage))/voltage; //1000 resistenza, se cambiamo res cambiamo par
int lux=500/(resistence/1000); 
return lux; 
}

float Photoresistor::getLux()
{
  digitalWrite(_pin, LOW);
  for (int i = 0; i < 100; i++) {
    double Lux = conversion(analogRead(A0));
    //Serial.println(Lux);
    return Lux;
  }
  digitalWrite(_pin, HIGH);
  delay(10000);
}

