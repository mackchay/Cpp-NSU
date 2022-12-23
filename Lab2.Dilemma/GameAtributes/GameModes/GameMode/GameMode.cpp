#include "GameMode.h"

void GameMode::initGameBuild(const std::vector<Strategy *> &strategyList,
                             const std::string &matrix) {
    gameBuild = GameBuild(strategyList, matrix);
}
