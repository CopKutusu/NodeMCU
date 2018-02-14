#include "Arduino.h"
#include "ultrasonic.h"

int ultrasonic::getDataFromSensor(byte trigger, byte echo)
{
	unsigned long sure; // Echo bacağının kac mikro saniyede aktif olduğunu saklayacak olan değişken
	double toplamYol;
	int aradakiMesafe;



  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  sure = pulseIn(echo, HIGH);
  toplamYol = (double)sure * 0.034;
  aradakiMesafe = toplamYol / 2;

  Serial.print("Ses dalgasinin geri donus suresi :");
  Serial.print(sure);
  Serial.println("mikro saniye");

  Serial.print("Ses dalgasinin toplam kat ettigi yol :");
  Serial.print(toplamYol);
  Serial.println("cm.");

  Serial.print("HC-SR04 ile karsisindaki yuzey arasindaki mesafe :");
  Serial.print(aradakiMesafe);
  Serial.println("cm.\n\n");

  delay(3000);
  return aradakiMesafe;
}

