#ifndef LAB2_DILEMMA_INPUTDATA_H
#define LAB2_DILEMMA_INPUTDATA_H
#include "../GameModes/DetailedMode/DetailedMode.h"
#include "../GameModes/FastMode/FastMode.h"
#include "../GameBuild/GameBuild.h"

class InputData {
public:
    InputData(int, char **);
    std::vector<Strategy*> &getStrategyList();
    std::string &getMatrix();
    std::shared_ptr<GameMode> getGameMode();

    ~InputData();

private:
    std::shared_ptr<GameMode> gameMode;
    size_t steps;
    std::vector<Strategy*> strategyList;
    std::string fileName;
    Factory <std::string, GameMode> gameModeFactory;
    Factory<std::string, Strategy> strategyFactory;
};


#endif //LAB2_DILEMMA_INPUTDATA_H
