#include "Game.h"
#include "../GameModes/DetailedMode/DetailedMode.h"

Game::Game() {
    mode = new DetailedMode();
}

Game::~Game() {
    delete mode;
    for (auto it = strategyList.begin(); it < strategyList.end(); it++) {
        delete *it;
    }
}

size_t Game::addStrategy(Strategy* strategy) {
    strategyList.push_back(strategy);
    strategy->setIndex(strategyList.size() - 1);
    return strategyList.size();
}

void Game::setMode(GameMode* gameMode) {
    delete mode;
    mode = gameMode;
}

void Game::run() {
    GameBuild gameBuild(strategyList);
    mode->start(gameBuild);
}