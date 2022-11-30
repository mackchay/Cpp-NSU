#ifndef LAB2_DILEMMA_SCORINGMATRIX_H
#define LAB2_DILEMMA_SCORINGMATRIX_H

#include <map>
#include <iostream>
#include <vector>

class ScoringMatrix {
public:
    ScoringMatrix();
    size_t getScore(std::string&, size_t);

private:
    typedef std::map<std::string, std::vector<size_t>> mapVector;
    mapVector mapResult;
};


#endif //LAB2_DILEMMA_SCORINGMATRIX_H
