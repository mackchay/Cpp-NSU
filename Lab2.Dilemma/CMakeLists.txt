cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 23)

project(Lab2.Dilemma)

# задаем имя исполняемого файла основной программы
set(dilemma ${PROJECT_NAME})

# задаем имя исполняемого файла программы для запуска тестов
set(dilemma_test test)

# Включаем отслеживание всех предупреждений (warnings) и запрещаем компиляцию при наличии предупреждений.
# Считается хорошим тоном, когда программа собирается без предупрреждений.
# Но вы можете убрать /WX и -Werror (разрешив компиляцию с предупреждениями), если сможете разумно объяснить своё решение.
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# описываем основную библиотеку, т.е. библиотеку, содержащую все cpp-файлы, кроме main.cpp
# TODO: отредактировать список cpp-файлов
add_library(corelib OBJECT strategyTypes/AlwaysCooperate/AlwaysCooperate.cpp
        strategyTypes/RandomAct/RandomAct.cpp
        GameAtributes/InputData/InputData.cpp GameAtributes/Factory/Factory.cpp
        GameAtributes/Log/Log.cpp GameAtributes/ScoringMatrix/ScoringMatrix.cpp
        GameAtributes/GameBuild/GameBuild.cpp
        strategyTypes/CoopUntilDefect/CoopUntilDefect.cpp
        strategyTypes/AlwaysDefect/AlwaysDefect.cpp
        strategyTypes/CustomAct/CustomAct.cpp
        strategyTypes/RatCat/RatAct.cpp
        GameAtributes/GameModes/DetailedMode/DetailedMode.cpp
        GameAtributes/GameModes/FastMode/FastMode.cpp
        GameAtributes/GameModes/TournamentMode/TournamentMode.cpp
        strategyTypes/MetaStrategy/MetaStrategy.cpp
        GameAtributes/Game/Game.cpp
        strategyTypes/Strategy.cpp
        strategyTypes/AlwaysDefect/AlwaysDefect.cpp)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# описываем исполняемый файл основной программы: это main.cpp + основная библиотека
add_executable(${dilemma} main.cpp)

target_link_libraries(${dilemma} corelib)

# ========== все, что ниже, относится к тестированию при помощи GoogleTest ==========

# скачиваем библиотеку GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/79d0399dba364a335e3ca621a8cce091ef5706da.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# описываем исполняемый файл программы для запуска тестов: это cpp-файлы тестов + основная библиотека + библиотека gtest_main
# наш собственный main.cpp здесь не нужен, т.к. функция main реализована в gtest_main
add_executable(${dilemma_test} Test/DilemmaTest.cpp)


target_link_libraries(${dilemma_test} gtest_main)
target_link_libraries(${dilemma_test} corelib)

