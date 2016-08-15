
#include <iostream>
#include "../src/grid.h"
#include "../src/rules.h"
#include "../src/board.hpp"

using namespace game_of_life;

int main() {
    std::cout << "=== Game Of Life ===" << std::endl;
    const std::size_t width = 8;
    const std::size_t height = 5;

    typedef GridBase<width,height> MyGrid;

    for (std::size_t i = 0; i<height; ++i) {
        for (std::size_t j = 0; j<width; ++j) {
            std::cout << (MyGrid::is_top(i*width + j) ? "T" : " ");
            std::cout << (MyGrid::is_bottom(i*width + j) ? "B" : " ");
            std::cout << (MyGrid::is_left(i*width + j) ? "L" : " ");
            std::cout << (MyGrid::is_right(i*width + j) ? "R" : " ");
        }
        std::cout << std::endl;
    }

    std::cout << "\nGridContinuous" << std::endl;
    typedef GridContinuous<width,height> MyGridContinuous;
    std::cout << MyGridContinuous::neighbours(2) << std::endl;

    std::cout << "\nGridFlat" << std::endl;
    typedef GridFlat<width,height> MyGridFlat;
    std::cout << MyGridFlat::neighbours(2) << std::endl;

    std::bitset<width*height> initial;
    initial[0] = true;
    initial[1] = true;
    initial[8] = true;

    {
        std::cout << "\nGridFlat - RuleConway" << std::endl;
        typedef Board<width, height, RuleConway, GridFlat, int> ConwayFlatBoard;
        ConwayFlatBoard board(initial);

        for (std::size_t i = 0; i< 4; ++i) {
            board.print(std::cout);
            std::cout << std::endl;
            std::cout << board.alive_population() << std::endl << std::endl;
            board.next();
        }
    }

    {
        std::cout << "\nGridContinuous - RuleConway" << std::endl;
        typedef Board<width, height, RuleConway, GridContinuous, bool> Board;
        Board board(initial);

        for (std::size_t i = 0; i< 4; ++i) {
            board.print(std::cout);
            std::cout << std::endl;
            std::cout << board.alive_population() << std::endl << std::endl;
            board.next();
        }
    }

}
