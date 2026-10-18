#include <Arduino.h>
#include "wifisetup.h"
#include "effekte.h"
#include "ota.h"
#include "button.h"

void setup() {
  Serial.begin(115200);
  setupLEDs();
  setupButton();
  setupWiFi();
  setupOTA();
}

void loop() {
  handleOTA();
  checkButton();
  updateEffect();
}
