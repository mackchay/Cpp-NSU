#include <random>
#include "RandomAct.h"

RandomAct::RandomAct() {
    points = 0;
}

void RandomAct::setPoints(size_t newPoints) {
    points += newPoints;
}

size_t RandomAct::getPoints() {
    return points;
}

void RandomAct::reset() {
    points = 0;
}

std::string RandomAct::info() {
    return "RandomAct";
}

char RandomAct::act(Log &newLog) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<char> uni('c','d');

    return uni(rng);
}

