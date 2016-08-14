
#pragma once

#include <tuple>
#include "utils_tuple.hpp"


namespace game_of_life {

    template <std::size_t N, std::size_t width, std::size_t height>
    struct Cell {
        static constexpr int cell_count = width*height;
        static constexpr bool is_top = N < cell_count;
        static constexpr bool is_bottom = (N + width) >= cell_count;
        static constexpr bool is_left = N % width == 0;
        static constexpr bool is_right = (N + 1) % width == 0;
    };

}

