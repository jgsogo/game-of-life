
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

        template <std::size_t width, std::size_t N, typename tuple>
        typename std::enable_if<(N==0), bool>::type
        print_board(std::ostream& os, const tuple& t) {
            os << t[0];
        }

        template <std::size_t width, std::size_t N, typename T>
        typename std::enable_if<(N==0), bool>::type
        print_board(std::ostream& os, const std::vector<std::shared_ptr<T>>& t) {
            t[0]->print(os);
        }

        template <std::size_t width, std::size_t N, typename tuple>
        typename std::enable_if<(N!=0), bool>::type
        print_board(std::ostream& os, const tuple& t) {
            print_board<width, N-1>(os, t);
            if( N % width == 0 ) os << std::endl;
            os << t[N];
        }

        template <std::size_t width, std::size_t N, typename T>
        typename std::enable_if<(N!=0), bool>::type
        print_board(std::ostream& os, const std::vector<std::shared_ptr<T>>& t) {
            print_board<width, N-1>(os, t);
            if( N % width == 0 ) os << std::endl;
            t[N]->print(os);
        }

    }
}
