#include "GameResult.h"
#include <fstream>
#define FILE "gameResult.txt"

GameResult::GameResult() = default;

GameResult::~GameResult() = default;

void GameResult::printMatrixOverall() {
    std::cout << "Overall:" << std::endl << std::endl;
    for (auto it = matrixResAll.begin(); it != matrixResAll.end(); ++it) {
        std::cout << it->first << " - " << it->second << std::endl;
    }
    std::cout << std::endl;
}

void GameResult::printMatrixCur(size_t rounds) {
    std::cout << "Round " << rounds << ":" << std::endl << std::endl;
    for (auto it = matrixResCur.begin(); it != matrixResCur.end(); ++it) {
        std::cout << it->first << " - " << it->second.back() << std::endl;
    }
    std::cout << std::endl;
}

void GameResult::printMatrixCur(size_t rounds, std::vector<std::string> &strategyList) {
    std::cout << "Round " << rounds << ":" << std::endl << std::endl;
    for (auto it = strategyList.begin(); it != strategyList.end(); ++it) {
        std::cout << *it << " - " << matrixResCur[*it].back() << std::endl;
    }
    std::cout << std::endl;
}

void GameResult::addToMatrix(const std::string &strategyName) {
    matrixResAll.insert(std::make_pair(strategyName, 0));
    matrixResCur.insert(std::make_pair(strategyName, 0));
}

GameResult &GameResult::getResult(ScoringMatrix &score, std::string &id) {
    size_t i = 0;
    for (auto it = matrixResAll.begin(); it != matrixResAll.end(); ++it) {
        it->second = score.getScore(id, i);
        i++;
    }
    return (*this);
}

GameResult &GameResult::updateResult(ScoringMatrix &score, std::string &id) {
    size_t i = 0;
    for (auto it = matrixResAll.begin(); it != matrixResAll.end(); ++it) {
         it->second += score.getScore(id, i);
         i++;
     }
     return (*this);
}

GameResult &GameResult::updateCurResult(ScoringMatrix &score, std::string &id) {
    size_t i = 0;
    for (auto it = matrixResCur.begin(); it != matrixResCur.end(); ++it) {
        it->second.push_back(score.getScore(id, i));
        i++;
    }
    return (*this);
}

GameResult &GameResult::updateResult(ScoringMatrix &score, std::string &id,
                                     std::vector<std::string> &strategyList) {
    size_t i = 0;
    for (auto it = strategyList.begin(); it != strategyList.end(); it++) {
        matrixResAll[*it] += score.getScore(id, i);
        i++;
    }
    return (*this);
}

GameResult &GameResult::updateCurResult(ScoringMatrix &score, std::string &id,
                                        std::vector<std::string> &strategyList) {
    size_t i = 0;
    for (auto it = strategyList.begin(); it != strategyList.end(); it++) {
        matrixResCur[*it].push_back(score.getScore(id, i));
        i++;
    }
    return (*this);
}

