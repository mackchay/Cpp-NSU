#ifndef LAB2_DILEMMA_ALWAYSCOOPERATE_H
#define LAB2_DILEMMA_ALWAYSCOOPERATE_H

#include "Strategy.h"

class AlwaysCooperate : public Strategy {
    void info() override;
    char act() override;
};


#endif //LAB2_DILEMMA_ALWAYSCOOPERATE_H
