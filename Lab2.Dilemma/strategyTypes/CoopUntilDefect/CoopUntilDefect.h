#ifndef LAB2_DILEMMA_COOPUNTILDEFECT_H
#define LAB2_DILEMMA_COOPUNTILDEFECT_H

#include "../Strategy.h"

class CoopUntilDefect : public Strategy {
public:

    CoopUntilDefect();
    std::string info() override;
    char act(Log &) override;

private:
    bool patience;
};


#endif //LAB2_DILEMMA_COOPUNTILDEFECT_H
