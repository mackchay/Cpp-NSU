#ifndef LAB2_DILEMMA_FASTMODE_H
#define LAB2_DILEMMA_FASTMODE_H

#include "GameMode.h"

class FastMode : public GameMode {
public:
    FastMode();
    void init(Game ) override;
    void start() override;

private:
    size_t steps;
    const size_t strategyNumber = 3;
    GamePtr gamePtr;
};


#endif //LAB2_DILEMMA_FASTMODE_H
