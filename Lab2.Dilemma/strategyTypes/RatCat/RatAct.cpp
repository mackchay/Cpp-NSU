#include "RatAct.h"
RatAct::RatAct(){
    patience = 1;
    defectTime = 3;
}

std::string RatAct::info() {
    return "RatAct";
}

char RatAct::act(Log &newLog) {
    if (patience == 0 || defectTime == 0) {
        return 'd';
    }
    std::vector<std::string> list = newLog.opponentList((*this).info());
    for (auto it = list.begin(); it != list.end(); it++) {
        if (newLog.isDefecting((*it))) {
            patience --;
        }
    }
    defectTime--;
    return 'c';
}