#include <conio.h>
#include "DetailedMode.h"


void DetailedMode::addData(size_t, size_t number) {
    if (number != 3) {
        throw std::invalid_argument("Invalid strategy number");
    }
}

std::vector<std::string> DetailedMode::start() {
    unsigned char a = 0;
    while (a != 'q') {
        while (true) {
            if (kbhit() != 0) {
                a = getch();
                break;
            }
        }
        gameBuild.round();
        gameBuild.printResultCur();
        gameBuild.printResult();
    }
    return(gameBuild.printWinner());
}