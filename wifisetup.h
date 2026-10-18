#ifndef WIFISETUP_H
#define WIFISETUP_H

#include <Arduino.h>
#include <WiFi.h>

// Set these in secrets.h (copy secrets.example.h); leave empty to use setup AP.
#if __has_include("secrets.h")
#include "secrets.h"
#else
#define WIFI_SSID ""
#define WIFI_PASSWORD ""
#endif

constexpr char AP_SSID[] = "CandyBar-Setup";
constexpr char AP_PASSWORD[] = "CandyBar123";

inline void setupWiFi() {
  WiFi.mode(WIFI_AP_STA);
  if (strlen(WIFI_SSID) > 0) {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    const unsigned long startedAt = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startedAt < 15000) {
      delay(250);
    }
    if (WiFi.status() == WL_CONNECTED) {
      Serial.print("WLAN verbunden: ");
      Serial.println(WiFi.localIP());
      return;
    }
    Serial.println("Router nicht erreichbar; starte Einrichtungs-AP.");
  }
  WiFi.softAP(AP_SSID, AP_PASSWORD);
  Serial.print("Einrichtungs-AP: ");
  Serial.println(WiFi.softAPIP());
}
#endif
