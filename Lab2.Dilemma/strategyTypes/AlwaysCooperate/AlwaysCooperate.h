#ifndef LAB2_DILEMMA_ALWAYSCOOPERATE_H
#define LAB2_DILEMMA_ALWAYSCOOPERATE_H

#include "../Strategy.h"

class AlwaysCooperate : public Strategy {
public:
    std::string info() override;
    char act(Log &) override;
};


#endif //LAB2_DILEMMA_ALWAYSCOOPERATE_H
