
#pragma once

#include "actuator.hpp"
#include "mass.hpp"


namespace dynamics {

    template <std::size_t NDimensions>
    class Dumper : public Actuator<NDimensions> {
        using TActuator = Actuator<NDimensions>;
        public:
            Dumper(const Mass& lhs, const Mass& rhs) : TActuator(lhs, rhs) {}

            ~Dumper() {}

            void initialize(std::array<float, NDimensions> damping) {
                _damping = damping;
            }

            void initialize(float damping) {
                _damping.fill(damping);
            }

        protected:
            std::array<float, NDimensions> _damping;
    };

}
