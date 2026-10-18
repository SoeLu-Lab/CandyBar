#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

constexpr uint8_t buttonPin = 12;
bool buttonState = false;
bool lastRawButtonState = false;
unsigned long buttonChangedAt = 0;
constexpr unsigned long BUTTON_DEBOUNCE_MS = 35;

inline void setupButton() {
  pinMode(buttonPin, INPUT_PULLUP);
}

inline void checkButton() {
  const bool rawPressed = digitalRead(buttonPin) == LOW;
  const unsigned long now = millis();
  if (rawPressed != lastRawButtonState) {
    lastRawButtonState = rawPressed;
    buttonChangedAt = now;
  }
  if (now - buttonChangedAt >= BUTTON_DEBOUNCE_MS && rawPressed != buttonState) {
    buttonState = rawPressed;
    if (buttonState) zufallsEffekt();
  }
}
#endif

