#include "Arduino.h"
#include "myDht.h"
#include "DHT.h"
int myDht::getDataFromTemperature(DHT dht)
{
  return dht.readTemperature();
}

