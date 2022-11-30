#include "InputData.h"
#include "../GameModes/TournamentMode.h"

InputData::InputData() {
    gameModeFactory.add<DetailedMode>("--detailed");
    gameModeFactory.add<FastMode>("--fast");
    gameModeFactory.add<TournamentMode>("--tournament");

    std::shared_ptr<Game> gamePtr(&game);

    std::string strategyName, gameMode;
    std::cin >> gameMode;
    if (gameModeFactory.contains(gameMode)) {
        mode.reset(gameModeFactory.get(gameMode)());
    }
    else {
        game.add(gameMode);
        mode.reset(gameModeFactory.get("--detailed")());
    }
    mode->init(game);
    mode->start();

}

InputData::~InputData() = default;