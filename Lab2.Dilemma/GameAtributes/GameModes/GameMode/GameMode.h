#ifndef LAB2_DILEMMA_GAMEMODE_H
#define LAB2_DILEMMA_GAMEMODE_H
#include <iostream>
#include <memory>
#include "../../GameBuild/GameBuild.h"

class GameMode {
public:

    void initGameBuild(const std::vector<Strategy *> &, const std::string &);
    virtual void addData(size_t, size_t) = 0;
    virtual std::vector<std::string> start() = 0;
    virtual ~GameMode() = default;

protected:
    GameBuild gameBuild;
};


#endif //LAB2_DILEMMA_GAMEMODE_H
