#include "hardware.h"
#include "game.h"

Hardware hardware;
Game game(hardware);

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(0));
    hardware.begin();
    game.begin();
}

void loop() {
    game.update();
}
