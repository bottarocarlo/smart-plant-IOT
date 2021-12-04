#ifndef Moisture_h
#define Moisture_h

#include "Arduino.h"

class Moisture
{
  public:
    Moisture(int pin);
    float getMoisture();
  private:
    int _pin;
};

#endif

