#include "AlwaysDefect.h"
#include <random>


void AlwaysDefect::reset() {
    points = 0;
}

std::string AlwaysDefect::info() {
     return "AlwaysDefect";
}

char AlwaysDefect::act() {
    return 'd';
}