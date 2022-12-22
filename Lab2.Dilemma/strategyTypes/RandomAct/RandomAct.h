#ifndef LAB2_DILEMMA_RANDOMACT_H
#define LAB2_DILEMMA_RANDOMACT_H

#include "../Strategy.h"

class RandomAct: public Strategy {
public:

    std::string info() override;
    char act() override;
    void reset() override;
};

#endif
