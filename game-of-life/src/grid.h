
#pragma once


namespace game_of_life {

    template <std::size_t width, std::size_t height>
    class Grid {
        public:
            static constexpr int cell_count = width*height;

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
    };

}

