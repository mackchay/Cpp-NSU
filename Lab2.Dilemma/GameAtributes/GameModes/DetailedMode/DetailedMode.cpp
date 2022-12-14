#include "DetailedMode.h"


void DetailedMode::addData(size_t, size_t) {

}

void DetailedMode::start(GameBuild &game) {
    std::string enter = "0";
    while (enter != "q") {
        game.round();
        game.printResultCur();
        game.printResult();
        std::cin >> enter;
    }
    game.printResult();
}