#ifndef LAB2_DILEMMA_ALWAYSDISTRUST_H
#define LAB2_DILEMMA_ALWAYSDISTRUST_H

#include "Strategy.h"

class AlwaysDistrust: public Strategy {
    void info() override;
    char act() override;
};


#endif //LAB2_DILEMMA_ALWAYSDISTRUST_H
