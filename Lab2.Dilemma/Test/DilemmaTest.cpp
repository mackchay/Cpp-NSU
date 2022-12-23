#include "DilemmaTest.h"

TEST_F(GameTest, ImpostorGame) {
   char *argv[] = {{}, (char*)"--mode=tournament", (char*)"AlwaysDefect",
                    (char*)"AlwaysCooperate", (char*)"AlwaysCooperate"
    , (char*)"AlwaysCooperate"};
    InputData input(5, argv);
    Game game(input);
    EXPECT_EQ(game.run()[0], "AlwaysDefect");
}

TEST_F(GameTest, Fast) {
    char *argv[] = {{}, (char*)"--mode=fast", (char*)"--steps=20",
                    (char*)"RatAct", (char*)"AlwaysCooperate"
            , (char*)"AlwaysCooperate"};
    InputData input(6, argv);
    Game game(input);
    EXPECT_EQ(game.run()[0], "RatAct");
}

TEST_F(GameTest, FrendlyVictory) {
    char *argv[] = {{}, (char*)"--mode=fast", (char*)"--steps=35",
                    (char*)"CoopUntilDefect", (char*)"CoopUntilDefect"
            , (char*)"CoopUntilDefect"};
    InputData input(6, argv);
    Game game(input);
    winners = {(char*)"CoopUntilDefect", (char*)"CoopUntilDefect"
            , (char*)"CoopUntilDefect"};
    EXPECT_EQ(game.run(), winners);
}
