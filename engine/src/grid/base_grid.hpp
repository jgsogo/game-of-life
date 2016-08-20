
#pragma once

#include <set>
#include <iostream>

namespace game_of_life {

    constexpr std::size_t no_neighbour = (std::size_t)-1;
    typedef std::set<std::size_t> _t_neighbours;


    template <std::size_t width, std::size_t height>
    class GridBase {
        public:
            static constexpr std::size_t cell_count = width*height;

        public:
            GridBase() {}
            virtual ~GridBase() {}

            static constexpr bool is_top(std::size_t N) {
                return N < width;
            }
            static constexpr bool is_bottom(std::size_t N) {
                return (N + width) >= cell_count;
            }
            static constexpr bool is_left(std::size_t N) {
                return N % width == 0;
            }
            static constexpr bool is_right(std::size_t N) {
                return (N + 1) % width == 0;
            }
    };

}

template<class Ch, class Tr>
auto operator<<(std::basic_ostream<Ch, Tr>& os, const game_of_life::_t_neighbours& t)
    -> std::basic_ostream<Ch, Tr>& {
    os << "{";
    for (auto& item: t)
    {
        os << item << ",";
    }
    return os << "}";
}

