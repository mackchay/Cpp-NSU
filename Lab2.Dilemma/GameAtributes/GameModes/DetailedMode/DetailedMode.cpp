#include "DetailedMode.h"


void DetailedMode::addData(size_t newSteps, size_t number) {
    if (number != 3) {
        throw std::invalid_argument("Invalid strategy number");
    }
}

void DetailedMode::start(GameBuild &game) {
    std::string enter = "0";
    while (enter != "q") {
        game.round();
        game.printResultCur();
        game.printResultFinal();
        std::cin >> enter;
    }
    game.printWinner();
}