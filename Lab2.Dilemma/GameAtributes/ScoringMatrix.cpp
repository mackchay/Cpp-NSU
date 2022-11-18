#include "ScoringMatrix.h"

ScoringMatrix::ScoringMatrix() {
    mapResult["ccc"] = {7, 7, 7};
    mapResult["ccd"] = {3, 3, 3};
    mapResult["cdc"] = {3, 9, 3};
    mapResult["dcc"] = {9, 3, 3};
    mapResult["dcc"] = {9, 3, 3};
    mapResult["cdd"] = {0, 5, 5};
    mapResult["dcd"] = {5, 0, 5};
    mapResult["ddc"] = {5, 5, 0};
    mapResult["ddd"] = {1, 1, 1};
}

size_t ScoringMatrix::getScore(std::string &pattern, size_t id) {
     return mapResult[pattern][id];
}