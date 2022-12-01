#include "FastMode.h"

FastMode::FastMode() {
    std::cin >> steps;
}

void FastMode::init(Game &game) {
    std::string strategyName;
    for (size_t i = 0; i < strategyNumber; i++) {
        std::cin >> strategyName;
        game.add(strategyName);
    }
}

void FastMode::start(Game &game) {
    for (size_t i = 0; i < steps; i++) {
        game.round();
    }
    game.printResult();
}