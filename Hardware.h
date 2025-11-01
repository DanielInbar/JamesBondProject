#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class Hardware {
public:
    Hardware();
    void begin();
    void updateInputs();

    int getPotValue();
    bool isConfirmPressed();
    bool isResetPressed();

    void buzzerBeep(int duration = 200);
    void ledOn(int mledPin);
    void ledOff(int ledPin);
    void ledBlink(int ledPin);
    void display(const String &line1, const String &line2);

private:
    const int potPin = A0;
    const int confirmPin = 8; // toggle button
    const int resetPin = 7;
    const int buzzerPin = 9;
    const int greenLedPin = 11;
    const int redLedPin = 10;

    bool confirmState;
    bool resetState;

    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
};