#include "TournamentMode.h"

TournamentMode::TournamentMode() {
    std::cin >> strategyNumber;
}

void TournamentMode::init(Game game) {
    this->gamePtr.reset(&game);
    std::string strategyName;
    for (size_t i = 0; i < strategyNumber; i++) {
        std::cin >> strategyName;
        gamePtr->add(strategyName);
    }
}

void TournamentMode::start() {
    std::vector<std::string> listAll, listThree;
    listAll = gamePtr->listOfPlayers();
    for (size_t itA = 0; itA < strategyNumber - 2; itA++) {
        for (size_t itB = itA+1; itB < strategyNumber - 1; itB++){
            for (size_t itC = itB + 1; itC < strategyNumber; itC++) {
                listThree.push_back(listAll[itA]);
                listThree.push_back(listAll[itB]);
                listThree.push_back(listAll[itC]);
                gamePtr->round(listThree);
                listThree.clear();
            }
        }
    }
}