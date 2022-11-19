#ifndef LAB2_DILEMMA_STRATEGY_H
#define LAB2_DILEMMA_STRATEGY_H

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual char act() = 0;
    virtual void info() = 0;
};


#endif //LAB2_DILEMMA_STRATEGY_H
