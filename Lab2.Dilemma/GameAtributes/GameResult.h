#ifndef LAB2_DILEMMA_GAMERESULT_H
#define LAB2_DILEMMA_GAMERESULT_H
#include <iostream>
#include <vector>
#include "ScoringMatrix.h"

class GameResult {
public:

    GameResult();

    ~GameResult();

    void addToMatrix(const std::string &);
    void printMatrix();
    size_t getMatrixSize() const;
    GameResult &getResult(ScoringMatrix &, std::string&);

    GameResult &updateResult(ScoringMatrix &, std::string&);

private:
    const size_t matrixSize = 3;
    std::map<std::string, size_t> matrix;
};


#endif //LAB2_DILEMMA_GAMERESULT_H
