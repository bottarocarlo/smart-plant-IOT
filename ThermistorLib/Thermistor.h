#ifndef Thermistor_h
#define Thermistor_h

#include "Arduino.h"

class Thermistor
{
  public:
    Thermistor(int pin);
    double conversion(int value);
    void getTemp();
  private:
    int _pin;
};

#endif

