#ifndef LAB2_DILEMMA_LOG_H
#define LAB2_DILEMMA_LOG_H

#include <iostream>
#include <vector>

class Log {
private:
    std::vector<std::string> vectorLog;
    size_t len;
public:

    Log();
    Log(size_t);
    void add(const std::string &);
    bool isCooperating(size_t);
    bool isDefecting(size_t);
    std::string lastRound();
    size_t opponentNumber();

};


#endif //LAB2_DILEMMA_LOG_H
