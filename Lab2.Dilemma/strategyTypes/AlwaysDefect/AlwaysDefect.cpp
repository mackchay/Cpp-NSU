#include "AlwaysDefect.h"
#include <random>
#include <iostream>

std::string AlwaysDefect::info() {
     return "AlwaysDistrust";
}

char AlwaysDefect::act(Log &newLog) {
    return 'd';
}