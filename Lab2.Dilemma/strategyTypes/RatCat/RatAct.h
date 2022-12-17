#ifndef LAB2_DILEMMA_RATACT_H
#define LAB2_DILEMMA_RATACT_H


#include "../Strategy.h"

class RatAct: public Strategy {
public:
    RatAct();
    std::string info() override;
    char act(Log &) override;
    void reset() override;
    void setIndex(size_t) override;
    void setPoints(size_t) override;
    size_t getPoints() override;

private:
    int patience;
    int defectTime;
    size_t points;
    size_t index;
};


#endif //LAB2_DILEMMA_RATACT_H
