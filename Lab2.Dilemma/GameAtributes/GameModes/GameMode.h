#ifndef LAB2_DILEMMA_GAMEMODE_H
#define LAB2_DILEMMA_GAMEMODE_H
#include <iostream>
#include <memory>
#include "../Game/Game.h"

class GameMode {
public:
    typedef std::shared_ptr<Game> GamePtr;
    virtual void init(Game ) = 0;
    virtual void start() = 0;
    virtual ~GameMode() = default;
};


#endif //LAB2_DILEMMA_GAMEMODE_H
