#include "RatAct.h"
RatAct::RatAct() {
    patience = 1;
    defectTime = 3;

}

void RatAct::reset() {
    (*this) = RatAct();
}

std::string RatAct::info() {
    return "RatAct";
}

char RatAct::act() {
    if (patience == 0 || defectTime == 0) {
        return 'd';
    }
    size_t opponentNumber = log.opponentNumber();

    for (size_t i = 0; i < opponentNumber; i++) {
        if (log.isDefecting(i)) {
            patience --;
        }
    }
    defectTime--;
    return 'c';
}

void RatAct::setOpponentActs(const std::string &opponentActs) {
    log.add(opponentActs);
}