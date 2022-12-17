#include "GameBuild.h"

GameBuild::GameBuild() {
    rounds = 0;
}

GameBuild::GameBuild(const std::vector<Strategy *> &strategyList, const ScoringMatrix &matrix) {
    rounds = 0;
    userData = strategyList;
    scoringMatrix = matrix;
    for (size_t i = 0; i < strategyList.size(); i++) {
        result.push_back(0);
    }
}


 void GameBuild::round(std::vector<size_t> vectorInt) {
    rounds++;
    std::string allActions;
    char action;
    for (size_t i = 0; i < vectorInt.size(); i++) {
        userData[vectorInt[i]]->setIndex(i);
        action = userData[vectorInt[i]]->act(log);
        allActions.push_back(action);
    }
    log.add(allActions);

    for (size_t i = 0; i < allActions.size(); i++) {
        result[vectorInt[i]] += scoringMatrix.getScore(allActions, i);
        userData[vectorInt[i]]->setPoints(scoringMatrix.getScore(allActions, i));
    }
}

void GameBuild::reset() {
    for (auto it = userData.begin(); it != userData.end(); it++) {
        (*it)->reset();
    }
    log = Log();

}

void GameBuild::printResult(const std::vector<size_t> &numbers) {
    std::cout << "Round " << rounds << ":" << std::endl;
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << userData[numbers[i]]->info() << " - " << userData[numbers[i]]->getPoints() << std::endl;
    }

    std::cout << std::endl;
}

void GameBuild::printResultCur(const std::vector<size_t>& numbers) {
    std::cout << "Round " << rounds << ":" << std::endl;
    for (size_t i = 0; i < numbers.size(); i++) {
        std::string lastActions = log.lastRound();
        std::cout << userData[numbers[i]]->info() << " - "
        << scoringMatrix.getScore(lastActions, i) << std::endl;
    }
    std::cout << std::endl;
}

void GameBuild::printWinner() {
    size_t max = 0;
    std::vector<std::string> strategyList;
    for (size_t i = 0; i < result.size(); i++) {
        if (result[i] == max) {
            strategyList.push_back(userData[i]->info());
        }
        else if (result[i] > max) {
            strategyList.clear();
            strategyList.push_back(userData[i]->info());
            max = result[i];
        }
    }

    if (strategyList.size() < 2) {
        std::cout << "Winner is " << strategyList[0] << std::endl;
    }
    else {
        std::cout << "Winners are: " << std::endl;
        for (size_t i = 0; i < strategyList.size(); i++) {
            std::cout << userData[i]->info() << " ";
        }
        std::cout << std::endl;
    }
}

void GameBuild::printResultFinal() {
    std::cout << "Overall:" << std::endl;
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << userData[i]->info() << " - "
        << result[i] << std::endl;
    }
    std::cout << std::endl;
}

GameBuild::~GameBuild() {

}