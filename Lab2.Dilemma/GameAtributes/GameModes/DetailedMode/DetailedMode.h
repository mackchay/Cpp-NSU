#ifndef LAB2_DILEMMA_DETAILEDMODE_H
#define LAB2_DILEMMA_DETAILEDMODE_H

#include "../GameMode.h"

class DetailedMode: public GameMode {
public:
    DetailedMode();
    explicit DetailedMode(size_t);
    void init(Game &) override;
    void start(Game &) override;

private:
    size_t strategyNumber;
};


#endif //LAB2_DILEMMA_DETAILEDMODE_H
