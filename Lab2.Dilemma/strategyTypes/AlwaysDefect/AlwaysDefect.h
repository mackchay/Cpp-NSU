#ifndef LAB2_DILEMMA_ALWAYSDEFECT_H
#define LAB2_DILEMMA_ALWAYSDEFECT_H

#include "../Strategy.h"

class AlwaysDefect: public Strategy {
public:
    std::string info() override;
    char act(Log &) override;
    void reset() override {};
    void setIndex(size_t) override {};
};


#endif //LAB2_DILEMMA_ALWAYSDEFECT_H
