
// Ã–ncelikle ArduinoJson kÃ¼tÃ¼phanesi yÃ¼klenir.Bunun nasÄ±l yapÄ±ldÄ±ÄŸÄ± detaylÄ± olarak anlatÄ±lacak !!!!!!!
#include <ArduinoJson.h>
// AynÄ± ÅŸekilde ESP kÃ¼tÃ¼phaneleride 
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "httpRequest.h"
#include "ultrasonic.h"
#include "orchestration.h"
//#include "DHT.h"

//#define DHTPIN 14
//#define DHTTYPE DHT11
//DHT dht(DHTPIN, DHTTYPE);

httpRequest http;
ultrasonic  sensor;
orchestration  orch;


// Nodemcu  datasheetinde belirtilen GPIO bacaklarÄ±nÄ±n numaralarÄ±na gÃ¶re kullanÄ±lan pinler.Ã–nceden 0  ve 2 ye baÄŸlÄ±ydÄ±.
byte trigger = 4; // SensÃ¶rÃ¼n Trigger bacaÄŸÄ±nÄ±n baÄŸlÄ± olduÄŸu pin  d2 -> GPIO 4
byte echo = 5; // SensÃ¶rÃ¼n Echo bacaÄŸÄ±nÄ±n baÄŸlÄ± olduÄŸu pin        d1 -> GPIO 5

// Wifi user - passs

const char* ssid     = "Connectify-1";
const char* password = "123456789";

//const char* ssid     = "TurkTelekom_TC33C";
//const char* password = "tTgYGafp";

// her Ã§Ã¶p kutusunda bu konum bilgileri deÄŸiÅŸtirilecek
double locationLatitude  = 40.768091;
double locationLongitude = 29.937862;
// NOT : Her kutunun id 'sini suan elle istek atÄ±yoruz.
int boxID =2;
//int temperature;

void setup() {
  pinMode(trigger, OUTPUT); // SensÃ¶rÃ¼n Trigger bacaÄŸÄ±na gerilim uygulayabilmemiz iÃ§in OUTPUT yapÄ±yoruz.
  pinMode(echo, INPUT); // SensÃ¶rÃ¼n Echo bacaÄŸÄ±ndaki gerilimi okuyabilmemiz iÃ§in INPUT yapÄ±yoruz.
  Serial.begin(9600);

  // Wifi'yi baÅŸlatÄ±yor.
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting..");
  }
}

void loop()
{
  //temperature = dht.readTemperature();
  //Serial.print("Temperature :");
  //Serial.println(temperature);
  String postReq ="";     // Her seferinde baÅŸtan oluÅŸturulan data gÃ¶ndermek iÃ§in kullanÄ±lacak olan deÄŸiÅŸken
  //String sicaklik = String(temperature);
  //postReq = orch.temperaturePostURL + sicaklik;
  //Serial.print("POST URL : ");
  //Serial.println(postReq);
  //http.httpGetRequest(postReq,"post");  // Doluluk bilgisi sunucuya gÃ¶nderilir.

 //delay(1000);
  
  int aradakiMesafe= sensor.getDataFromSensor(trigger,echo);
  http.httpGetRequest(orch.solidityRatioGetURL,"get");  // Doluluk bilgisi sunucudan alÄ±nÄ±r.
  
  String mesafe = String(aradakiMesafe);  // SensÃ¶rden Ã¶lÃ§Ã¼len deÄŸeri sunucuya gÃ¶nderilecek olan URL'ye ekliyoruz.
  postReq = orch.solidityRatioPostURL + mesafe;
  Serial.print("POST URL : ");
  Serial.println(postReq);

    
// TODO :  Get location information from Adafruit and Check datas with here location datas.Ä°f each data equals -> nothing do , else -> post new datas to Adafruit
  
  http.httpGetRequest(postReq,"post");  // Doluluk bilgisi sunucuya gÃ¶nderilir.
  delay(500);
  Serial.println("Uykuya GeÃ§iyorum");
 // ESP.deepSleep(5 * 60 * 1000000); //sleep for 5 minutes
 ESP.deepSleep(10000000, WAKE_RF_DEFAULT); //sleep for 10 second
 delay(500);

  //delay(10000);
}


