#include "Game.h"
#include "../GameModes/DetailedMode/DetailedMode.h"

Game::Game(InputData inputData) {

    strategyList = inputData.getStrategyList();
    mode = inputData.getGameMode();
    mode->initGameBuild(inputData.getStrategyList(), inputData.getMatrix());
}

std::vector<std::string> Game::run() {
    return mode->start();
}

Game::~Game() {
    for (auto it = strategyList.begin(); it < strategyList.end(); it++) {
        delete *it;
    }
}