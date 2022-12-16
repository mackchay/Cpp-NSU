#include <fstream>
#include <memory>
#include "InputData.h"
#include "../GameModes/TournamentMode/TournamentMode.h"
#include "../../strategyTypes/AlwaysCooperate/AlwaysCooperate.h"
#include "../../strategyTypes/AlwaysDefect/AlwaysDefect.h"
#include "../../strategyTypes/RandomAct/RandomAct.h"
#include "../../strategyTypes/CoopUntilDefect/CoopUntilDefect.h"
#include "../../strategyTypes/CustomAct/CustomAct.h"
#include "../../strategyTypes/RatCat/RatAct.h"


InputData::InputData(int argc, char *argv[]) {
    gameModeFactory.add<DetailedMode>("detailed");
    gameModeFactory.add<FastMode>("fast");
    gameModeFactory.add<TournamentMode>("tournament");

    strategyFactory.add<AlwaysDefect>("AlwaysDefect");
    strategyFactory.add<AlwaysCooperate>("AlwaysCooperate");
    strategyFactory.add<RandomAct>("RandomAct");
    strategyFactory.add<CoopUntilDefect>("CoopUntilDefect");
    strategyFactory.add<CustomAct>("CustomAct");
    strategyFactory.add<RatAct>("RatAct");

    gameMode = std::make_shared_for_overwrite<DetailedMode>();
    steps = 1;

    try {
        std::string data = argv[1];
        if (data.substr(0, 7) == "--mode=" &&
            gameModeFactory.contains(data.substr(7, data.size() - 7))) {
            gameMode.reset(gameModeFactory.get(data.substr(7, data.size() - 7))());
        } else if (strategyFactory.contains(data)) {
            strategyList.push_back(strategyFactory.get(data)());
            (*strategyList.end())->setIndex(strategyList.size() - 1);
        } else if (data == "--help") {

            std::ifstream fin;
            std::getline(fin, data);
            std::cout << data;
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
                strategyList.push_back(strategyFactory.get(data)());
                (*(strategyList.end() - 1))->setIndex(strategyList.size() - 1);
            } else {
                throw std::invalid_argument("Invalid name of strategy.");
            }
        }
        if (strategyList.size() < 3) {
            throw std::invalid_argument("Invalid strategy number");
        }
    }
    catch (const std::exception &e) {
        for (auto it = strategyList.begin(); it < strategyList.end(); it++) {
            delete *it;
        }
        std::cerr << e.what();
        exit(1);
    }

}

size_t InputData::getSteps(){
    return steps;
}

std::vector<Strategy *> InputData::getStrategyList() {
    return strategyList;
}

std::shared_ptr<GameMode> InputData::getGameMode() {
    return gameMode;
}

InputData::~InputData() = default;