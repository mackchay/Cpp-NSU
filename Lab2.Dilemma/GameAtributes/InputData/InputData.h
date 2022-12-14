#ifndef LAB2_DILEMMA_INPUTDATA_H
#define LAB2_DILEMMA_INPUTDATA_H
#include "../GameModes/DetailedMode/DetailedMode.h"
#include "../GameModes/FastMode/FastMode.h"
#include "../GameBuild/GameBuild.h"
#include "../Game/Game.h"

class InputData {
public:
    InputData(int, char **, Game &);
    ~InputData();

private:
    Factory <std::string, GameMode> gameModeFactory;
    Factory<std::string, Strategy> strategyFactory;
};


#endif //LAB2_DILEMMA_INPUTDATA_H
