#ifndef LAB2_DILEMMA_GAME_H
#define LAB2_DILEMMA_GAME_H

#include "../GameModes/GameMode/GameMode.h"
#include "../InputData/InputData.h"

class Game {
public:

    explicit Game(InputData);
    std::vector<std::string> run();
    ~Game();


private:
    std::vector<Strategy*> strategyList;
    std::shared_ptr<GameMode> mode;
};


#endif //LAB2_DILEMMA_GAME_H
