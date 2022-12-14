#ifndef LAB2_DILEMMA_GAME_H
#define LAB2_DILEMMA_GAME_H

#include "../GameModes/GameMode.h"

class Game {
public:

    Game();
    size_t addStrategy(Strategy*);
    void setMode(GameMode*);
    void run();
    ~Game();

private:
    std::vector<Strategy*> strategyList;
    GameMode* mode;
};


#endif //LAB2_DILEMMA_GAME_H
