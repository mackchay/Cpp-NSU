#ifndef LAB2_DILEMMA_STRATEGY_TYPE_H
#define LAB2_DILEMMA_STRATEGY_TYPE_H

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual bool act() = 0;
    virtual void info() = 0;
};

class PrimitiveStrategy : public Strategy {

};

class NonPrimitiveStrategy : public Strategy {

};

class AlwaysBetray : public PrimitiveStrategy {
    void info() override;
    bool act() override;
};

class AlwaysCooperate : public PrimitiveStrategy {
    void info() override;
    bool act() override;
};

#endif
