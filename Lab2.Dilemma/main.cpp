#include <memory>
#include "GameAtributes/Game.h"

int main(int argc, char *argv[]) {
    Game dilemma;
    std::string strategyName, mode, enter;
    int steps;
    for (size_t i = 0; i < 3; i++) {
        std::cin >> strategyName;
        dilemma.add(strategyName);
    }

    std::cin >> mode;
    if (mode == "fast") {
        std::cin >> steps;
        for (size_t i = 0; i < steps; i++) {
            dilemma.round();
        }
        dilemma.printResult();
    }
    else {
        while (enter != "Q") {
            std::cin >> enter;
            dilemma.round();
            dilemma.printResult();
        }
    }

    return 0;
}
