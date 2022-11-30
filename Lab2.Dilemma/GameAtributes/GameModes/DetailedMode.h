#ifndef LAB2_DILEMMA_DETAILEDMODE_H
#define LAB2_DILEMMA_DETAILEDMODE_H

#include "GameMode.h"

class DetailedMode: public GameMode {
public:
    DetailedMode();
    DetailedMode(size_t);
    void init(Game ) override;
    void start() override;

private:
    size_t strategyNumber;
    GamePtr gamePtr;
};


#endif //LAB2_DILEMMA_DETAILEDMODE_H
