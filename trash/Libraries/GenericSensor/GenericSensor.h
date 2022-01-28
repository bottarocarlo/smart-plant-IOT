#ifndef GenericSensor_h
#define GenericSensor_h

#include "Arduino.h"

class GenericSensor
{
  public:
    GenericSensor(int pin);
    float getValue();
  private:
    int _pin;
};

#endif

