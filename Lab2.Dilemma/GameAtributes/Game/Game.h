#ifndef LAB2_DILEMMA_GAME_H
#define LAB2_DILEMMA_GAME_H
#include "../GameResult/GameResult.h"
#include "../Factory/Factory.h"
#include "../../strategyTypes/Strategy.h"
#include "../Log/Log.h"

class Game {
public:
    typedef std::vector<std::string> VectorString;
    Game();

    void add(std::string &);
    void round();
    void round(VectorString &);
    void printResult();
    VectorString listOfPlayers();
    ~Game();

private:
    Factory<std::string, Strategy> strategyFactory;
    ScoringMatrix scoringMatrix;
    GameResult gameResult;
    std::map<std::string, Strategy*> userData;
    Log log;
};


#endif
