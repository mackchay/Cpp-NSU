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
    void printMatrixOverall();
    void printMatrixCur(size_t);
    void printMatrixCur(size_t, std::vector<std::string> &);

    GameResult &getResult(ScoringMatrix &, std::string&);

    GameResult &updateResult(ScoringMatrix &, std::string&);
    GameResult &updateResult(ScoringMatrix &, std::string &, std::vector<std::string> &);

    GameResult &updateCurResult(ScoringMatrix &, std::string&);
    GameResult &updateCurResult(ScoringMatrix &, std::string &, std::vector<std::string> &);

private:
    std::map<std::string, size_t> matrixResAll;
    std::map<std::string, std::vector<size_t>> matrixResCur;
};


#endif //LAB2_DILEMMA_GAMERESULT_H
