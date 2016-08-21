
#pragma once

#include "actuator.hpp"
#include "mass.hpp"


namespace dynamics {

    template <std::size_t NDimensions>
    class Dumper : public Actuator<NDimensions> {
        using TActuator = Actuator<NDimensions>;
        using TMass = typename TActuator::TMass;
        public:
            Dumper(TMass& lhs, TMass& rhs) : TActuator(lhs, rhs) {}

            ~Dumper() {}

            void initialize(std::array<float, NDimensions> damping) {
                _damping = damping;
            }

            void initialize(float damping) {
                _damping.fill(damping);
            }

            virtual void compute(float delta_t) {
                auto diffv = TActuator::_rh_mass.get_speed() - TActuator::_lh_mass.get_speed();
                TActuator::_rh_force->set(-_damping*diffv);
                TActuator::_lh_force->set( _damping*diffv);
            }

        protected:
            std::array<float, NDimensions> _damping;
    };

}
