#include "FastMode.h"

FastMode::FastMode() {
    steps = 1;
}

void FastMode::addData(size_t newSteps, size_t) {
    steps = newSteps;
}

void FastMode::start(GameBuild &game) {
    for (size_t i = 0; i < steps; i++) {
        game.round();
    }
    game.printResult();
}