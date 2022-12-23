#ifndef LAB2_DILEMMA_DETAILEDMODE_H
#define LAB2_DILEMMA_DETAILEDMODE_H

#include "../GameMode/GameMode.h"

class DetailedMode: public GameMode {
public:

    void addData(size_t, size_t) override;
    std::vector<std::string> start() override;

private:
    const size_t strategyNumber = 3;
};


#endif //LAB2_DILEMMA_DETAILEDMODE_H
