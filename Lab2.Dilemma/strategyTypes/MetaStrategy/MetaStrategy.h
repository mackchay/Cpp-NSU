#ifndef LAB2_DILEMMA_METASTRATEGY_H
#define LAB2_DILEMMA_METASTRATEGY_H

#include "../../GameAtributes/Factory/Factory.h"
#include "../CustomStrategy/CustomStrategy.h"

class MetaStrategy: public CustomStrategy {
public:
    MetaStrategy();
    char act() override;
    void reset() override;
    std::string info() override;
    void setOpponentActs(const std::string &) override;
    void setDirName(const std::string &) override;
    ~MetaStrategy() override;

private:
      Factory <std::string, Strategy> strategyFactory;
      size_t countDefect, countCoop;
      std::string fileName;
      std::vector<Strategy*> strategyList;
      Log log;
      void registerFactory();
};


#endif //LAB2_DILEMMA_METASTRATEGY_H
