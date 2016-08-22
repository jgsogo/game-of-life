
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

            void initialize(float length, float stiffness) {
                _stiffness = stiffness;
                _length = length;
            }

            virtual void compute(float delta_t) {
                auto u = TActuator::_rh_mass.get_position() - TActuator::_lh_mass.get_position();
                auto len_u = length(u);
                if (len_u > .001f) {
                    float force = (_length - len_u)*_stiffness;
                    auto v_unitario = u/len_u;
                    TActuator::_rh_force->set(v_unitario*force);
                    TActuator::_lh_force->set(v_unitario*-force);
                }
                else {
                    TActuator::_rh_force->set(TVector{});
                    TActuator::_lh_force->set(TVector{});
                }
            }

        protected:
            float _stiffness;
            float _length;
    };

}
