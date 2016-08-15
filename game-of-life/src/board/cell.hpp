
#pragma once

#include <memory>
#include <vector>
#include <algorithm>


namespace game_of_life {

    template <std::size_t width, std::size_t height,
              class TRules,
              template <std::size_t, std::size_t> class TGrid,
              class T>
    class Cell {
        using TCell = Cell<width, height, TRules, TGrid, T>;
        public:
            typedef TRules Rules;
            typedef TGrid<width, height> Grid;

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

            static std::shared_ptr<TCell> make_shared(std::size_t i, bool alive=false) {
                return std::make_shared<TCell>(i, alive);
            }

            void initialize(const std::vector<std::shared_ptr<TCell>>& board) {
                for (auto n: Grid::neighbours(_idx)) {
                    _neighbours.push_back(board[n]);
                }
            }

            std::size_t alive_neighbours() const {
                return std::count_if(_neighbours.begin(), _neighbours.end(), [](const std::shared_ptr<TCell>& item) {
                    return item->is_alive();
                });
            }

            bool is_alive() const {
                return _is_alive;
            }

            void next() {
                _is_alive = Rules::next_alive(_is_alive, alive_neighbours());
            }

            void print(std::ostream& os) const {
                os << (_is_alive ? "X" : "0");
            }
        protected:
            std::size_t _idx;
            bool _is_alive;
            T _data;
            std::vector<std::shared_ptr<TCell>> _neighbours;
    };

}
