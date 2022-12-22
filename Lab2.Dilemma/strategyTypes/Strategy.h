#ifndef LAB2_DILEMMA_STRATEGY_H
#define LAB2_DILEMMA_STRATEGY_H

#include "../GameAtributes/Log/Log.h"

class Strategy {
public:
    Strategy();
    virtual ~Strategy() = default;
    virtual char act() = 0;
    virtual void reset() = 0;
    virtual std::string info() = 0;
    virtual void setOpponentActs(const std::string &);
    virtual void setPoints(size_t);
    virtual size_t getPoints();

protected:
    size_t points;
};


#endif //LAB2_DILEMMA_STRATEGY_H
