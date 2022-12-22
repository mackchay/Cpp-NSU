#ifndef LAB2_DILEMMA_ALWAYSCOOPERATE_H
#define LAB2_DILEMMA_ALWAYSCOOPERATE_H

#include "../Strategy.h"

class AlwaysCooperate : public Strategy {
public:

    std::string info() override;
    char act() override;
    void reset() override;
    void setOpponentActs(const std::string &) override {};
    size_t getPoints() override;
};


#endif //LAB2_DILEMMA_ALWAYSCOOPERATE_H
