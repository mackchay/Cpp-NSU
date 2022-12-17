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
    void setPoints(size_t) override;
    size_t getPoints() override;

private:
    bool patience;
    size_t index;
    size_t points;
};


#endif //LAB2_DILEMMA_COOPUNTILDEFECT_H
