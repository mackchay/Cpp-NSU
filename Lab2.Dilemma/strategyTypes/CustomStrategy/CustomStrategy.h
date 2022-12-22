#ifndef LAB2_DILEMMA_CUSTOMSTRATEGY_H
#define LAB2_DILEMMA_CUSTOMSTRATEGY_H


#include "../Strategy.h"

class CustomStrategy: public Strategy {
public:

    virtual void setDirName(const std::string &) = 0;
};


#endif //LAB2_DILEMMA_CUSTOMSTRATEGY_H
