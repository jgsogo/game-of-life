project(GameOfLife)

cmake_minimum_required(VERSION 2.8.12)

add_executable(engine_example main.cpp
                              log_level_param.hpp)
target_include_directories(engine_example PUBLIC ${CONAN_INCLUDE_DIRS_GAME-OF-LIFE})
target_link_libraries(engine_example
                      ${CONAN_LIBS}
                      # engine
                      ${Boost_LIBRARIES}
                      Threads::Threads)


