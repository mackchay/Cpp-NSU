#include "Game.h"
#include "../GameModes/DetailedMode/DetailedMode.h"

Game::Game(InputData inputData) {

    gameBuild = GameBuild(inputData.getStrategyList(), inputData.getMatrix());
    strategyList = inputData.getStrategyList();
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