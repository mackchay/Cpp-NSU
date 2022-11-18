#ifndef LAB2_DILEMMA_GAMERESULT_H
#define LAB2_DILEMMA_GAMERESULT_H
#include <iostream>
#include <vector>
#include "ScoringMatrix.h"

class GameResult {
public:

    GameResult();

    ~GameResult();

    void readMatrix();
    void printMatrix();
    size_t getMatrixSize() const;
    void updateResult(ScoringMatrix &, std::string&);

private:
    const size_t matrixSize;
    std::vector<int> matrix;
};


#endif //LAB2_DILEMMA_GAMERESULT_H
