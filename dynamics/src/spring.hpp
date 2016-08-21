
#pragma once

#include "actuator.hpp"
#include "mass.hpp"


namespace dynamics {

    template <std::size_t NDimensions>
    class Spring : public Actuator<NDimensions> {
        using TActuator = Actuator<NDimensions>;
        using TMass = Mass<NDimensions>;
        using TVector = vector<NDimensions>;
        public:
            Spring(const TMass& lhs, const TMass& rhs) : TActuator(lhs, rhs) {}

            ~Spring() {}

            void initialize(float length, const TVector& stiffness) {
                _stiffness = stiffness;
                _length = length;
            }

            void initialize(float length, float stiffness) {
                _stiffness.fill(stiffness);
                _length = length;
            }

            virtual void _compute() {

            }

        protected:
            TVector _stiffness;
            float _length;
    };

}
