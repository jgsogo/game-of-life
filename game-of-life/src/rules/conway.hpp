
#pragma once

#include "../grid/continuous_grid.hpp"


namespace game_of_life {

    class RuleConway {
        public:
            static bool next_alive(bool me_alive, std::size_t alive_neighbours) {
                return (!me_alive && alive_neighbours == 3) || (me_alive && (alive_neighbours == 2 || alive_neighbours == 3));
            }

    };

}
