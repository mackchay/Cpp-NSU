#ifndef LAB2_DILEMMA_GAMEBUILD_H
#define LAB2_DILEMMA_GAMEBUILD_H

#include "../Factory/Factory.h"
#include "../../strategyTypes/Strategy.h"
#include "../Log/Log.h"
#include "../ScoringMatrix/ScoringMatrix.h"

class GameBuild {
public:
    GameBuild();
    GameBuild(const std::vector<Strategy*> &, const std::string &);

    void reset();
    void round(std::vector<size_t> = {0, 1, 2});
    void printResult(const std::vector<size_t>& = {0, 1, 2});
    void printResultFinal();
    void printResultCur(const std::vector<size_t>& = {0, 1, 2});
    std::vector<std::string> printWinner();

    ~GameBuild();

private:
    std::vector<Strategy*> userData;
    size_t rounds;
    ScoringMatrix scoringMatrix;
    std::vector<size_t> score;
    std::vector<size_t> scoreCur;
};


#endif
