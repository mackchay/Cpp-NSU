#include <fstream>
#include "ScoringMatrix.h"

#define MATRIX "scoringMatrix.txt"

ScoringMatrix::ScoringMatrix() {
    std::string id;
    std::ifstream fin;
    fin.open(MATRIX);
    while (!fin.eof()) {
        fin >> id;
        mapResult[id].resize(3);
        fin >> mapResult[id][0] >> mapResult[id][1]
        >> mapResult[id][2];
    }
    fin.close();
}

size_t ScoringMatrix::getScore(std::string &pattern, size_t id) {
     return mapResult[pattern][id];
}