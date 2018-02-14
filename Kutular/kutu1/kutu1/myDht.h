#ifndef myDht_h
#define myDht_h
#include "Arduino.h"
#include "DHT.h"
class myDht
{
  public:
    int getDataFromTemperature(DHT dht);
};
#endif

