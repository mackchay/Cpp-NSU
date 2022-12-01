#include <fstream>
#include "ScoringMatrix.h"


ScoringMatrix::ScoringMatrix() {
    mapScore["ccc"] = {7, 7, 7};
    mapScore["ccd"] = {3, 3, 9};
    mapScore["cdc"] = {3, 9, 3};
    mapScore["dcc"] = {9, 3, 3};
    mapScore["cdd"] = {0, 5, 5};
    mapScore["dcd"] = {5, 0, 5};
    mapScore["ddc"] = {5, 5, 0};
    mapScore["ddd"] = {1, 1, 1};

}

size_t ScoringMatrix::getScore(std::string &pattern, size_t id) {
    if (mapScore.contains(pattern)) {
        return mapScore[pattern][id];
    } else {
        throw std::invalid_argument("Invalid gameResult or ScoringMatrix data!");
    }
}