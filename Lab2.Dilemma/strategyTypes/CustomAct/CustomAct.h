#ifndef LAB2_DILEMMA_CUSTOMACT_H
#define LAB2_DILEMMA_CUSTOMACT_H

#include "../Strategy.h"

class CustomAct: public Strategy {
public:
    CustomAct();
    std::string info() override;
    char act(Log &) override;
    void reset() override;
    void setIndex(size_t) override;
    void setPoints(size_t) override;
    size_t getPoints() override;

private:
    std::vector<char> instructions;
    int countCoop;
    int countDefect;
    size_t index;
    size_t points;
};


#endif //LAB2_DILEMMA_CUSTOMACT_H
