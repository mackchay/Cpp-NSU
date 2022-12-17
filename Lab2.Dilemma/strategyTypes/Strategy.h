#ifndef LAB2_DILEMMA_STRATEGY_H
#define LAB2_DILEMMA_STRATEGY_H

#include "../GameAtributes/Log/Log.h"

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual char act(Log &) = 0;
    virtual void reset() = 0;
    virtual std::string info() = 0;
    virtual void setIndex(size_t) = 0;
    virtual void setPoints(size_t) = 0;
    virtual size_t getPoints() = 0;
};


#endif //LAB2_DILEMMA_STRATEGY_H
