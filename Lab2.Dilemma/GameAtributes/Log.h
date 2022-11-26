#ifndef LAB2_DILEMMA_LOG_H
#define LAB2_DILEMMA_LOG_H

#include "GameResult.h"

class Log {
private:
    typedef std::map<std::string, std::vector<char>> MapLog;
    MapLog mapLog;
public:

    Log();
    void add(const std::string &, char);
    char lastAct(const std::string &);
    std::vector<std::string> opponentList(const std::string &);

};


#endif //LAB2_DILEMMA_LOG_H
