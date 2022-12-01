#ifndef LAB2_DILEMMA_GAMERESULT_H
#define LAB2_DILEMMA_GAMERESULT_H
#include <iostream>
#include <vector>
#include "../ScoringMatrix/ScoringMatrix.h"

class GameResult {
public:

    GameResult();

    ~GameResult();

    void addToMatrix(const std::string &);
    void printMatrix();
    GameResult &getResult(ScoringMatrix &, std::string&);

    GameResult &updateResult(ScoringMatrix &, std::string&);

private:
    std::map<std::string, size_t> matrix;
};


#endif //LAB2_DILEMMA_GAMERESULT_H
