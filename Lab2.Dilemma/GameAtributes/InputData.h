#ifndef LAB2_DILEMMA_INPUTDATA_H
#define LAB2_DILEMMA_INPUTDATA_H
#include <iostream>
#include "../strategyTypes/Strategy.h"


class InputData {
public:
    InputData();

private:
    Matrix matrix;
    StrategyFactory <std::string, Strategy> *list;
};


#endif //LAB2_DILEMMA_INPUTDATA_H
