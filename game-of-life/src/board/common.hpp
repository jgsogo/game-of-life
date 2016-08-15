
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
        typename std::enable_if<(N==0), bool>::type
        print_board(std::ostream& os, const array& t) {
            os << t[0];
        }

        template <std::size_t width, std::size_t N, typename array>
        typename std::enable_if<(N!=0), bool>::type
        print_board(std::ostream& os, const array& t) {
            print_board<width, N-1>(os, t);
            if( N % width == 0 ) os << std::endl;
            os << t[N];
        }

    }
}
