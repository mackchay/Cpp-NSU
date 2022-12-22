#ifndef LAB2_DILEMMA_COOPUNTILDEFECT_H
#define LAB2_DILEMMA_COOPUNTILDEFECT_H

#include "../Strategy.h"

class CoopUntilDefect : public Strategy {
public:

    CoopUntilDefect();
    std::string info() override;
    char act() override;
    void reset() override;
    void setOpponentActs(const std::string &) override;

private:
    bool patience;
    Log log;
};


#endif //LAB2_DILEMMA_COOPUNTILDEFECT_H
