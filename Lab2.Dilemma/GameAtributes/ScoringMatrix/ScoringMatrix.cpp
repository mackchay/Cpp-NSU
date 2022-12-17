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

ScoringMatrix::ScoringMatrix(const std::string &file) {
    std::ifstream fin;
    fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    fin.open(file);

    while (!fin.eof()) {
        std::vector<size_t> score(3);
        std::string pattern;
        fin >> pattern;
        if (pattern.size() != 3 || pattern.find_first_not_of("cd") == std::string::npos) {
            throw std::ifstream::failure("Invalid matrix file.");
        }
        fin >> score[0] >> score[1]  >> score[2];
        mapScore.emplace(std::make_pair(pattern, score));
    }
}
