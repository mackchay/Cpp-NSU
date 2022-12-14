#include <fstream>
#include "InputData.h"
#include "../GameModes/TournamentMode/TournamentMode.h"
#include "../../strategyTypes/AlwaysCooperate/AlwaysCooperate.h"
#include "../../strategyTypes/AlwaysDefect/AlwaysDefect.h"
#include "../../strategyTypes/RandomAct/RandomAct.h"
#include "../../strategyTypes/CoopUntilDefect/CoopUntilDefect.h"
#include "../../strategyTypes/CustomAct/CustomAct.h"
#include "../../strategyTypes/RatCat/RatAct.h"


InputData::InputData(int argc, char *argv[], Game &game) {
    gameModeFactory.add<DetailedMode>("detailed");
    gameModeFactory.add<FastMode>("fast");
    gameModeFactory.add<TournamentMode>("tournament");

    strategyFactory.add<AlwaysDefect>("AlwaysDefect");
    strategyFactory.add<AlwaysCooperate>("AlwaysCooperate");
    strategyFactory.add<RandomAct>("RandomAct");
    strategyFactory.add<CoopUntilDefect>("CoopUntilDefect");
    strategyFactory.add<CustomAct>("CustomAct");
    strategyFactory.add<RatAct>("RatAct");

    Strategy *strategy = new AlwaysCooperate();
    GameMode *gameMode = new DetailedMode();
    size_t strategyNumber = 0, steps = 0;

    try {
        std::string data = argv[1];
        if (data.substr(0, 7) == "--mode=" &&
            gameModeFactory.contains(data.substr(7, data.size() - 7))) {
            gameMode = gameModeFactory.get(data.substr(7, data.size() - 7))();
        } else if (strategyFactory.contains(data)) {
            strategy = strategyFactory.get(data)();
            strategyNumber = game.addStrategy(strategy);
        } else if (data == "--help") {

            std::ifstream fin;
            std::getline(fin, data);
            std::cout << data;
            delete gameMode;
            delete strategy;
            return;

        } else {
            throw std::invalid_argument("Invalid name of strategy or game mode.");
        }

        for (size_t i = 2; i < argc; i++) {
            data = argv[i];
            if (data.substr(0, 8) == "--steps=") {
                steps = std::stoll(data.substr(8, data.size() - 8));
                if (data.substr(8, 1) == "-") {
                    throw std::invalid_argument("Invalid steps number.");
                }
            } else if (strategyFactory.contains(data)) {
                strategy = strategyFactory.get(data)();
                strategyNumber = game.addStrategy(strategy);
            } else {
                throw std::invalid_argument("Invalid name of strategy.");
            }
        }
        if (strategyNumber < 3) {
            throw std::invalid_argument("Invalid strategy number");
        }
        gameMode->addData(steps, strategyNumber);
        game.setMode(gameMode);
    }
    catch (const std::exception &e) {
        delete gameMode;
        delete strategy;
        std::cerr << e.what();
        exit(1);
    }

}

InputData::~InputData() = default;