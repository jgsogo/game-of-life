
#pragma once

#include "../grid/continuous_grid.hpp"


namespace game_of_life {

    class RuleCornway {
        public:
            static bool next_alive(bool me_alive, std::size_t alive_neighbours) {
                return (alive_neighbours == 2) || (alive_neighbours == 3);
            }

    };

}
