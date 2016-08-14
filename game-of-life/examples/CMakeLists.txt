project(GameOfLife)

cmake_minimum_required(VERSION 2.8.12)

add_executable(game_of_life main.cpp
                            log_level_param.hpp)
target_include_directories(game_of_life PUBLIC ${CONAN_INCLUDE_DIRS_GAME-OF-LIFE})
target_link_libraries(game_of_life
                      ${CONAN_LIBS}
                      gameoflife
                      ${Boost_LIBRARIES}
                      Threads::Threads)
