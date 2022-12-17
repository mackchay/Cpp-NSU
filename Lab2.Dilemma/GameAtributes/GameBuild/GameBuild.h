#ifndef LAB2_DILEMMA_GAMEBUILD_H
#define LAB2_DILEMMA_GAMEBUILD_H

#include "../Factory/Factory.h"
#include "../../strategyTypes/Strategy.h"
#include "../Log/Log.h"
#include "../ScoringMatrix/ScoringMatrix.h"

class GameBuild {
public:
    typedef std::vector<std::string> VectorString;
    GameBuild();
    GameBuild(const std::vector<Strategy*> &, const ScoringMatrix &);

    void reset();
    void round(std::vector<size_t> = {0, 1, 2});
    void printResult(const std::vector<size_t>& = {0, 1, 2});
    void printResultFinal();
    void printResultCur(const std::vector<size_t>& = {0, 1, 2});
    void printWinner();

    ~GameBuild();

private:
    std::vector<Strategy*> userData;
    Log log;
    size_t rounds;
    ScoringMatrix scoringMatrix;
    std::vector<size_t> result;
};


#endif
