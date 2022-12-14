#include "TournamentMode.h"

TournamentMode::TournamentMode() {
    steps = 1;
}

void TournamentMode::addData(size_t newSteps, size_t strategies) {
    steps = newSteps;
    strategyNumber = strategies;
}

void TournamentMode::start(GameBuild &game) {
    std::vector<size_t> listThree, listAll;
    for (size_t i = 0; i < strategyNumber; i++) {
        listAll.push_back(i);
    }

    for (size_t itA = 0; itA < strategyNumber - 2; itA++) {
        for (size_t itB = itA+1; itB < strategyNumber - 1; itB++){
            for (size_t itC = itB + 1; itC < strategyNumber; itC++) {
                for (size_t j = 0; j < steps; j++) {
                    game.round({itA, itB, itC});
                    listThree.clear();
                }
                std::cout << "Round " << itA + itB + itC << ":" << std::endl;
                game.printLastActions({itA, itB, itC}, steps);
                game.reset();
            }
        }
    }

    game.printResult(listAll);
}