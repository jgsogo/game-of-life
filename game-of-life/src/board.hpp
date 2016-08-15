
#pragma once

#include <bitset>
#include <algorithm>
#include <memory>
#include "utils_tuple.hpp"
#include "rules.h"
#include "cell.hpp"


namespace game_of_life {

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


    template <std::size_t width, std::size_t height, template <std::size_t, std::size_t> class R, typename T>
    class Board {
        public:
            typedef R<width, height> Rules;
            typedef typename Rules::TGrid Grid;
            typedef Cell<width, height, R, T> CellType;

            Board() {
                initialize(std::bitset<width*height>());
            };
            Board(const std::bitset<width*height>& board) {
                initialize(board);
            };
            virtual ~Board() {};

            std::size_t alive_population() const {
                return std::count_if(_board.begin(), _board.end(), [](auto& item) { return item->is_alive();});
            }

            std::size_t alive_neighbours(std::size_t N) const {
                return _board[N]->alive_neighbours();
            }

            virtual std::ostream& print(std::ostream& os) const {
                _detail::print_board<width, width*height-1>(os, _board);
                return os;
            }

            void next() {
                for (std::size_t i=0; i<width*height; ++i) {
                    _board[i]->next();
                }
            }

        protected:
            void initialize(const std::bitset<width*height>& board) {
                // Create board
                _board.resize(width*height);
                for (std::size_t i=0; i<width*height; ++i) {
                    _board[i] = CellType::make_shared(i, board[i]);
                }

                // Let the cells store data about its neighbours
                for (std::size_t i=0; i<width*height; ++i) {
                    _board[i]->initialize(_board);
                }
            }

        protected:
            std::vector<std::shared_ptr<CellType>> _board;
    };

    template <std::size_t width, std::size_t height, template <std::size_t, std::size_t> class R>
    class Board<width, height, R, bool> {
        public:
            typedef R<width, height> Rules;
            typedef typename Rules::TGrid Grid;

            Board() {};
            Board(const std::bitset<width*height>& board) : _board(board) {};
            virtual ~Board() {};

            std::size_t alive_population() const {
                return _board.count();
            }

            std::size_t alive_neighbours(std::size_t N) const {
                return count_alive(_board, Rules::neighbours(N));
            }

            virtual std::ostream& print(std::ostream& os) const {
                _detail::print_board<width, width*height-1>(os, _board);
                return os;
            }

            void next() {
                std::bitset<width*height> dest;
                for (std::size_t i=0; i<width*height; ++i) {
                    dest[i] = Rules::next_alive( alive_neighbours(i));
                }
                std::swap(dest, _board);
            }

        protected:
            std::bitset<width*height> _board;
    };

}
