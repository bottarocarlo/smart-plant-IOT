/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef Thermistor_h
#define Thermistor_h

#include "Arduino.h"

class Thermistor
{
  public:
    Thermistor(int pin);
    double conversion(int value);
    float getTemp();
  private:
    int _pin;
};

#endif

