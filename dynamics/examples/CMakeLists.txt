project(GameOfLife)

cmake_minimum_required(VERSION 2.8.12)

add_executable(dynamics_example main.cpp)
target_include_directories(dynamics_example PUBLIC ${CONAN_INCLUDE_DIRS_GAME-OF-LIFE})
target_link_libraries(dynamics_example
                      ${CONAN_LIBS}
                      # engine
                      ${Boost_LIBRARIES}
                      Threads::Threads)


