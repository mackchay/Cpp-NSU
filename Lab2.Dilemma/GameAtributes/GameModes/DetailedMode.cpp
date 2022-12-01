#include "DetailedMode.h"

DetailedMode::DetailedMode() {
    strategyNumber = 3;
}

DetailedMode::DetailedMode(size_t defaultSize) {
    strategyNumber = defaultSize;
}

void DetailedMode::init(Game &game) {
    std::string strategyName;
    for (size_t i = 0; i < strategyNumber; i++) {
        std::cin >> strategyName;
        game.add(strategyName);
    }
}

void DetailedMode::start(Game &game) {
    std::string enter = "0";
    while (enter != "q") {
        game.round();
        game.printResult();
        std::cin >> enter;
    }
}