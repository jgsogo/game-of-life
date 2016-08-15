
#pragma once

#include <tuple>
#include <set>
#include <bitset>
#include <algorithm>

#include "utils_tuple.hpp"
#include "grid.h"


namespace game_of_life {

    constexpr std::size_t no_neighbour = (std::size_t)-1;
    typedef std::set<std::size_t> _t_neighbours;

    template <typename data>
    std::size_t count_alive(const data& board, const _t_neighbours& neighbours) {
        return std::count_if(neighbours.begin(), neighbours.end(), [&board](std::size_t idx) { return (idx != no_neighbour) && board[idx];});
    }

    template <std::size_t width, std::size_t height>
    class RuleCornway {
        public:
            using TGrid = Grid<width, height>;
            static constexpr int cell_count = width*height;

            static constexpr _t_neighbours neighbours(std::size_t N) {
                return {
                    // left
                    TGrid::is_left(N) ? (N+width-1) : (N-1),
                    // right
                    TGrid::is_right(N) ? (N-width+1) : (N+1),
                    // top
                    TGrid::is_top(N) ? (cell_count-width+N) : (N-width),
                    // top-left
                    (N==0) ? (cell_count-1) : (TGrid::is_left(N) ? (N-1) : (TGrid::is_top(N) ? (cell_count -width+N-1) : (N-width-1))),
                    // top-right
                    (N == (width-1)) ? (cell_count - width) : (TGrid::is_right(N) ? (N - width*2 + 1) : (TGrid::is_top(N) ? (cell_count - width + N + 1) : (N - width + 1)) ),
                    // bottom
                    (N + width >= cell_count) ? (N + width - cell_count) : (N + width),
                    // bottom-left
                    (N == (cell_count - width)) ? (width - 1) : (TGrid::is_left(N) ? (N + width*2 - 1) : (TGrid::is_bottom(N) ? (N + width - cell_count - 1) : (N + width - 1))),
                    // bottom-right
                    (N == (cell_count - 1)) ? (0) : ((N+1) % width == 0 ? (N+1) : (TGrid::is_bottom(N) ? (N + width - cell_count + 1) : (N+width+1)) )
                };
            }

            static bool next_alive(std::size_t alive_neighbours) {
                return (alive_neighbours == 2) || (alive_neighbours == 3);
            }

    };

    template <std::size_t width, std::size_t height>
    class RuleFlatBoard {
        public:
            using TGrid = Grid<width, height>;
            static constexpr int cell_count = width*height;

            static constexpr _t_neighbours neighbours(std::size_t N) {
                _t_neighbours r{
                    // left
                    TGrid::is_left(N) ? no_neighbour : (N-1),
                    // right
                    TGrid::is_right(N) ? no_neighbour : (N+1),
                    // top
                    TGrid::is_top(N) ? no_neighbour : (N-width),
                    // top-left
                    TGrid::is_top(N) ? no_neighbour : (TGrid::is_left(N) ? no_neighbour : (N-width-1)),
                    // top-right
                    TGrid::is_top(N) ? no_neighbour : (TGrid::is_right(N) ? no_neighbour : (N-width+1)),
                    // bottom
                    TGrid::is_bottom(N) ? no_neighbour : (N+width),
                    // bottom-left
                    TGrid::is_bottom(N) ? no_neighbour : (TGrid::is_left(N) ? no_neighbour : (N+width-1)),
                    // bottom-right
                    TGrid::is_bottom(N) ? no_neighbour : (TGrid::is_right(N) ? no_neighbour : (N+width+1))
                };
                r.erase(no_neighbour);
                return r;
            }

            static bool next_alive(std::size_t alive_neighbours) {
                return (alive_neighbours == 2) || (alive_neighbours == 3);
            }

    };

}


template<class Ch, class Tr, class... Args>
auto operator<<(std::basic_ostream<Ch, Tr>& os, const game_of_life::_t_neighbours& t)
    -> std::basic_ostream<Ch, Tr>& {
    os << "{";
    for (auto& item: t)
    {
        os << item << ",";
    }
    return os << "}";
}
