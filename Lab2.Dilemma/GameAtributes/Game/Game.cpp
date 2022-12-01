#include "Game.h"
#include "../../strategyTypes/AlwaysCooperate/AlwaysCooperate.h"
#include "../../strategyTypes/AlwaysDefect/AlwaysDefect.h"
#include "../../strategyTypes/RandomAct/RandomAct.h"
#include "../../strategyTypes/CoopUntilDefect/CoopUntilDefect.h"
#include "../../strategyTypes/CustomAct/CustomAct.h"
#include "../../strategyTypes/RatCat/RatAct.h"

Game::Game() {
    rounds = 0;
    strategyFactory.add<AlwaysDefect>("AlwaysDefect");
    strategyFactory.add<AlwaysCooperate>("AlwaysCooperate");
    strategyFactory.add<RandomAct>("RandomAct");
    strategyFactory.add<CoopUntilDefect>("CoopUntilDefect");
    strategyFactory.add<CustomAct>("CustomAct");
    strategyFactory.add<RatAct>("RatAct");

}

Game::~Game() {
    for (auto it = userData.begin(); it != userData.end(); it++) {
        delete it->second;
    }
}


void Game::add(std::string &id) {
    if (strategyFactory.contains(id)) {
        userData[id] = strategyFactory.get(id)();
        gameResult.addToMatrix(id);
    }
    else {
        throw std::invalid_argument("Invalid argument!");
    }
}

void Game::round() {
    rounds++;
    std::string resultAct;
    std::map<std::string, char> allActions;
    char action;
    GameResult tmp;
    for (auto it = userData.begin(); it != userData.end(); it++) {
        action = it->second->act(log);
        resultAct += action;
        allActions[it->first] = action;
    }

    tmp.getResult(scoringMatrix, resultAct);
    gameResult.updateResult(scoringMatrix, resultAct);
    gameResult.updateCurResult(scoringMatrix, resultAct);

    for (auto it = allActions.begin(); it != allActions.end(); it++) {
        log.add(it->first, it->second);
    }
}

void Game::round(VectorString &vectorString) {
    rounds++;
    std::string resultAct;
    std::map<std::string, char> allActions;
    char action;
    GameResult tmp;
    for (auto it = vectorString.begin(); it != vectorString.end(); it++) {
        action = userData[*it]->act(log);
        resultAct += action;
        allActions[*it] = action;
    }

    tmp.getResult(scoringMatrix, resultAct);
    gameResult.updateResult(scoringMatrix, resultAct, vectorString);
    gameResult.updateCurResult(scoringMatrix, resultAct, vectorString);

    for (auto it = allActions.begin(); it != allActions.end(); it++) {
        log.add(it->first, it->second);
    }
}

Game::VectorString Game::listOfPlayers() {
    Game::VectorString vectorString;
    for (auto it = userData.begin(); it != userData.end(); it++) {
        vectorString.push_back(it->first);
    }
    return vectorString;
}

void Game::printResult() {
    gameResult.printMatrixOverall();
}

void Game::printResultCur() {
    gameResult.printMatrixCur(rounds);
}

void Game::printResultCur(VectorString &vectorString) {
    gameResult.printMatrixCur(rounds, vectorString);
}