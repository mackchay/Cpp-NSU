#include "TournamentMode.h"

TournamentMode::TournamentMode() {
    steps = 1;
}

void TournamentMode::addData(size_t newSteps, size_t strategies) {
    steps = newSteps;
    if (strategies >= 3) {
        strategyNumber = strategies;
    }
    else {
       throw std::invalid_argument("Invalid strategy number");
    }
}

void TournamentMode::start(GameBuild &game) {
    size_t z = 1;

    for (size_t itA = 0; itA < strategyNumber - 2; itA++) {
        for (size_t itB = itA+1; itB < strategyNumber - 1; itB++){
            for (size_t itC = itB + 1; itC < strategyNumber; itC++) {
                for (size_t j = 0; j < steps; j++) {
                    game.round({itA, itB, itC});
                }

                game.printResult({itA, itB, itC});
                game.reset();
            }
        }
    }

    game.printResultFinal();
    game.printWinner();
}