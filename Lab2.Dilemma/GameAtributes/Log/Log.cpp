#include "Log.h"

Log::Log() = default;

void Log::add(const std::string &pattern, char action) {
    if (!mapLog.contains(pattern)) {
        std::string newPlay;
        newPlay.push_back(action);
        mapLog.insert(std::make_pair(pattern, newPlay));
    }
    else {
        mapLog[pattern].push_back(action);
    }
}

bool Log::isCooperating(const std::string &strategyName) {
    if (mapLog[strategyName].back() == 'c') {
        return true;
    }
    return false;
}

bool Log::isDefecting(const std::string &strategyName) {
    if (mapLog[strategyName].back() == 'd') {
        return true;
    }
    return false;
}

std::vector<std::string> Log::opponentList(const std::string &strategyName) {
    std::vector<std::string> res;
    for (auto it = mapLog.begin(); it != mapLog.end(); it++) {
        if (it->first != strategyName) {
            res.push_back(it->first);
        }
    }
    return res;
}

