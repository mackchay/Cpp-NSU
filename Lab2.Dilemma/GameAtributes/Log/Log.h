#ifndef LAB2_DILEMMA_LOG_H
#define LAB2_DILEMMA_LOG_H

#include "../GameResult/GameResult.h"

class Log {
private:
    std::vector<std::string> vectorLog;
public:

    Log();
    void add(size_t, char);
    bool isCooperating(size_t);
    bool isDefecting(size_t);

    size_t opponentNumber();
    std::vector<std::string> opponentList(size_t);

};


#endif //LAB2_DILEMMA_LOG_H
