#ifndef ultrasonic_h
#define ultrasonic_h
#include "Arduino.h"
class ultrasonic
{
  public:
    int getDataFromSensor(byte trigger, byte echo);
};
#endif

