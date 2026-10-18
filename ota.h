#ifndef OTA_H
#define OTA_H

#include <Arduino.h>
#include <ArduinoOTA.h>

inline void setupOTA() {
  ArduinoOTA.setHostname("candybar");
  ArduinoOTA.begin();
}

inline void handleOTA() {
  ArduinoOTA.handle();
}
#endif
