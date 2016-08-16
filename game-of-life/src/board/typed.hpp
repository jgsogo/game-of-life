
#pragma once

#include <array>
#include "common.hpp"
#include "cell.hpp"

namespace game_of_life {

    template <std::size_t width, std::size_t height,
              class TRules,
              template <std::size_t, std::size_t> class TGrid,
              typename T>
    class Board {
        public:
            typedef TRules Rules;
            typedef TGrid<width, height> Grid;
            typedef Cell<width, height, TRules, TGrid, T> CellType;

            Board() {
                initialize(std::bitset<width*height>());
            };
            Board(const std::bitset<width*height>& board) {
                initialize(board);
            };

            virtual ~Board() {};

            std::size_t alive_population() const {
                return std::count_if(_board.begin(), _board.end(), [](auto& item) { return item.is_alive();});
            }

            std::size_t alive_neighbours(std::size_t N) const {
                return _board[N].alive_neighbours();
            }

            virtual std::ostream& print(std::ostream& os) const {
                _detail::print_board<width, width*height-1>(os, _board);
                return os;
            }

            void next() {
                for (std::size_t i=0; i<width*height; ++i) {
                    _board[i].next();
                }
            }

            std::bitset<width*height> get_state() const {
                return _board;
            }

        protected:
            void initialize(const std::bitset<width*height>& board) {
                // Create board
                for (std::size_t i=0; i<width*height; ++i) {
                    _board[i] = CellType::build(i, board[i]);
                }

                // Let the cells store data about its neighbours
                for (std::size_t i=0; i<width*height; ++i) {
                    _board[i].initialize(_board);
                }
            }

        protected:
            std::array<CellType, width*height> _board;
    };

}
