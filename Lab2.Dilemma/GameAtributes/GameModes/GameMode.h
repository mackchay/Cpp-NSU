#ifndef LAB2_DILEMMA_GAMEMODE_H
#define LAB2_DILEMMA_GAMEMODE_H
#include <iostream>
#include <memory>
#include "../GameBuild/GameBuild.h"

class GameMode {
public:

    virtual void addData(size_t, size_t) = 0;
    virtual void start(GameBuild &) = 0;
    virtual ~GameMode() = default;
};


#endif //LAB2_DILEMMA_GAMEMODE_H
