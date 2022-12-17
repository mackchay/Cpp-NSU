#ifndef LAB2_DILEMMA_ALWAYSCOOPERATE_H
#define LAB2_DILEMMA_ALWAYSCOOPERATE_H

#include "../Strategy.h"

class AlwaysCooperate : public Strategy {
public:
    AlwaysCooperate();
    std::string info() override;
    char act(Log &) override;
    void reset() override;
    void setIndex(size_t) override {};
    void setPoints(size_t) override;
    size_t getPoints() override;
private:
    size_t points;
};


#endif //LAB2_DILEMMA_ALWAYSCOOPERATE_H
