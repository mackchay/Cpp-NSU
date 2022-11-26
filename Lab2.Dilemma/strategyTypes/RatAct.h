#ifndef LAB2_DILEMMA_RATACT_H
#define LAB2_DILEMMA_RATACT_H


#include "Strategy.h"

class RatAct: public Strategy {
public:
    RatAct();
    std::string info() override;
    char act(Log &) override;
private:
    bool patience;
    int defectTime;
};


#endif //LAB2_DILEMMA_RATACT_H
