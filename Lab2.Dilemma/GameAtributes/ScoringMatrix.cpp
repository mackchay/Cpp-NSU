#include <fstream>
#include "ScoringMatrix.h"

#define MATRIX "scoringMatrix.txt"

ScoringMatrix::ScoringMatrix() {
    std::string id;
    std::vector<size_t> points(3);
    std::ifstream fin;
    fin.open(MATRIX);
    while (!fin.eof()) {
        fin >> id;
        fin >> points[0] >> points[1]
            >> points[2];
        mapResult.insert(std::make_pair(id, points));
    }
    fin.close();
}

size_t ScoringMatrix::getScore(std::string &pattern, size_t id) {
    if (mapResult.contains(pattern)) {
        return mapResult[pattern][id];
    }
    else {
        throw std::invalid_argument("Invalid gameResult or ScoringMatrix data!");
    }
}