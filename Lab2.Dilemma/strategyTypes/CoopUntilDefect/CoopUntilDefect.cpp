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

void CoopUntilDefect::setOpponentActs(const std::string &number) {
    log.add(number);
}

char CoopUntilDefect::act() {
    if (patience == 0) {
        return 'd';
    }

    size_t opponentNumber = log.opponentNumber();

    for (size_t i = 0; i < opponentNumber; i++) {
        if (log.isDefecting(i)) {
            patience = false;
            return 'd';
        }
    }
    return 'c';
}
