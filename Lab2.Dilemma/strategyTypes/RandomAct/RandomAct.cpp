#include <random>
#include "RandomAct.h"

std::string RandomAct::info() {
    return "RandomAct";
}

char RandomAct::act(Log &newLog) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<char> uni('c','d');

    return uni(rng);
}

