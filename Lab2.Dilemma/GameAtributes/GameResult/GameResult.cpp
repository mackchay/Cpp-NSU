#include "GameResult.h"
#include <fstream>

GameResult::GameResult() = default;

GameResult::~GameResult() = default;

void GameResult::resize(size_t size) {
    for (size_t i = matrixResAll.size(); i < size; i++) {
        matrixResAll.push_back(0);
        matrixResCur.push_back({0});
    }
}

void GameResult::printMatrixOverall(std::vector<std::string> &strategyList, std::vector<size_t> &numbers) {
    std::cout << "Overall:" << std::endl;
    for (size_t i = 0; i < numbers.size() && i < matrixResAll.size(); ++i) {
        std::cout << numbers[i] + 1 << ". " << strategyList[numbers[i]] << " - " << matrixResAll[i]
                  << std::endl;
    }
    std::cout << std::endl;
}

void GameResult::printMatrixCur(size_t rounds, std::vector<std::string> &strategyList,
                                std::vector<size_t> &numbers) {
    std::cout << "Round " << rounds << ":" << std::endl;
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] + 1 << ". " << strategyList[numbers[i]] << " - "
                  << matrixResCur[numbers[i]].back() << std::endl;
    }
    std::cout << std::endl;
}


GameResult &GameResult::updateResult(std::string &id,
                                     std::vector<size_t> &strategyList) {

    for (size_t i = 0; i < strategyList.size(); i++) {
        matrixResAll[strategyList[i]] += scoringMatrix.getScore(id, i);
    }
    return (*this);
}

GameResult &GameResult::updateCurResult(std::string &id,
                                        std::vector<size_t> &strategyList) {
    for (size_t i = 0; i < strategyList.size(); i++) {
        matrixResCur[strategyList[i]].push_back(scoringMatrix.getScore(id, i));
    }
    return (*this);
}

void GameResult::printLastActions(size_t steps, std::vector<std::string> &strategyList,
                                  std::vector<size_t> &numbers) {
    std::vector<size_t> lastActions;
    size_t size;
    for (size_t j = 0; j < numbers.size(); ++j) {
        lastActions.push_back(0);
        size = matrixResCur[numbers[j]].size();
        for (size_t i = 0; i < steps; ++i) {
            lastActions[j] += matrixResCur[numbers[j]][size - i - 1];
        }
    }

    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] + 1 << ". " << strategyList[numbers[i]] << " - "
                  << lastActions[i] << std::endl;
    }
    std::cout << std::endl;
}