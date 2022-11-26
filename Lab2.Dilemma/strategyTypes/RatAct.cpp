#include "RatAct.h"
RatAct::RatAct(){
    patience = true;
    defectTime = 3;
}

std::string RatAct::info() {
    return "RatAct";
}

char RatAct::act(Log &newLog) {
    if (!patience || defectTime == 0) {
        return 'd';
    }
    std::vector<std::string> list = newLog.opponentList((*this).info());
    for (auto it = list.begin(); it != list.end(); it++) {
        if (newLog.lastAct((*it)) == 'd') {
            patience = false;
            return 'd';
        }
    }
    defectTime--;
    return 'c';
}