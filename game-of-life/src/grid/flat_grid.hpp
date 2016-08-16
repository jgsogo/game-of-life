
#pragma once

#include "base_grid.hpp"

namespace game_of_life {

    template <std::size_t width, std::size_t height>
    class GridFlat : public GridBase<width, height> {

        public:
            using GridBase<width, height>::cell_count;
            using GridBase<width, height>::is_top;
            using GridBase<width, height>::is_bottom;
            using GridBase<width, height>::is_left;
            using GridBase<width, height>::is_right;

            static _t_neighbours neighbours(std::size_t N) {
                _t_neighbours r{
                    // left
                    is_left(N) ? no_neighbour : (N-1),
                    // right
                    is_right(N) ? no_neighbour : (N+1),
                    // top
                    is_top(N) ? no_neighbour : (N-width),
                    // top-left
                    is_top(N) ? no_neighbour : (is_left(N) ? no_neighbour : (N-width-1)),
                    // top-right
                    is_top(N) ? no_neighbour : (is_right(N) ? no_neighbour : (N-width+1)),
                    // bottom
                    is_bottom(N) ? no_neighbour : (N+width),
                    // bottom-left
                    is_bottom(N) ? no_neighbour : (is_left(N) ? no_neighbour : (N+width-1)),
                    // bottom-right
                    is_bottom(N) ? no_neighbour : (is_right(N) ? no_neighbour : (N+width+1))
                };
                r.erase(no_neighbour);
                return r;
            }
    };

}

