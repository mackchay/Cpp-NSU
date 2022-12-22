#ifndef LAB2_DILEMMA_CUSTOMACT_H
#define LAB2_DILEMMA_CUSTOMACT_H

#include "../CustomStrategy/CustomStrategy.h"

class CustomAct: public CustomStrategy {
public:
    CustomAct();
    std::string info() override;
    char act() override;
    void reset() override;
    void setOpponentActs(const std::string &) override;
    void setDirName(const std::string &) override;

private:
    std::string instructions;
    int countCoop, countDefect;
    std::string fileName;
    Log log;
};


#endif //LAB2_DILEMMA_CUSTOMACT_H
