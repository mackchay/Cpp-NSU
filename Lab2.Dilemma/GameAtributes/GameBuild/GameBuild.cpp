#include "GameBuild.h"

GameBuild::GameBuild() {
    rounds = 0;
}

GameBuild::GameBuild(std::vector<Strategy *> &strategyList) {
    rounds = 0;
    userData = strategyList;
    gameResult.resize(userData.size());
}


void GameBuild::round(std::vector<size_t> vectorInt) {
    rounds++;

    std::string resultAct;
    std::vector<char> allActions(userData.size());
    char action;
    for (size_t i = 0; i < vectorInt.size(); i++) {
        action = userData[vectorInt[i]]->act(log);
        resultAct += action;
        allActions[i] = action;
    }

    gameResult.updateResult(resultAct, vectorInt);
    gameResult.updateCurResult(resultAct, vectorInt);

    for (size_t i = 0; i < allActions.size(); i++) {
        log.add(i, allActions[i]);
    }
}

GameBuild::VectorString GameBuild::listOfPlayers() {
    GameBuild::VectorString vectorString;
    for (auto it = userData.begin(); it != userData.end(); it++) {
        vectorString.push_back((*it)->info());
    }
    return vectorString;
}

void GameBuild::reset() {
    for (auto it = userData.begin(); it != userData.end(); it++) {
        (*it)->reset();
    }
    log = Log();
}

void GameBuild::printResult(std::vector<size_t> numbers) {
    VectorString list = listOfPlayers();
    gameResult.printMatrixOverall(list, numbers);
}

void GameBuild::printResultCur(std::vector<size_t> numbers) {
    VectorString list = listOfPlayers();
    gameResult.printMatrixCur(rounds, list, numbers);
}

void GameBuild::printLastActions(std::vector<size_t> numbers, size_t steps) {
    VectorString list = listOfPlayers();
    gameResult.printLastActions(steps, list, numbers);
}