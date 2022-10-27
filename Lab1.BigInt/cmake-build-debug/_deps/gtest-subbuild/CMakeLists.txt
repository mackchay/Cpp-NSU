# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.20.2)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(gtest-populate NONE)



include(ExternalProject)
ExternalProject_Add(gtest-populate
                     "UPDATE_DISCONNECTED" "False" "URL" "https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip"
                    SOURCE_DIR          "C:/Users/Public/ClionProjects_C++/OOP_cpp/Lab1.BigInt/cmake-build-debug/_deps/gtest-src"
                    BINARY_DIR          "C:/Users/Public/ClionProjects_C++/OOP_cpp/Lab1.BigInt/cmake-build-debug/_deps/gtest-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)


