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

private:
    std::vector<char> instructions;
    int countCoop;
    int countDefect;
    size_t index;
};


#endif //LAB2_DILEMMA_CUSTOMACT_H
