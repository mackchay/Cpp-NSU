#ifndef LAB2_DILEMMA_INPUTDATA_H
#define LAB2_DILEMMA_INPUTDATA_H
#include <iostream>
#include "../strategyTypes/Strategy.h"
#include "StrategyFactory.h"


class InputData {
public:
    InputData();


private:
    StrategyFactory<std::string, Strategy> strategyFactory;
};


#endif //LAB2_DILEMMA_INPUTDATA_H
