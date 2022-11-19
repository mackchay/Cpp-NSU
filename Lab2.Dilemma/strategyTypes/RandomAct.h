#ifndef LAB2_DILEMMA_RANDOMACT_H
#define LAB2_DILEMMA_RANDOMACT_H

#include "Strategy.h"

class RandomAct: public Strategy {
    void info() override;
    char act() override;
};

#endif
