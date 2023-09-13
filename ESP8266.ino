/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  NOTE: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_TEMPLATE_ID "TMPL6y_FfwTB0"
#define BLYNK_TEMPLATE_NAME "DHT11"
#define BLYNK_AUTH_TOKEN "jF3ZJYkS3SLe1UEwyMzqLN5IveEt62a3"
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
//#define BLYNK_TEMPLATE_NAME         "Device"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DFRobot_DHT11.h>
#include <Wire.h>
DFRobot_DHT11 DHT;

#define DHT11_PIN D6

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Tên Wifi";
char pass[] = "Pass Wifi";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
  DHT.read(DHT11_PIN);
  Blynk.virtualWrite(V1,DHT.temperature);
  Blynk.virtualWrite(V0,DHT.humidity);
  delay(1000);
}

