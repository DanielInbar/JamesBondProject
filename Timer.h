#pragma once
#include <Arduino.h>

class Timer {
public:
    Timer(int seconds);
    void reset();
    void start();
    long calcTime();

    bool isRunning() const { return running; }
    bool isFinished() const { return finished; }

private:
    int seconds;
    bool running;
    bool finished;
    unsigned long startMillis;
};
