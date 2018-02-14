#ifndef httpRequest_h
#define httpRequest_h
#include "Arduino.h"
class httpRequest
{
  public:
    String httpGetRequest(String ReqURL, String RequestBilgisi);
};
#endif

