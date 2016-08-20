project(GameOfLife)

cmake_minimum_required(VERSION 2.8.12)

file(GLOB engine_SRC
    "src/*.h"
    "src/*.cpp"
    "src/*.hpp"
)

add_library(engine ${engine_SRC})
target_include_directories(engine PUBLIC ${CONAN_INCLUDE_DIRS_GAME-OF-LIFE})
set_target_properties(engine PROPERTIES LINKER_LANGUAGE CXX)


add_subdirectory(examples)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()
