#ifndef LAB2_DILEMMA_COOPUNTILDEFECT_H
#define LAB2_DILEMMA_COOPUNTILDEFECT_H

#include "../Strategy.h"

class CoopUntilDefect : public Strategy {
public:

    CoopUntilDefect();
    std::string info() override;
    char act(Log &) override;
    void reset() override;
    void setIndex(size_t) override;

private:
    bool patience;
    size_t index;
};


#endif //LAB2_DILEMMA_COOPUNTILDEFECT_H
