
#pragma once

#include <bitset>
#include <algorithm>
#include "common.hpp"


namespace game_of_life {

    template <std::size_t width, std::size_t height,
              class TRules,
              template <std::size_t, std::size_t> class TGrid>
    class Board<width, height, TRules, TGrid, bool> {
        public:
            typedef TRules Rules;
            typedef TGrid<width, height> Grid;

            Board() {};
            Board(const std::bitset<width*height>& board) : _board(board) {};
            virtual ~Board() {};

            std::size_t alive_population() const {
                return _board.count();
            }

            std::size_t alive_neighbours(std::size_t N) const {
                auto neighbours = Grid::neighbours(N);
                return std::count_if(neighbours.begin(), neighbours.end(),
                                    [this](std::size_t idx) {
                                        return _board[idx];
                                    });
            }

            virtual std::ostream& print(std::ostream& os) const {
                _detail::print_board<width, width*height-1>(os, _board);
                return os;
            }

            void next() {
                std::bitset<width*height> dest;
                for (std::size_t i=0; i<width*height; ++i) {
                    dest[i] = Rules::next_alive(_board[i], alive_neighbours(i));
                }
                std::swap(dest, _board);
            }

            std::bitset<width*height> get_state() const {
                return _board;
            }

        protected:
            std::bitset<width*height> _board;
    };


}
