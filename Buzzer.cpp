#include <Arduino.h>
#include "Buzzer.h"

Buzzer::Buzzer(int pin) {
  this->pin = pin;
  this->melody = nullptr;
  this->durations = nullptr;
  this->size = 0;
  this->currentNote = 0;
  this->playing = false;
}

Buzzer::init() {
  pinMode(pin, OUTPUT);
}

Buzzer::playMelody(int melody[], int durations[], int sizeOfDurations) {
  this->melody = melody;
  this->durations = durations;
  this->size = sizeOfDurations;
  this->currentNote = 0;
  this->playing = true;
  this->noteStartMillis = millis();

  int duration = 1000 / durations[currentNote];
  tone(pin, melody[currentNote], duration);
}

Buzzer::stopMelody() {
  noTone(pin);
  playing = false;
}

Buzzer::update() {
  if (!playing) return;

  unsigned long currentMillis = millis();
  int duration = 1000 / durations[currentNote];
  int pause = duration * 1.30;

  if (currentMillis - noteStartMillis >= (unsigned long)pause) {
    noTone(pin);
    currentNote++;

    if (currentNote < size) {
      noteStartMillis = currentMillis;
      int nextDuration = 1000 / durations[currentNote];
      tone(pin, melody[currentNote], nextDuration);
    } else {
      playing = false; // finished
    }
  }
}

bool Buzzer::isPlaying() {
  return playing;
}