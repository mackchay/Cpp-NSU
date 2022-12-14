#ifndef LAB2_DILEMMA_GAMEBUILD_H
#define LAB2_DILEMMA_GAMEBUILD_H
#include "../GameResult/GameResult.h"
#include "../Factory/Factory.h"
#include "../../strategyTypes/Strategy.h"
#include "../Log/Log.h"

class GameBuild {
public:
    typedef std::vector<std::string> VectorString;
    GameBuild();
    explicit GameBuild(std::vector<Strategy*> &);

    void reset();
    void round(std::vector<size_t> = {0, 1, 2});
    void printResult(std::vector<size_t> = {0, 1, 2});
    void printLastActions(std::vector<size_t> = {0, 1, 2}, size_t = 1);
    void printResultCur(std::vector<size_t> numbers = {0, 1, 2});
    VectorString listOfPlayers();

private:
    GameResult gameResult;
    std::vector<Strategy*> userData;
    Log log;
    size_t rounds;

};


#endif
