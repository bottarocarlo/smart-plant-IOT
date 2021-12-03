#ifndef Photoresistor_h
#define Photoresistor_h

#include "Arduino.h"

class Photoresistor
{
  public:
    Photoresistor(int pin);
    double conversion(int value);
    void getLux();
  private:
    int _pin;
};

#endif

