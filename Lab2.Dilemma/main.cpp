#include "GameAtributes/InputData/InputData.h"
#include "GameAtributes/Game/Game.h"
#include <memory>


int main(int argc, char *argv[]) {
    Game dilemma(InputData(argc, argv));
    dilemma.run();
    return 0;
}
