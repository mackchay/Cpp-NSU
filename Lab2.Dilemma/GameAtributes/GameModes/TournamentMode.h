#ifndef LAB2_DILEMMA_TOURNAMENTMODE_H
#define LAB2_DILEMMA_TOURNAMENTMODE_H

#include "GameMode.h"

class TournamentMode: public GameMode {
public:
    typedef std::shared_ptr<Game> GamePtr;
    TournamentMode();
    void init(Game) override;
    void start() override;

private:
    size_t strategyNumber;
    GamePtr gamePtr;
};


#endif //LAB2_DILEMMA_TOURNAMENTMODE_H
