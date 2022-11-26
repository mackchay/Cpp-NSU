#include "GameResult.h"
#include <fstream>
#define FILE "gameResult.txt"

GameResult::GameResult() = default;

GameResult::~GameResult() = default;

void GameResult::printMatrix() {
    for (auto it = matrix.begin(); it != matrix.end(); ++it) {
        std::cout << it->first << " - " << it->second << std::endl;
    }
}

void GameResult::addToMatrix(const std::string &strategyName) {
    matrix.insert(std::make_pair(strategyName, 0));
}

size_t GameResult::getMatrixSize() const{
    return matrixSize;
}

GameResult &GameResult::getResult(ScoringMatrix &score, std::string &id) {
    size_t i = 0;
    for (auto it = matrix.begin(); it != matrix.end(); ++it) {
        it->second = score.getScore(id, i);
        i++;
    }
    return (*this);
}

GameResult &GameResult::updateResult(ScoringMatrix &score, std::string &id) {
    size_t i = 0;
    for (auto it = matrix.begin(); it != matrix.end(); ++it) {
         it->second += score.getScore(id, i);
         i++;
     }
     return (*this);
}