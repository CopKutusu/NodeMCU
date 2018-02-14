#ifndef orchestration_h
#define orchestration_h
#include "Arduino.h"
class orchestration
{
  public:
  // Buradaki değişkenleri tanımlarken static kullanmamız gerekiyormuş
String static getURI;
String static postURI;
String  static aioKey ;
String static kutuInformation;

String static locationLatitudeGetURL;
String  static locationLatitudePostURL ;


String static locationLongitudeGetURL ;
String static locationLongitudePostURL ;


String static solidityRatioGetURL ;
String static solidityRatioPostURL;

String static temperatureGetURL;
String static temperaturePostURL;
};
#endif

