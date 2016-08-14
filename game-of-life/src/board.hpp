
#pragma once

#include <bitset>
#include <algorithm>
#include "utils_tuple.hpp"
#include "rules.h"


namespace game_of_life {

    namespace _detail {

        template <std::size_t width, std::size_t N, typename tuple>
        typename std::enable_if<(N==0), bool>::type
        print_board(std::ostream& os, const tuple& t) {
            os << t[0];
        }

        template <std::size_t width, std::size_t N, typename tuple>
        typename std::enable_if<(N!=0), bool>::type
        print_board(std::ostream& os, const tuple& t) {
            print_board<width, N-1>(os, t);
            if( N % width == 0 ) os << std::endl;
            os << t[N];
        }


    }

    template <std::size_t width, std::size_t height, template <std::size_t, std::size_t> class R, typename T>
    class Board {
        public:
            typedef R<width, height> Rules;
            typedef typename Rules::TGrid Grid;

            Board() {};
            Board(const std::bitset<width*height>& board) : _board(board) {};
            virtual ~Board() {};

            std::size_t alive_neighbours(std::size_t N) const {
                return count_alive(_board, Rules::neighbours(N));
            }

            virtual std::ostream& print(std::ostream& os) const {
                _detail::print_board<width, width*height-1>(os, _board);
                return os;
            }

            void next() {
                std::bitset<width*height> n = Rules::next_state(_board);
                std::swap(n, _board);
            }

        protected:
            std::bitset<width*height> _board;
    };

}
