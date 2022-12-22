#include <random>
#include "RandomAct.h"



void RandomAct::reset() {
    points = 0;
}

std::string RandomAct::info() {
    return "RandomAct";
}

char RandomAct::act() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<char> uni('c','d');

    return uni(rng);
}

