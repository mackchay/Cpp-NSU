#include "Log.h"

Log::Log() = default;

void Log::add(const std::string &actions) {
    vectorLog.push_back(actions);
}

bool Log::isCooperating(size_t strategyIndex) {
    if (!vectorLog.empty() && vectorLog.back()[strategyIndex] == 'c') {
        return true;
    }
    return false;
}

bool Log::isDefecting(size_t strategyIndex) {
    if (!vectorLog.empty() && vectorLog.back()[strategyIndex] == 'd') {
        return true;
    }
    return false;
}

size_t Log::opponentNumber() {
    if (vectorLog.empty()) {
        return 0;
    }
    return vectorLog.back().size();
}

std::string Log::lastRound() {
    return vectorLog.back();
}

