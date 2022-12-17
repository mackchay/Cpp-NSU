#include <iostream>
#include "AlwaysCooperate.h"

AlwaysCooperate::AlwaysCooperate() {
    points = 0;
}

size_t AlwaysCooperate::getPoints() {
    return points;
}

void AlwaysCooperate::setPoints(size_t newPoints) {
    points += newPoints;
}

void AlwaysCooperate::reset() {
    points = 0;
}

std::string AlwaysCooperate::info() {
    return "AlwaysCooperate";
}

char AlwaysCooperate::act(Log &newLog) {
    return 'c';
}

