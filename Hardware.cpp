#include "hardware.h"
#include "Buzzer.h"

Hardware::Hardware() {}

void Hardware::begin() {
    
    pinMode(confirmPin, INPUT_PULLUP);
    pinMode(resetPin, INPUT_PULLUP);
    pinMode(buzzerPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    lcd.begin();
    lcd.backlight();
    display("Bond Bomb Game", "Ready...");
}

void Hardware::updateInputs() {
    confirmState = !digitalRead(confirmPin);
    resetState = !digitalRead(resetPin);
}

int Hardware::getPotValue() {
    return analogRead(potPin);
}

bool Hardware::isConfirmPressed() {
    return confirmState;
}

bool Hardware::isResetPressed() {
    return resetState;
}

void Hardware::buzzerBeep(int duration) {
    digitalWrite(buzzerPin, HIGH);
    delay(duration);
    digitalWrite(buzzerPin, LOW);
}

void Hardware::ledOn() {
    digitalWrite(ledPin, HIGH);
}

void Hardware::ledOff() {
    digitalWrite(ledPin, LOW);
}

void Hardware::display(const String &line1, const String &line2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(line1);
    lcd.setCursor(0, 1);
    lcd.print(line2);
}
