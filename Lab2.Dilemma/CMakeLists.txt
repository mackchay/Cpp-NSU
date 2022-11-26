cmake_minimum_required(VERSION 3.20)
project(Lab2.Dilemma)

set(CMAKE_CXX_STANDARD 23)

add_executable(Lab2.Dilemma main.cpp strategyTypes/AlwaysCooperate.cpp strategyTypes/AlwaysCooperate.h strategyTypes/AlwaysDefect.cpp strategyTypes/AlwaysDefect.h strategyTypes/RandomAct.cpp strategyTypes/RandomAct.h strategyTypes/Strategy.h GameAtributes/InputData.cpp GameAtributes/InputData.h GameAtributes/GameResult.cpp GameAtributes/GameResult.h GameAtributes/StrategyFactory.cpp GameAtributes/StrategyFactory.h GameAtributes/Log.cpp GameAtributes/Log.h GameAtributes/ScoringMatrix.cpp GameAtributes/ScoringMatrix.h GameAtributes/Game.cpp GameAtributes/Game.h GameAtributes/StrategyParser.cpp GameAtributes/StrategyParser.h strategyTypes/CoopUntilDefect.cpp strategyTypes/CoopUntilDefect.h strategyTypes/CustomAct.cpp strategyTypes/CustomAct.h strategyTypes/RatAct.cpp strategyTypes/RatAct.h)
