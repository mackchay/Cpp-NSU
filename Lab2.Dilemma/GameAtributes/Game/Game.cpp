#include "Game.h"
#include "../GameModes/DetailedMode/DetailedMode.h"

Game::Game(InputData inputData) {
    strategyList = inputData.getStrategyList();
    gameBuild = GameBuild(strategyList, inputData.getMatrix());
    mode = inputData.getGameMode();
}

void Game::run() {
    mode->start(gameBuild);
}

Game::~Game() {
    for (auto it = strategyList.begin(); it < strategyList.end(); it++) {
        delete *it;
    }
}