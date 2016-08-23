
#pragma once

#include "system.hpp"
#include "spring.hpp"
#include "dumper.hpp"

namespace dynamics {

    template <std::size_t width, std::size_t height>
    class Surface : public System<1ul> {
        using TMass = Mass<1ul>;
        using TVector = System<1ul>::TVector;
        public:
            Surface();
            ~Surface();
            void initialize() {
                float mass = 1.f;
                float stiffness = 1.f;
                float damping = std::sqrt(4*stiffness*mass)*0.5f;

                // Floor item
                auto& mass_floor = this->add_mass<MassFixed<1ul>>(TVector{});

                // Create all mass items, and attach them to floor
                for (std::size_t i = 0; i<width*heigh; ++i) {
                    auto& m = this->add_mass<TMass>(mass); // Unit mass for each cell
                    auto& s1 = this->add_actuator<dynamics::Spring>(mass_floor, m);
                    s1.initialize(0.f, stiffness);
                    auto& c1 = this->add_actuator<dynamics::Dumper>(mass_floor, m);
                    c1.initialize(damping);
                }

                // Attach mass to neighbours
                for (std::size_t i = 0; i<width*heigh; ++i) {

                }
            }

        protected:
            std::array<std::shared_ptr<TMass>, width*height> _surface;
    };
}