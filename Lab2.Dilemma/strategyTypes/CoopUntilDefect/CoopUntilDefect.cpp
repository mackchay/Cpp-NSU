#include "CoopUntilDefect.h"

CoopUntilDefect::CoopUntilDefect() {
    patience = true;
}
std::string CoopUntilDefect::info() {
    return "CoopUntilDefect";
}

char CoopUntilDefect::act(Log &newLog) {
    if (patience == 0) {
        return 'd';
    }
    std::vector<std::string> list = newLog.opponentList((*this).info());
    for (auto it = list.begin(); it != list.end(); it++) {
        if (newLog.isDefecting(*it)) {
            patience = false;
            return 'd';
        }
    }
    return 'c';
}
