
#pragma once

#include "mass.h"

namespace dynamics {

    template <std::size_t NDimensions>
    class Actuator {
        using TMass = Mass<NDimensions>;
        public:
            Actuator(const TMass& lhs, const TMass& rhs);
            virtual ~Actuator();

            void compute();
            virtual void update();

        protected:
            virtual void _compute() = 0;

        protected:
            const TMass& _lh_mass;
            const TMass& _rh_mass;
            std::array<float, NDimensions> _lh_force;
            std::array<float, NDimensions> _rh_force;
    };

}
