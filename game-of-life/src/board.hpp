
#pragma once

#include "utils_tuple.hpp"
#include "rules.h"


namespace game_of_life {

    namespace _detail {

        template <std::size_t width, std::size_t N, typename tuple>
        typename std::enable_if<(N==0), bool>::type
        print_board(std::ostream& os, const tuple& t) {
            os << std::get<0>(t);
        }

        template <std::size_t width, std::size_t N, typename tuple>
        typename std::enable_if<(N!=0), bool>::type
        print_board(std::ostream& os, const tuple& t) {
            print_board<width, N-1>(os, t);
            if( N % width == 0 ) os << std::endl;
            os << std::get<N>(t);
        }


    }

    template <std::size_t width, std::size_t height, template <std::size_t, std::size_t> class R, typename T>
    class Board {
        public:
            typedef R<width, height> Rules;
            typedef typename Rules::TGrid Grid;

            Board() {};
            virtual ~Board() {};

            std::size_t alive_neighbours(std::size_t N) const {
                auto idx = Rules::neighbours(N);
            }

            virtual std::ostream& print(std::ostream& os) const {
                _detail::print_board<width, width*height-1>(os, _board);
                return os;
            }

        protected:
            typename utils::create_tuple<width*height, T>::type _board;

    };

}
