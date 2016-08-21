project(GameOfLife)
cmake_minimum_required(VERSION 2.8.12)

# All tests in one test project.
file(GLOB engine_test_files "test_*.cpp")

#add_executable (test_engine main.cpp ${engine_test_files})
#target_link_libraries (test_engine                       
#                       ${Boost_LIBRARIES})

#add_test(NAME TestEngine COMMAND $<TARGET_FILE:test_engine>)
