#include "AlwaysDistrust.h"
#include <random>
#include <iostream>

void AlwaysDistrust::info() {
    std::cout << "StrategyType: AlwaysDistrust" << std::endl;
}

char AlwaysDistrust::act() {
    return 'd';
}