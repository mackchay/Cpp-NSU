#include "AlwaysDefect.h"
#include <random>
#include <iostream>

AlwaysDefect::AlwaysDefect() {
    points = 0;
}

void AlwaysDefect::setPoints(size_t newPoints) {
    points += newPoints;
}

size_t AlwaysDefect::getPoints() {
    return points;
}

void AlwaysDefect::reset() {
    points = 0;
}

std::string AlwaysDefect::info() {
     return "AlwaysDefect";
}

char AlwaysDefect::act(Log &newLog) {
    return 'd';
}