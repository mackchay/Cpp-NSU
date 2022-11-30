#include "Log.h"

Log::Log() = default;

void Log::add(const std::string &pattern, char action) {
    if (!mapLog.contains(pattern)) {
        mapLog.insert(std::make_pair(pattern, action));
    }
    else {
        mapLog[pattern].push_back(action);
    }
}

char Log::lastAct(const std::string &strategyName) {
    return mapLog[strategyName].back();
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

