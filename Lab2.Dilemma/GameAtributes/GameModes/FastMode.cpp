#include "FastMode.h"

FastMode::FastMode() {
    std::cin >> steps;
}

void FastMode::init(Game game) {
    this -> gamePtr.reset(&game);
    std::string strategyName;
    for (size_t i = 0; i < strategyNumber; i++) {
        std::cin >> strategyName;
        gamePtr->add(strategyName);
    }
}

void FastMode::start() {
    for (size_t i = 0; i < steps; i++) {
        gamePtr->round();
    }
    gamePtr->printResult();
}