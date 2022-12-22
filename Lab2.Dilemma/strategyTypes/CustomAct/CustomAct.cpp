#include <fstream>
#include "CustomAct.h"

CustomAct::CustomAct() {
    countCoop = 0, countDefect = 0;
    fileName = "/customAct.txt";
}

void CustomAct::reset() {
    points = 0, countCoop = 0, countDefect = 0;
}

std::string CustomAct::info() {
    return "CustomAct";
}

char CustomAct::act() {
    if (instructions.empty()) {
        if (countDefect >= countCoop) {
            return 'd';
        }
        return 'c';
    }
    char res = instructions.front();
    size_t opponentNumber = log.opponentNumber();
    instructions.erase(instructions.begin());
    for (size_t i = 0; i < opponentNumber; i++) {
        if (log.isCooperating(i)) {
            countCoop++;
        }
        if (log.isDefecting(i)) {
            countDefect++;
        }
    }
    return res;
}

void CustomAct::setOpponentActs(const std::string &opponentActs) {
    log.add(opponentActs);
}

void CustomAct::setDirName(const std::string &dirName) {
    std::ifstream fin;
    std::string strategyName;

    fin.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    fin.open(dirName + fileName);

    fin >> instructions;

    if (instructions.find_first_not_of("cd") != std::string::npos) {
        throw std::invalid_argument("Incorrect data in " + fileName);
    }

    fin.close();
}