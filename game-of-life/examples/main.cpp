
#include <iostream>
#include "../src/grid.h"
#include "../src/cell.hpp"

int main() {
    std::cout << "Here I'm" << std::endl;

    typedef game_of_life::Grid<4,4, int> MyGrid;

    for (std::size_t i = 0; i<4; ++i) {
        for (std::size_t j = 0; j<4; ++j) {
            std::cout << (MyGrid::is_top(i*4 + j) ? "X" : "0");
            std::cout << (MyGrid::is_top(i*4 + j) ? "X" : "0");
        }
        std::cout << std::endl;
    }

    std::cout << MyGrid::neighbours(2) << std::endl;

}
