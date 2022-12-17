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
        std::string data;
        for (size_t i = 1; i < argc; i++) {
            data = argv[i];
            if (data.substr(0, 7) == "--mode=" &&
                gameModeFactory.contains(data.substr(7, data.size() - 7))) {
                gameMode.reset(gameModeFactory.get(data.substr(7, data.size() - 7))());
            } else if (data.substr(0, 8) == "--steps=") {
                steps = std::stoll(data.substr(8, data.size() - 8));
                if (data.substr(8, 1) == "-") {
                    throw std::invalid_argument("Invalid steps number.");
                }
            } else if (data == "--help") {

                std::ifstream fin;
                std::getline(fin, data);
                std::cout << data;
                return;
            } else if (data.substr(0, 9) == "--matrix=") {
                scoringMatrix = ScoringMatrix(data.substr(9, data.size() - 9));
            } else if (strategyFactory.contains(data)) {
                strategyList.push_back(strategyFactory.get(data)());
            } else {
                throw std::invalid_argument("Invalid name of strategy.");
            }
        }
        gameMode->addData(steps, strategyList.size()); //throw exception about strategy number.
    }
    catch (const std::exception &e) {
        for (auto it = strategyList.begin(); it < strategyList.end(); it++) {
            delete *it;
        }
        std::cerr << e.what();
        exit(1);
    }

}

ScoringMatrix &InputData::getMatrix() {
    return scoringMatrix;
}

std::vector<Strategy *> &InputData::getStrategyList() {
    return strategyList;
}

std::shared_ptr<GameMode> InputData::getGameMode() {
    return gameMode;
}

InputData::~InputData() = default;