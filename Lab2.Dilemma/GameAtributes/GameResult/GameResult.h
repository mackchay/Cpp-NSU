#ifndef LAB2_DILEMMA_GAMERESULT_H
#define LAB2_DILEMMA_GAMERESULT_H
#include <iostream>
#include <vector>
#include "../ScoringMatrix/ScoringMatrix.h"

class GameResult {
public:

    GameResult();

    ~GameResult();

    void resize(size_t);

    void printMatrixOverall(std::vector<std::string> &, std::vector<size_t> &);

    void printMatrixCur(size_t, std::vector<std::string> &, std::vector<size_t> &);

    void printLastActions(size_t, std::vector<std::string> &, std::vector<size_t> &);

    GameResult &updateResult(std::string &, std::vector<size_t> &);

    GameResult &updateCurResult(std::string &, std::vector<size_t> &);

private:
    std::vector<size_t> matrixResAll;
    std::vector<std::vector<size_t>> matrixResCur;
    ScoringMatrix scoringMatrix;
};


#endif //LAB2_DILEMMA_GAMERESULT_H
