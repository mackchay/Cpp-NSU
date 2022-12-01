#ifndef LAB2_DILEMMA_LOG_H
#define LAB2_DILEMMA_LOG_H

#include "../GameResult/GameResult.h"

class Log {
private:
    typedef std::map<std::string, std::string> MapLog;
    MapLog mapLog;
public:

    Log();
    void add(const std::string &, char);
    bool isCooperating(const std::string &);
    bool isDefecting(const std::string &);

    std::vector<std::string> opponentList(const std::string &);

};


#endif //LAB2_DILEMMA_LOG_H
