#ifndef LAB2_DILEMMA_GAME_H
#define LAB2_DILEMMA_GAME_H

#include "../GameModes/GameMode.h"
#include "../InputData/InputData.h"

class Game {
public:

    Game(InputData);
    void run();
    ~Game();

private:
    std::vector<Strategy*> strategyList;
    std::shared_ptr<GameMode> mode;
};


#endif //LAB2_DILEMMA_GAME_H
