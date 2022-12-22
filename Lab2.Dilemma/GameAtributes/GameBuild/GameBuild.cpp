#include "GameBuild.h"
#include <fstream>

GameBuild::GameBuild() {
    rounds = 0;
}

GameBuild::GameBuild(const std::vector<Strategy *> &strategyList, const std::string &matrix)
: userData(strategyList), rounds(0) {

    for (size_t i = 0; i < strategyList.size(); i++) {
        score.push_back(0);
    }

    try {
        scoringMatrix = ScoringMatrix(matrix);
    }
    catch (const std::ifstream::failure &e) {
        if (matrix.empty()) {
            std::cout << "Can't opened matrix file." << std::endl;
        }
        scoringMatrix = ScoringMatrix();
    }
    catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
            scoringMatrix = ScoringMatrix();
    }
}


 void GameBuild::round(std::vector<size_t> vectorInt) {
    rounds++;
    std::string allActions, opponentActs;
    char action;
    for (size_t i = 0; i < vectorInt.size(); i++) {
        action = userData[vectorInt[i]]->act();
        allActions.push_back(action);
    }


    for (size_t i = 0; i < allActions.size(); i++) {
        opponentActs = allActions.substr(0, i) +
                allActions.substr(i, allActions.size() - i);
        userData[vectorInt[i]]->setOpponentActs(opponentActs);
        score[vectorInt[i]] += scoringMatrix.getScore(allActions, i);
        userData[vectorInt[i]]->setPoints(scoringMatrix.getScore(allActions, i));
    }
}

void GameBuild::reset() {
    for (auto it = userData.begin(); it != userData.end(); it++) {
        (*it)->reset();
    }
}

void GameBuild::printResult(const std::vector<size_t> &numbers) {
    std::cout << "Round " << rounds << ":" << std::endl;
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << userData[numbers[i]]->info() << " - "
        << userData[numbers[i]]->getPoints() << std::endl;
    }

    std::cout << std::endl;
}

void GameBuild::printResultCur(const std::vector<size_t>& numbers) {
    std::cout << "Round " << rounds << ":" << std::endl;
    for (size_t i = 0; i < numbers.size(); i++) {
        std::cout << userData[numbers[i]]->info() << " - "
        << scoreCur[i] << std::endl;
    }
    std::cout << std::endl;
}

void GameBuild::printWinner() {
    size_t max = 0;
    std::vector<std::string> strategyList;
    for (size_t i = 0; i < score.size(); i++) {
        if (score[i] == max) {
            strategyList.push_back(userData[i]->info());
        }
        else if (score[i] > max) {
            strategyList.clear();
            strategyList.push_back(userData[i]->info());
            max = score[i];
        }
    }

    if (strategyList.size() < 2) {
        std::cout << "Winner is " << strategyList[0] << std::endl;
    }
    else {
        std::cout << "Winners are: " << std::endl;
        for (size_t i = 0; i < strategyList.size(); i++) {
            std::cout << strategyList[i] << " ";
        }
        std::cout << std::endl;
    }
}

void GameBuild::printResultFinal() {
    std::cout << "Overall:" << std::endl;
    for (size_t i = 0; i < score.size(); i++) {
        std::cout << userData[i]->info() << " - "
                  << score[i] << std::endl;
    }
    std::cout << std::endl;
}

GameBuild::~GameBuild() = default;