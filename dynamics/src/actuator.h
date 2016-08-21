
#pragma once

#include "mass.h"
#include "force.hpp"

namespace dynamics {

    template <std::size_t NDimensions>
    class Actuator {
        protected:
            using TMass = Mass<NDimensions>;
            using TForce = Force<NDimensions>;

        public:
            Actuator(TMass& lhs, TMass& rhs);
            virtual ~Actuator();

            virtual void compute(float delta_t) = 0;

        protected:
            const TMass& _lh_mass;
            const TMass& _rh_mass;
            std::shared_ptr<TForce> _lh_force;
            std::shared_ptr<TForce> _rh_force;
    };

}
