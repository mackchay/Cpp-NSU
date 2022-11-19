#include "Game.h"
#include "../strategyTypes/AlwaysCooperate.h"
#include "../strategyTypes/AlwaysDistrust.h"
#include "../strategyTypes/RandomAct.h"

Game::Game() {
    strategyFactory.add<AlwaysDistrust>("AlwaysDistrust");
    strategyFactory.add<AlwaysCooperate>("AlwaysCooperate");
    strategyFactory.add<RandomAct>("RandomAct");

}

void Game::add(std::string &id) {
    userData[id] = strategyFactory.get(id)();
}

void Game::round() {
    std::string resultAct;
    for (auto it = userData.begin(); it != userData.end(); it++) {
        resultAct += it->second->act();
    }
    gameResult.updateResult(scoringMatrix, resultAct);
    gameResult.printMatrix();
}