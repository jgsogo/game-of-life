
#pragma oncei

#include <tuple>
#include "utils_tuple.hpp"
#include "cell.hpp"


namespace game_of_life {

    template <std::size_t width, std::size_t height, typename T>
    class Grid {
        public:
            template <std::size_t N> using Cell = Cell<N, width, height>;

            static constexpr int cell_count = width*height;
            typedef typename utils::create_tuple<4, std::size_t>::type _t_neighbours;

        public:
            Grid() {}
            virtual ~Grid() {}

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

            
            static constexpr _t_neighbours neighbours(std::size_t N) {
                return std::make_tuple(
                    // left
                    is_left(N) ? (N+width-1) : (N-1),
                    // right
                    is_right(N) ? (N-width+1) : (N+1),
                    // top
                    is_top(N) ? (cell_count-width+N) : (N-width),
                    // top-left
                    (N==0) ? (cell_count-1) : (is_left(N) ? (N-1) : (is_top(N) ? (cell_count -width+N-1) : (N-width-1)))
                );
            };
/*
template <int N>
    using neighbors = tuple
    <
    // maybe these aren't completely correct, needs checking
    // left
    point< is_left(N) ? (N + width - 1) : (N - 1) >,
    // right
    point< is_right(N) ? (N - width + 1) : (N + 1) >,
    // top
    point< is_top(N) ? (point_count - width + N) : (N - width) >,
    // top-left
    point< (N == 0) ? (point_count - 1) : (is_left(N) ? (N - 1) : ( is_top(N) ? (point_count - width + N - 1) : (N - width - 1)) ) >,
    // top-right
    point< (N == (width-1)) ? (point_count - width) : (is_right(N) ? (N - width*2 + 1) : ( is_top(N) ? (point_count - width + N + 1) : (N - width + 1)) ) >,
    // bottom
    point< (N + width >= point_count) ? (N + width - point_count) : (N + width) >,
    // bottom-left
    point< (N == (point_count - width)) ? (width - 1) : (is_left(N) ? (N + width*2 - 1) : (is_bot(N) ? (N + width - point_count - 1) : (N + width - 1))) >,
    // bottom-right
    point< (N == (point_count - 1)) ? (0) : ((N+1) % width == 0 ? (N+1) : (is_bot(N) ? (N + width - point_count + 1) : (N+width+1)) )>
    >;
*/
        protected:

            typename utils::create_tuple<width*height, T>::type _board;
    };

}

