project(GameOfLife)
cmake_minimum_required(VERSION 2.8.12)

# All tests in one test project.
file(GLOB test_files "test_*.cpp")

add_executable (test_dynamics main.cpp ${test_files})
target_link_libraries (test_dynamics
                       ${Boost_LIBRARIES})

add_test(NAME TestDynamics COMMAND $<TARGET_FILE:test_dynamics>)
