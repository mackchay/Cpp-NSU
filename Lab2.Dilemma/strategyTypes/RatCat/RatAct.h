#ifndef LAB2_DILEMMA_RATACT_H
#define LAB2_DILEMMA_RATACT_H


#include "../Strategy.h"

class RatAct: public Strategy {
public:
    RatAct();
    std::string info() override;
    char act() override;
    void reset() override;
    void setOpponentActs(const std::string &) override;

private:
    int patience;
    int defectTime;
    Log log;
};


#endif //LAB2_DILEMMA_RATACT_H
