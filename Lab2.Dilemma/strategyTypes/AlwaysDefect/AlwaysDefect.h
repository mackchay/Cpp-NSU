#ifndef LAB2_DILEMMA_ALWAYSDEFECT_H
#define LAB2_DILEMMA_ALWAYSDEFECT_H

#include "../Strategy.h"

class AlwaysDefect: public Strategy {
public:
    AlwaysDefect();
    std::string info() override;
    char act(Log &) override;
    void reset() override;
    void setIndex(size_t) override {};
    void setPoints(size_t) override;
    size_t getPoints() override;
private:
    size_t points;
};



#endif //LAB2_DILEMMA_ALWAYSDEFECT_H
