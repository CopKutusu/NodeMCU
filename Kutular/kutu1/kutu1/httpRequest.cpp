#include "Arduino.h"
#include "httpRequest.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
String httpRequest::httpGetRequest(String ReqURL, String RequestBilgisi)
{
   String payload;
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    Serial.println("Kontrol Ediliyor...");
    HTTPClient http;  //Declare an object of class HTTPClient

    // Burada Adafruit.io içerisine gönderilen son data GET ediliyor.Eğer veri mevcut değilse 404 hatası verecektir.Çok takılma.
    http.begin(ReqURL);  //Specify request destination
    int httpCode = http.GET();//Send the request
      if (RequestBilgisi == "get"){
            Serial.print("GET HTTP CODE : ");
      }
      else 
      {
        Serial.print("POST HTTP CODE : ");
      }
    Serial.println(httpCode);

    if (httpCode > 0) { //Check the returning code
     // Response değeri 
       payload = http.getString();   //Get the request response payload

      // Burada bir şey dikkatimi çekti.Bu kod içinde yok ama gelen Response'yi JSON parser kullanarak parse etmek isteyince Response içinde [ .... ]  bu köşeli parantezlerden dolayı parse hata veriyordu.
      // Bende başta ve sonda bulunan bu köşeli parantezleri kaldırdım.Aşagıdaki kodlar bunun içindir.
      int ilkParantez = 0;
      int sonParantez = payload.length() - 1;

      payload.remove(ilkParantez, ilkParantez + 1);
      payload.remove(sonParantez - 1);
    //  Serial.print("Updated string value: ");
    //  Serial.println(payload);
    }
    http.end();   //Close connection
  }
  delay(3000);
    return payload;
}

