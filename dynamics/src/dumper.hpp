
#pragma once

#include "actuator.hpp"
#include "mass.hpp"


namespace dynamics {

    template <std::size_t NDimensions>
    class Dumper : public Actuator<NDimensions> {
        using TActuator = Actuator<NDimensions>;
        using TMass = typename TActuator::TMass;
        using TVector = vector<NDimensions>;
        public:
            Dumper(TMass& lhs, TMass& rhs) : TActuator(lhs, rhs) {}

            ~Dumper() {}

            void initialize(float damping) {
                _damping = damping;
            }

            virtual void compute(float delta_t) {
                auto u = TActuator::_rh_mass.get_position() - TActuator::_lh_mass.get_position();
                auto len_u = length(u);
                if (len_u > .001f) {
                    auto v = TActuator::_rh_mass.get_speed() - TActuator::_lh_mass.get_speed();
                    float force = ((dot_product(u, v) >= 0) ? 1 : -1)*length(v)*_damping;
                    auto v_unitario = u/len_u;
                    TActuator::_rh_force->set(v_unitario*-force);
                    TActuator::_lh_force->set(v_unitario*force);
                }
                else {
                    TActuator::_rh_force->set(TVector{});
                    TActuator::_lh_force->set(TVector{});
                }
            }

        protected:
            float _damping;
    };

}
