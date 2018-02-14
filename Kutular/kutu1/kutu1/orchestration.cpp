#include "Arduino.h"
#include "orchestration.h"

	//  Yapılacak her isteğin bir URL 'i olacak.Bunları bu şekilde belirtiyoruz.Burada önemli nokta HTTPS degilde HTTP kullanılmalıdır.
// getURI , postURI ve aioKey her zaman sabit 
String orchestration::getURI = "http://io.adafruit.com/api/v2/cengize/feeds/";
String orchestration::postURI = "http://io.adafruit.com/api/groups/";
String orchestration::aioKey = "2b06ca1d03eb4568983a2fbe8126f100";

// kutu bilgisi değişiyor.
String orchestration::kutuInformation = "kutu";   // kutu,kutu1,kutu2 ...


// Requests
String orchestration::locationLatitudeGetURL = getURI + kutuInformation + ".locationlatitude/data";
String orchestration::locationLatitudePostURL = postURI + kutuInformation +"/send.json?x-aio-key=" + aioKey + "&" + kutuInformation +".locationlatitude=";  // alt kısımda bunun sonuna değeri (locationLatitude ) eklenip request yapılacak.


String orchestration::locationLongitudeGetURL = getURI + kutuInformation + ".locationlongitude/data";
String orchestration::locationLongitudePostURL = postURI + kutuInformation +"/send.json?x-aio-key=" + aioKey + "&" + kutuInformation +".locationlongitude=";  // alt kısımda bunun sonuna değeri (locationLatitude ) eklenip request yapılacak.


String orchestration::solidityRatioGetURL = getURI + kutuInformation + ".solidityratio/data";
String orchestration::solidityRatioPostURL = postURI + kutuInformation +"/send.json?x-aio-key=" + aioKey + "&" + kutuInformation +".solidityratio=";  // alt kısımda bunun sonuna değeri (locationLatitude ) eklenip request yapılacak.

String orchestration::temperatureGetURL = getURI + kutuInformation + ".solidityratio/data";
String orchestration::temperaturePostURL = postURI + kutuInformation +"/send.json?x-aio-key=" + aioKey + "&" + kutuInformation +".temperature=";  // alt kısımda bunun sonuna değeri (locationLatitude ) eklenip request yapılacak.

