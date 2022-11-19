#include <iostream>
#include "AlwaysCooperate.h"

void AlwaysCooperate::info() {
    std::cout << "StrategyType: AlwaysCooperate";
}

char AlwaysCooperate::act() {
    return 'c';
}