#ifndef LAB2_DILEMMA_TOURNAMENTMODE_H
#define LAB2_DILEMMA_TOURNAMENTMODE_H

#include "../GameMode/GameMode.h"

class TournamentMode: public GameMode {
public:
    typedef std::shared_ptr<GameBuild> GamePtr;
    TournamentMode();
    void addData(size_t, size_t) override;
    std::vector<std::string> start() override;

private:
    size_t steps;
    size_t strategyNumber;
};


#endif //LAB2_DILEMMA_TOURNAMENTMODE_H
