
#pragma once

#include <memory>
#include "utils_tuple.hpp"


namespace game_of_life {

    template <std::size_t width, std::size_t height, template <std::size_t, std::size_t> class R, class T>
    class Cell {
        public:
            typedef R<width, height> Rules;
            typedef typename Rules::TGrid Grid;

            const bool is_top;
            const bool is_bottom;
            const bool is_left;
            const bool is_right;

        public:
            Cell(std::size_t idx, bool alive) :
                _idx(idx),
                _is_alive(alive),
                is_top(Grid::is_top(idx)),
                is_bottom(Grid::is_top(idx)),
                is_left(Grid::is_top(idx)),
                is_right(Grid::is_top(idx)) {
            };
            virtual ~Cell() {};

            static std::shared_ptr<Cell<width, height, R, T>> make_shared(std::size_t i, bool alive=false) {
                return std::make_shared<Cell<width, height, R, T>>(i, alive);
            }

            void initialize(const std::vector<std::shared_ptr<Cell<width, height, R, T>>>& board) {
                for (auto n: Rules::neighbours(_idx)) {
                    _neighbours.push_back(board[n]);
                }
            }

            std::size_t alive_neighbours() const {
                return std::count_if(_neighbours.begin(), _neighbours.end(), [](const std::shared_ptr<Cell<width, height, R, T>>& item) {
                    return item->is_alive();
                });
            }

            bool is_alive() const {
                return _is_alive;
            }

            void next() {
                _is_alive = Rules::next_alive(alive_neighbours());
            }

            void print(std::ostream& os) const {
                os << (_is_alive ? "X" : "0");
            }
        protected:
            std::size_t _idx;
            bool _is_alive;
            T _data;
            std::vector<std::shared_ptr<Cell<width, height, R, T>>> _neighbours;
    };

}
