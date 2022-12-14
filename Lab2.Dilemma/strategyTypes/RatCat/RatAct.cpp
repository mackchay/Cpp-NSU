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

char RatAct::act(Log &newLog) {
    if (patience == 0 || defectTime == 0) {
        return 'd';
    }
    size_t opponentNumber = newLog.opponentNumber();

    for (size_t i = 0; i < opponentNumber; i++) {
        if (newLog.isDefecting(i) && i != index) {
            patience --;
        }
    }
    defectTime--;
    return 'c';
}

void RatAct::setIndex(size_t number) {
    index = number;
}