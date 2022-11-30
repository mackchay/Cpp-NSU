#include "DetailedMode.h"

DetailedMode::DetailedMode() {
    strategyNumber = 3;
}

DetailedMode::DetailedMode(size_t defaultSize) {
    strategyNumber = defaultSize;
}

void DetailedMode::init(Game game) {
    gamePtr.reset(&game);
    std::string strategyName;
    for (size_t i = 0; i < strategyNumber; i++) {
        std::cin >> strategyName;
        gamePtr->add(strategyName);
    }
}

void DetailedMode::start() {
    std::string enter = "0";
    while (enter != "q") {
        gamePtr->round();
        gamePtr->printResult();
        std::cin >> enter;
    }
}