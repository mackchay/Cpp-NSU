#ifndef LAB2_DILEMMA_GAME_H
#define LAB2_DILEMMA_GAME_H
#include "GameResult.h"
#include "StrategyFactory.h"
#include "../strategyTypes/Strategy.h"
#include "InputData.h"

class Game {
public:
    Game();
    void add(std::string &);
    void round();

private:
    StrategyFactory<std::string, Strategy> strategyFactory;
    ScoringMatrix scoringMatrix;
    GameResult gameResult;
    std::map<std::string, Strategy*> userData;
};


#endif //LAB2_DILEMMA_GAME_H
