#include <iostream>
#include "AlwaysCooperate.h"

std::string AlwaysCooperate::info() {
    return "AlwaysCooperate";
}

char AlwaysCooperate::act(Log &newLog) {
    return 'c';
}

