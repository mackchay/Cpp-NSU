#include <iostream>
#include "AlwaysCooperate.h"


size_t AlwaysCooperate::getPoints() {
    return points;
}

void AlwaysCooperate::reset() {
    points = 0;
}

std::string AlwaysCooperate::info() {
    return "AlwaysCooperate";
}

char AlwaysCooperate::act() {
    return 'c';
}

