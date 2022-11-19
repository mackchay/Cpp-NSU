#include <memory>
#include "GameAtributes/Game.h"

int main() {
    Game dilemma;
    std::string ivan = "AlwaysCooperate";
    std::string gleb = "RandomAct";
    std::string denis = "AlwaysDistrust";
    for (size_t i = 0; i < 3; i++) {
    }
    dilemma.add(ivan);
    dilemma.add(gleb);
    dilemma.add(denis);
    dilemma.round();

    return 0;
}
