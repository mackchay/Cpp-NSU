#include "Game.h"
#include "../GameModes/DetailedMode/DetailedMode.h"

Game::Game(InputData inputData) {
    strategyList = inputData.getStrategyList();
    mode = inputData.getGameMode();
    mode->addData(inputData.getSteps(), strategyList.size());
}

Game::~Game() {
    for (auto it = strategyList.begin(); it < strategyList.end(); it++) {
        delete *it;
    }
}

void Game::run() {
    GameBuild gameBuild(strategyList);
    mode->start(gameBuild);
}