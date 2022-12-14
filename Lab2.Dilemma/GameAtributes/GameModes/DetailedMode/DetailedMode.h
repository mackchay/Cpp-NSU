#ifndef LAB2_DILEMMA_DETAILEDMODE_H
#define LAB2_DILEMMA_DETAILEDMODE_H

#include "../GameMode.h"

class DetailedMode: public GameMode {
public:

    void addData(size_t, size_t) override;
    void start(GameBuild &) override;

private:
    const size_t strategyNumber = 3;
};


#endif //LAB2_DILEMMA_DETAILEDMODE_H
