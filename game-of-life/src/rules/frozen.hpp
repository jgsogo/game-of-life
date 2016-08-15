
#pragma once


namespace game_of_life {

    class RuleFrozen {
        public:
            static bool next_alive(bool me_alive, std::size_t alive_neighbours) {
                return me_alive;
            }
    };

}
