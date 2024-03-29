#include "FastMode.h"

FastMode::FastMode() {
    steps = 1;
}

void FastMode::addData(size_t newSteps, size_t number) {
    steps = newSteps;
    if (number != 3) {
        throw std::invalid_argument("Invalid strategy number");
    }
}

std::vector<std::string> FastMode::start() {
    for (size_t i = 0; i < steps; i++) {
        gameBuild.round();
    }
    gameBuild.printResultFinal();
    return(gameBuild.printWinner());
}