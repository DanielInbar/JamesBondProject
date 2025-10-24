#include "game.h"
#include "Constant.h"

Game::Game(Hardware &hw)
    : hardware(hw), state(WAITING), targetValue(0), roundCount(0), lastUpdate(0), buzzer(9), timer(15) {}

void Game::begin() {
    hardware.display("Bond Bomb", "Press Toggle!");
    buzzer.init();
    
}

void Game::update() {
    hardware.updateInputs();
    buzzer.update();

    if (hardware.isResetPressed()) {
        resetGame();
        return;
    }

    switch (state) {
        case WAITING:
            if (hardware.isConfirmPressed()) {
                hardware.display("Armed!", "Find code...");
                hardware.ledOn();
                delay(800);
                startRound();
            }
            break;

        case LOCKING:
            checkLock();
            break;

        case SUCCESS:
        case FAIL:
        case DISARMED:
            // wait for reset
            break;
    }
}

void Game::startRound() {
    timer.start();
    targetValue = random(200, 900); // new "code"
    state = LOCKING;
    hardware.display("Turn Dial...", " ");
    lastUpdate = millis();
}

void Game::checkLock() {
    int potVal = hardware.getPotValue();
    int tolerance = 40;

    // Show proximity bar every ~100ms
    if (millis() - lastUpdate > 100) {
        lastUpdate = millis();

        int diff = abs(potVal - targetValue);
        int strength = map(diff, 0, 512, 10, 0); // closer = more bars (10 max)
        if (strength < 0) strength = 0;
        if (strength > 10) strength = 10;

        String bar = "[";
        for (int i = 0; i < strength; i++) bar += "#";
        for (int i = strength; i < 10; i++) bar += "-";
        bar += "]";

        hardware.display("Dial Lock... ", bar);
        Serial.println(timer.calcTime());
    }

    if (hardware.isConfirmPressed()) {
        if (abs(potVal - targetValue) <= tolerance) {
            roundCount++;
            hardware.buzzerBeep(120);
            if (roundCount >= 3) {
                state = DISARMED;
                hardware.ledOff();
                hardware.display("💣 DISARMED 💣", "Bond Wins!");
                buzzer.playMelody(Constants::morningMoodMelody, Constants::morningMoodDurations, Constants::morningMoodSizeOfDurations);
            } else {
                hardware.display("✅ Success!", "Next lock...");
                delay(1000);
                startRound();
            }
        } else {
            endRound(false);
        }
    }

    if (timer.calcTime() == 15000) {
        endRound(false);
    }
}

void Game::endRound(bool success) {
    if (success) {
        state = SUCCESS;
        hardware.display("Success!", "Next round...");
        delay(1000);
        startRound();
    } else {
        state = FAIL;
        hardware.ledOff();
        hardware.display("💥 BOOM! 💥", "Press Reset");
        hardware.display("INVADE POLAND", "NOWWW!!!");
        buzzer.playMelody(Constants::erikaMelody, Constants::erikaDurations, Constants::erikaSizeOfDurations);


    }
}

void Game::resetGame() {
    state = WAITING;
    roundCount = 0;
    hardware.ledOff();
    hardware.display("Bond Bomb", "Press Toggle!");
    buzzer.stopMelody();
}