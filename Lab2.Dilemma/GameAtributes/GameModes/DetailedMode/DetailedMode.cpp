#include <conio.h>
#include "DetailedMode.h"


void DetailedMode::addData(size_t, size_t number) {
    if (number != 3) {
        throw std::invalid_argument("Invalid strategy number");
    }
}

void DetailedMode::start(GameBuild &game) {
    unsigned char a = 0;
    while (a != 'q') {
        while (true) {
            if (kbhit() != 0) {
                a = getch();
                break;
            }
        }
        game.round();
        game.printResultCur();
        game.printResult();
    }
    game.printWinner();
}