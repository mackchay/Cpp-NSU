#ifndef LAB2_DILEMMA_FASTMODE_H
#define LAB2_DILEMMA_FASTMODE_H

#include "../GameMode.h"

class FastMode : public GameMode {
public:
    FastMode();
    void addData(size_t, size_t) override;
    void start(GameBuild &) override;

private:
    size_t steps;
    const size_t strategyNumber = 3;
};


#endif //LAB2_DILEMMA_FASTMODE_H
