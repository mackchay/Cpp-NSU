#ifndef LAB2_DILEMMA_TOURNAMENTMODE_H
#define LAB2_DILEMMA_TOURNAMENTMODE_H

#include "../GameMode.h"

class TournamentMode: public GameMode {
public:
    typedef std::shared_ptr<Game> GamePtr;
    TournamentMode();
    void init(Game &) override;
    void start(Game &) override;

private:
    size_t strategyNumber;
};


#endif //LAB2_DILEMMA_TOURNAMENTMODE_H
