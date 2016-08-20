project(GameOfLife)

cmake_minimum_required(VERSION 2.8.12)

file(GLOB gameoflife_SRC
    "src/*.h"
    "src/*.cpp"
    "src/*.hpp"
)

add_library(gameoflife ${gameoflife_SRC})
target_include_directories(gameoflife PUBLIC ${CONAN_INCLUDE_DIRS_GAME-OF-LIFE})
set_target_properties(gameoflife PROPERTIES LINKER_LANGUAGE CXX)


add_subdirectory(examples)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()
