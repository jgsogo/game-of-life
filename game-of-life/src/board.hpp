
#pragma once

#include "utils_tuple.hpp"


namespace game_of_life {

    template <std::size_t width, std::size_t height, template <std::size_t, std::size_t> class R, typename T>
    class Board {
        public:
            typedef R<width, height> Rules;
            typedef typename Rules::TGrid Grid;

            Board() {};
            virtual ~Board() {};

            static std::size_t count_neighbours(std::size_t N) {
                typename Rules::_t_neighbours neighbours = Rules::neighbours(N);
                return std::size_t(2);
            }

        protected:
            typename utils::create_tuple<width*height, T>::type _board;

    };

}
