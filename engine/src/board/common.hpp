
#pragma once

#include <iostream>
#include <vector>
#include <memory>

namespace game_of_life {

    template <std::size_t width, std::size_t height,
              class TRules,
              template <std::size_t, std::size_t> class TGrid,
              typename T = void>
    class Board;


    namespace _detail {

        template <std::size_t width, std::size_t N, typename array>
        std::ostream& print_board(std::ostream& os, const array& t) {
            for (std::size_t i = 0; i<N; ++i) {
                os << t[i];
                if (i% width == 0) os << std::endl;
            }
            return os;
        }

    }
}
