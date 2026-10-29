#include <Arduino.h>
#include <WiFi.h>
#include "secrets.h"

void connectWifi()
{
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED)
  {
    if (millis() - start > 15000)
    {
      Serial.println();
      Serial.print("Not connected, status code: ");
      Serial.println(WiFi.status());
      Serial.println("Retrying in 5 seconds");
      delay(5000);
      WiFi.disconnect();
      WiFi.begin(WIFI_SSID, WIFI_PASS);
      start = millis();
    }
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected. IP: ");
  Serial.println(WiFi.localIP());
}

void setup()
{
  Serial.begin(115200);
  delay(1000);
  connectWifi();
}

void loop()
{
}