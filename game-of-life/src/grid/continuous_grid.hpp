
#pragma once

#include "base_grid.hpp"

namespace game_of_life {

    template <std::size_t width, std::size_t height>
    class GridContinuous : public GridBase<width, height> {

        public:
            using GridBase<width, height>::cell_count;
            using GridBase<width, height>::is_top;
            using GridBase<width, height>::is_bottom;
            using GridBase<width, height>::is_left;
            using GridBase<width, height>::is_right;

            static constexpr _t_neighbours neighbours(std::size_t N) {
                return {
                    // left
                    is_left(N) ? (N+width-1) : (N-1),
                    // right
                    is_right(N) ? (N-width+1) : (N+1),
                    // top
                    is_top(N) ? (cell_count-width+N) : (N-width),
                    // top-left
                    (N==0) ? (cell_count-1) : (is_left(N) ? (N-1) : (is_top(N) ? (cell_count -width+N-1) : (N-width-1))),
                    // top-right
                    (N == (width-1)) ? (cell_count - width) : (is_right(N) ? (N - width*2 + 1) : (is_top(N) ? (cell_count - width + N + 1) : (N - width + 1)) ),
                    // bottom
                    (N + width >= cell_count) ? (N + width - cell_count) : (N + width),
                    // bottom-left
                    (N == (cell_count - width)) ? (width - 1) : (is_left(N) ? (N + width*2 - 1) : (is_bottom(N) ? (N + width - cell_count - 1) : (N + width - 1))),
                    // bottom-right
                    (N == (cell_count - 1)) ? (0) : ((N+1) % width == 0 ? (N+1) : (is_bottom(N) ? (N + width - cell_count + 1) : (N+width+1)) )
                };
            }
    };

}

