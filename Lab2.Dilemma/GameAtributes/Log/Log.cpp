#include "Log.h"

Log::Log() = default;

void Log::add(size_t index, char action) {
    if (vectorLog.size() <= index) {
        std::string newPlay;
        newPlay.push_back(action);
        vectorLog.push_back(newPlay);
    }
    else {
        vectorLog[index].push_back(action);
    }
}

bool Log::isCooperating(size_t strategyIndex) {
    if (vectorLog[strategyIndex].back() == 'c') {
        return true;
    }
    return false;
}

bool Log::isDefecting(size_t strategyIndex) {
    if (vectorLog[strategyIndex].back() == 'd') {
        return true;
    }
    return false;
}

size_t Log::opponentNumber() {
    return vectorLog.size();
}

std::vector<std::string> Log::opponentList(size_t index) {
    std::vector<std::string> res;
    for (size_t it = 0; it < vectorLog.size(); it++) {
        if (it != index) {
            res.push_back(vectorLog[it]);
        }
    }
    return res;
}

