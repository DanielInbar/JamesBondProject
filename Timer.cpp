#include "Timer.h"

Timer::Timer(int seconds)
  : seconds(seconds), running(false), finished(false), startMillis(0) {}

void Timer::start() {
  running = true;
  finished = false;
  startMillis = millis();
}

void Timer::reset() {
  running = false;
  finished = false;
  startMillis = 0;
}

long Timer::calcTime() {
  if (!running) return seconds * 1000L;

  unsigned long now = millis();
  unsigned long elapsed = now - startMillis;
  long remaining = (seconds * 1000L) - elapsed;

  if (remaining <= 0) {
    running = false;
    finished = true;
    remaining = 0;
  }

  return remaining;
}
