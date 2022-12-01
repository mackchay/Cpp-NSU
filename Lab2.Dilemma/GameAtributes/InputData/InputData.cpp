#include "InputData.h"
#include "../GameModes/TournamentMode/TournamentMode.h"

InputData::InputData() {
    gameModeFactory.add<DetailedMode>("--detailed");
    gameModeFactory.add<FastMode>("--fast");
    gameModeFactory.add<TournamentMode>("--tournament");
    DetailedMode defaultMode(2);


    std::string strategyName, gameMode;
    std::cin >> gameMode;
    if (gameModeFactory.contains(gameMode)) {
        mode.reset(gameModeFactory.get(gameMode)());
        mode->init(game);
        mode->start(game);
    }
    else {
        game.add(gameMode);
        defaultMode.init(game);
        defaultMode.start(game);
    }
}

InputData::~InputData() = default;