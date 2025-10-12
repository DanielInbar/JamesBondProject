#pragma once
#include "hardware.h"
#include "Buzzer.h"

enum GameState {
    WAITING,
    LOCKING,
    SUCCESS,
    FAIL,
    DISARMED
};

class Game {
public:
    Game(Hardware &hw);
    void begin();
    void update();

private:
    Hardware &hardware;
    GameState state;
    int targetValue;
    int roundCount;
    unsigned long lastUpdate;
    Buzzer buzzer;

    void startRound();
    void checkLock();
    void endRound(bool success);
    void resetGame();
};
