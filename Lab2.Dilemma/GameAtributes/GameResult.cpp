#include "GameResult.h"
#include <fstream>
#define FILE "gameResult.txt"

GameResult::GameResult() {
    //matrixSize;
    matrix = {0,0,0};
}

GameResult::~GameResult() = default;

void GameResult::printMatrix() {
    std::ofstream f;
    f.open(FILE);
    for (auto it = matrix.begin(); it != matrix.end(); ++it) {
        f << *it << " ";
    }
    f.close();
}

void GameResult::readMatrix() {
    std::ifstream f;
    f.open(FILE);
    for (int i = 0; i < matrixSize; i++) {
        f >> this->matrix[i];
    }
    f.close();
}

size_t GameResult::getMatrixSize() const{
    return matrixSize;
}

void GameResult::updateResult(ScoringMatrix &score, std::string &id) {
     for (size_t i = 0; i < matrixSize; i++) {
         matrix[i] = score.getScore(id, i);
     }
}