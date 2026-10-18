#ifndef EFFEKTE_H
#define EFFEKTE_H

#include <Arduino.h>
#include <FastLED.h>

constexpr uint16_t NUM_RINGS = 48;
constexpr uint8_t LEDS_PER_RING = 12;
constexpr uint8_t DATA_PIN = 5;
constexpr uint8_t BRIGHTNESS = 20;
constexpr uint16_t NUM_LEDS = NUM_RINGS * LEDS_PER_RING;
constexpr unsigned long EFFECT_DURATION_MS = 1100;
constexpr unsigned long EFFECT_STEP_MS = 35;

CRGB rings[NUM_RINGS][LEDS_PER_RING];
bool effectActive = false;
unsigned long effectStartedAt = 0;
unsigned long lastEffectStepAt = 0;
uint8_t effectRing = 0;

inline void setAll(CRGB color) {
  fill_solid(&rings[0][0], NUM_LEDS, color);
  FastLED.show();
}

inline void pulsieren(CRGB color) {
  // Original behavior is a steady color despite the legacy function name.
  setAll(color);
}

inline void setupLEDs() {
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(&rings[0][0], NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  setAll(CRGB::Blue);
}

inline void zufallsEffekt() {
  effectActive = true;
  effectStartedAt = millis();
  lastEffectStepAt = 0;
  fill_solid(&rings[0][0], NUM_LEDS, CRGB::Black);
}

inline void updateEffect() {
  if (!effectActive) return;

  const unsigned long now = millis();
  if (now - lastEffectStepAt >= EFFECT_STEP_MS) {
    lastEffectStepAt = now;
    fill_solid(&rings[0][0], NUM_LEDS, CRGB::Black);
    effectRing = random(NUM_RINGS);
    fill_solid(rings[effectRing], LEDS_PER_RING, CRGB::White);
    FastLED.show();
  }
  if (now - effectStartedAt >= EFFECT_DURATION_MS) {
    effectActive = false;
    setAll(CRGB::Blue);
  }
}
#endif
