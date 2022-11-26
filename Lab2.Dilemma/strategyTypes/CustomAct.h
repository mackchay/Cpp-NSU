#ifndef LAB2_DILEMMA_CUSTOMACT_H
#define LAB2_DILEMMA_CUSTOMACT_H

#include "Strategy.h"

class CustomAct: public Strategy {
public:
    CustomAct();
    std::string info() override;
    char act(Log &) override;

private:
    std::vector<char> instructions;
    int countCoop;
    int countDefect;
};


#endif //LAB2_DILEMMA_CUSTOMACT_H
