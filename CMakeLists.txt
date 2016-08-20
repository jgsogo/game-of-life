project(GameOfLife)
cmake_minimum_required(VERSION 2.8.12)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")  # Needed for Travis CI
add_compile_options(-std=c++14) # CMake 2.8.12 or newer

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Files in subdirectories
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Include our cmake macros
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include (CMakeHelpers)


OPTION(SPDLOG_DEBUG_ON "Enable debug logging" OFF) # Disabled by default
IF(SPDLOG_DEBUG_ON)
    ADD_DEFINITIONS(-DSPDLOG_DEBUG_ON)
ENDIF(SPDLOG_DEBUG_ON)

set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)


option(BUILD_TESTS "Build test" OFF)
if (BUILD_TESTS)
    # Testing
    enable_testing()
    if (UNIX)
        add_definitions(-Wfatal-errors)
        add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1
                          ${CMAKE_CTEST_COMMAND} --verbose
                          WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
    else()
        add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1
                          ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
                          WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
    endif()

    find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
    include_directories (${Boost_INCLUDE_DIRS})

    # Let's look for all test directories (they have to be called 'tests')!
    message(${CMAKE_CURRENT_SOURCE_DIR})
    file (GLOB_RECURSE MATCHED_ITEMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*/tests/CMakeLists.txt" "*/*/tests/CMakeLists.txt")
    foreach (ITEM ${MATCHED_ITEMS})
        string(REGEX REPLACE "/CMakeLists.txt" "" ITEM ${ITEM})
        message("Add tests in ${CMAKE_CURRENT_SOURCE_DIR}/${ITEM}")
        # add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/${ITEM}")
    endforeach()
endif()

add_subdirectory(engine)
add_subdirectory(desktop)

