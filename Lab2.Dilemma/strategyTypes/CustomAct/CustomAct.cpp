#include <fstream>
#include "CustomAct.h"


CustomAct::CustomAct() {
    points = 0;
    std::ifstream fin;
    char action;
    fin.open("custom.txt");
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

void CustomAct::setPoints(size_t newPoints) {
    points += newPoints;
}

size_t CustomAct::getPoints() {
    return points;
}

void CustomAct::reset() {
    (*this) = CustomAct();
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
    size_t opponentNumber = newLog.opponentNumber();
    instructions.erase(instructions.begin());
    for (size_t i = 0; i < opponentNumber; i++) {
        if (newLog.isCooperating(i) && i != index) {
            countCoop++;
        }
        if (newLog.isDefecting(i) && i != index){
            countDefect++;
        }
    }
    return res;
}

void CustomAct::setIndex(size_t number) {
    index = number;
}