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
    void ledOn();
    void ledOff();
    void display(const String &line1, const String &line2);

private:
    const int potPin = A0;
    const int confirmPin = 8; // toggle button
    const int resetPin = 7;
    const int buzzerPin = 9;
    const int ledPin = 10;

    bool confirmState;
    bool resetState;

    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
};