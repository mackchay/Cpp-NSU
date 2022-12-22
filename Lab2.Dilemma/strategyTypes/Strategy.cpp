#include "Strategy.h"

Strategy::Strategy() {
    points = 0;
}

void Strategy::setPoints(size_t newPoints) {
    points += newPoints;
}

size_t Strategy::getPoints() {
    return points;
}

void Strategy::setOpponentActs(const std::string &) {

}