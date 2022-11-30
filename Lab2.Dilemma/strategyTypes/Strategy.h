#ifndef LAB2_DILEMMA_STRATEGY_H
#define LAB2_DILEMMA_STRATEGY_H

#include "../GameAtributes/Log/Log.h"

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual char act(Log &) = 0;
    virtual std::string info() = 0;
};


#endif //LAB2_DILEMMA_STRATEGY_H
