#ifndef LAB2_DILEMMA_INPUTDATA_H
#define LAB2_DILEMMA_INPUTDATA_H
#include "../Game/Game.h"
#include "../GameModes/DetailedMode.h"
#include "../GameModes/FastMode.h"

class InputData {
public:
    InputData();
    ~InputData();

private:
    Game game;
    Factory <std::string, GameMode> gameModeFactory;
    std::unique_ptr<GameMode> mode;
};


#endif //LAB2_DILEMMA_INPUTDATA_H
