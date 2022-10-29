#include "strategy_type.h"
#include "strategy_make.h"

void AlwaysBetray::info() {
    std::cout << "StrategyType: AlwaysBetray" << std::endl;
}

void AlwaysCooperate::info() {
    std::cout << "StrategyType: AlwaysCooperate";
}

bool AlwaysBetray::act() {
    return false;
}

bool AlwaysCooperate::act() {
    return true;
}

