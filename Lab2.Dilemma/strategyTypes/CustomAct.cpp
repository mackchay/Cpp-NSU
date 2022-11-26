#include <fstream>
#include "CustomAct.h"
#define FIN "custom.txt"

CustomAct::CustomAct() {
    std::ifstream fin;
    char action;
    fin.open(FIN);
    while (!fin.eof()) {
        fin >> action;
        if (action == 'c' || action == 'd') {
            instructions.push_back(action);
        }
    }
    fin.close();
    countCoop = 0;
    countDefect = 0;
}

std::string CustomAct::info() {
    return "CustomAct";
}

char CustomAct::act(Log &newLog) {
    if (instructions.empty()) {
        if (countDefect >= countCoop) {
            return 'd';
        }
        return 'c';
    }
    char res = instructions.front();
    std::vector<std::string> list = newLog.opponentList((*this).info());
    instructions.erase(instructions.begin());
    for (auto it = list.begin(); it != list.end(); it++) {
        if (newLog.lastAct((*it)) == 'c') {
            countCoop++;
        }
        else {
            countDefect++;
        }
    }
    return res;
}