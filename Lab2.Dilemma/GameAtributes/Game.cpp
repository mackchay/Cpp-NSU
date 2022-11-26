#include "Game.h"
#include "../strategyTypes/AlwaysCooperate.h"
#include "../strategyTypes/AlwaysDefect.h"
#include "../strategyTypes/RandomAct.h"
#include "../strategyTypes/CoopUntilDefect.h"
#include "../strategyTypes/CustomAct.h"

Game::Game() {
    strategyFactory.add<AlwaysDefect>("AlwaysDefect");
    strategyFactory.add<AlwaysCooperate>("AlwaysCooperate");
    strategyFactory.add<RandomAct>("RandomAct");
    strategyFactory.add<CoopUntilDefect>("CoopUntilDefect");
    strategyFactory.add<CustomAct>("CustomAct");

}

Game::~Game() {
    for (auto it = userData.begin(); it != userData.end(); it++) {
        delete it->second;
    }
}

void Game::add(std::string &id) {
    if (strategyFactory.isStrategy(id)) {
        userData[id] = strategyFactory.get(id)();
        gameResult.addToMatrix(id);
    }
    else {
        throw std::invalid_argument("Invalid argument!");
    }
}

void Game::round() {
    std::string resultAct;
    char action;
    GameResult tmp;
    for (auto it = userData.begin(); it != userData.end(); it++) {
        action = it->second->act(log);
        resultAct += action;
        log.add(it->first, action);
    }

    tmp.getResult(scoringMatrix, resultAct);
    gameResult.updateResult(scoringMatrix, resultAct);
    gameResult.printMatrix();
}