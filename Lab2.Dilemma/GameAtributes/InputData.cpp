#include "InputData.h"



InputData::InputData() {
    std::string gameMode;
    size_t strategyNumber;
    std::string strategyName;

    std::cout << "Enter gameMode" << std::endl;
    std::cin >> gameMode;
    if (gameMode == "Tournament") {
        std::cout << "Enter strategyNumber" << std::endl;
        std::cin >> strategyNumber;
        matrix.resize(strategyNumber);
    }
    else {
        strategyNumber = 3;
    }

    std::cout << "Enter " << strategyNumber << " strategies ";
    for (size_t i = 0; i < strategyNumber; i++) {
        std::cin >> strategyName;

    }
}
