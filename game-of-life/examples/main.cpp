
#include <iostream>
#include "../src/grid.h"
#include "../src/rules.h"
#include "../src/cell.hpp"
#include "../src/board.hpp"

using namespace game_of_life;

int main() {
    std::cout << "=== Game Of Life ===" << std::endl;

    typedef Grid<4,4> MyGrid;

    for (std::size_t i = 0; i<4; ++i) {
        for (std::size_t j = 0; j<4; ++j) {
            std::cout << (MyGrid::is_top(i*4 + j) ? "T" : " ");
            std::cout << (MyGrid::is_bottom(i*4 + j) ? "B" : " ");
            std::cout << (MyGrid::is_left(i*4 + j) ? "L" : " ");
            std::cout << (MyGrid::is_right(i*4 + j) ? "R" : " ");
        }
        std::cout << std::endl;
    }

    std::cout << "\nRuleCornway" << std::endl;
    typedef RuleCornway<4,4> MyRules;
    std::cout << MyRules::neighbours(2) << std::endl;

    std::cout << "\nRuleFlatWorld" << std::endl;
    typedef RuleFlatBoard<4,4> MyRuleFlatBoard;
    std::cout << MyRuleFlatBoard::neighbours(2) << std::endl;

    std::cout << "\nBOARD - RuleCornway" << std::endl;
    typedef Board<4,4,RuleCornway, bool> CornwayBoard;
    CornwayBoard board;
    board.print(std::cout);
    std::cout << std::endl;
    
}
