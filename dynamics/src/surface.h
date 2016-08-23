
#pragma once

#include "../../engine/src/grid.h"

#include "system.hpp"
#include "spring.hpp"
#include "dumper.hpp"


namespace dynamics {

    template <std::size_t width, std::size_t height,
              template <std::size_t, std::size_t> class Grid = game_of_life::GridContinuous>
    class Surface : public System<1ul> {
        using TMass = Mass<1ul>;
        using TPosition = System<1ul>::TPosition;
        using TGrid = Grid<width, height>;
        public:
            Surface() {};
            ~Surface() {};

            void initialize() {
                float mass = 1.f;
                float stiffness = 1.f;
                float damping = std::sqrt(4*stiffness*mass)*0.5f;

                // Floor item
                auto& mass_floor = this->add_mass<MassFixed>(TPosition{});

                // Create all mass items, and attach them to floor
                for (std::size_t i = 0; i<width*height; ++i) {
                    auto& m = this->add_mass<Mass>(mass, TPosition{}); // Unit mass for each cell
                    auto& s1 = this->add_actuator<dynamics::Spring>(mass_floor, m);
                    s1.initialize(0.f, stiffness);
                    auto& c1 = this->add_actuator<dynamics::Dumper>(mass_floor, m);
                    c1.initialize(damping);
                }

                // Attach mass to neighbours
                for (std::size_t i = 1; i<width*height+1; ++i) {
                    auto neighbours = TGrid::neighbours(i-1);
                    for (auto it: neighbours) {
                        auto& s = this->add_actuator<dynamics::Spring>(*_mass[it], *_mass[i]);
                        s.initialize(0.f, stiffness);
                    }
                }
            }

            const TMass& get_mass(std::size_t i) {
                return *_mass[i];
            }

        protected:
    };
}
