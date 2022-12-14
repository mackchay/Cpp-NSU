#include "AlwaysDefect.h"
#include <random>
#include <iostream>

std::string AlwaysDefect::info() {
     return "AlwaysDefect";
}

char AlwaysDefect::act(Log &newLog) {
    return 'd';
}