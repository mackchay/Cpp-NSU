#include "CoopUntilDefect.h"

CoopUntilDefect::CoopUntilDefect() {
    patience = true;
}

void CoopUntilDefect::reset() {
    (*this) = CoopUntilDefect();
}

std::string CoopUntilDefect::info() {
    return "CoopUntilDefect";
}

void CoopUntilDefect::setIndex(size_t number) {
    index = number;
}

char CoopUntilDefect::act(Log &newLog) {
    if (patience == 0) {
        return 'd';
    }

    size_t opponentNumber = newLog.opponentNumber();

    for (size_t i = 0; i < opponentNumber; i++) {
        if (newLog.isDefecting(i) && i != index) {
            patience = false;
            return 'd';
        }
    }
    return 'c';
}
