
#pragma once

#include <memory>
#include <vector>
#include <algorithm>
#include <iomanip>

namespace game_of_life {

    template <std::size_t width, std::size_t height,
              class TRules,
              template <std::size_t, std::size_t> class TGrid,
              class T>
    class Cell {
        using TCell = Cell<width, height, TRules, TGrid, T>;
        typedef std::array<TCell, width*height> TContainer;

        public:
            typedef TRules Rules;
            typedef TGrid<width, height> Grid;

        public:
            Cell() {};  // TODO: Remove this default constructor. All cells must have an index.
            Cell(const Cell& other) :
                _idx(other._idx),
                _is_alive(other._is_alive) {
            };
            Cell(std::size_t idx, bool alive) :
                _idx(idx),
                _is_alive(alive) {
            };
            virtual ~Cell() {};

            static TCell build(std::size_t i, bool alive=false) {
                return TCell(i, alive);
            }

            void initialize(const TContainer& board) {
                for (auto n: Grid::neighbours(_idx)) {
                    _neighbours.push_back(&board[n]);
                }
            }

            std::size_t alive_neighbours() const {
                return std::count_if(_neighbours.begin(), _neighbours.end(), [](const TCell* item) {
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
                os << std::setw(3) << (_is_alive ? " X " : " 0 ");
            }
        protected:
            std::size_t _idx;
            bool _is_alive;
            T _data;
            std::vector<const TCell*> _neighbours;
    };

}

template<class Ch, class Tr,
              std::size_t width, std::size_t height,
              class TRules,
              template <std::size_t, std::size_t> class TGrid,
              class T>
auto operator<<(std::basic_ostream<Ch, Tr>& os, const game_of_life::Cell<width, height, TRules, TGrid, T>& t)
    -> std::basic_ostream<Ch, Tr>& {
    t.print(os);
    return os;
}


