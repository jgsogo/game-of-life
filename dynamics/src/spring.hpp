
#pragma once

#include "actuator.hpp"
#include "mass.hpp"


namespace dynamics {

    template <std::size_t NDimensions>
    class Spring : public Actuator<NDimensions> {
        using TActuator = Actuator<NDimensions>;
        using TMass = typename TActuator::TMass;
        using TVector = vector<NDimensions>;
        public:
            Spring(TMass& lhs, TMass& rhs) : TActuator(lhs, rhs) {}

            ~Spring() {}

            void initialize(float length, const TVector& stiffness) {
                _stiffness = stiffness;
                _length = length;
            }

            void initialize(float length, float stiffness) {
                _stiffness.fill(stiffness);
                _length = length;
            }

            virtual void compute(float delta_t) {
                float x = length(TActuator::_rh_mass.get_position() - TActuator::_lh_mass.get_position());
                TActuator::_rh_force->set(_stiffness*x);
                TActuator::_lh_force->set(_stiffness*-x);
            }

        protected:
            TVector _stiffness;
            float _length;
    };

}
