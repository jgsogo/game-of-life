project(GameOfLife)

cmake_minimum_required(VERSION 3.0.2)

# More verbose: https://gitlab.com/Gluttton/SOS/blob/master/25989448/suggested/CMakeLists.txt

find_package(Qt5Widgets)  # This works with Conan, great!

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(mainwindow mainwindow.cpp glwidget.cpp helper.cpp widget.cpp)
target_link_libraries (mainwindow Qt5::Widgets)

add_executable(MyProject main.cpp)
target_link_libraries (MyProject mainwindow)
