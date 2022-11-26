#include "CoopUntilDefect.h"

CoopUntilDefect::CoopUntilDefect() {
    patience = 2;

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
        if (newLog.lastAct(*it) == 'd') {
            patience--;
        }
    }
    return 'c';
}
