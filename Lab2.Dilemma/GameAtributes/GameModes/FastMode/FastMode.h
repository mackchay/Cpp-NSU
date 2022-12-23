#ifndef LAB2_DILEMMA_FASTMODE_H
#define LAB2_DILEMMA_FASTMODE_H

#include "../GameMode/GameMode.h"

class FastMode : public GameMode {
public:
    FastMode();
    void addData(size_t, size_t) override;
    std::vector<std::string> start() override;

private:
    size_t steps;
    const size_t strategyNumber = 3;
};


#endif //LAB2_DILEMMA_FASTMODE_H
