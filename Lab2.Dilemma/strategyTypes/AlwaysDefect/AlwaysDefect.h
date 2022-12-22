#ifndef LAB2_DILEMMA_ALWAYSDEFECT_H
#define LAB2_DILEMMA_ALWAYSDEFECT_H

#include "../Strategy.h"

class AlwaysDefect: public Strategy {
public:
    AlwaysDefect() = default;
    std::string info() override;
    char act() override;
    void reset() override;
    void setOpponentActs(const std::string &) override {};

private:
    size_t points;
};



#endif //LAB2_DILEMMA_ALWAYSDEFECT_H
