#include "timer.h"
#include <Arduino.h>

unsigned long myTimer = 0;

bool timePassed(unsigned long &lastTime, unsigned long interval) {
  unsigned long currentTime = millis();
  if (currentTime - lastTime >= interval) {
    lastTime = currentTime;
    return false;
  }
  return true;
}
