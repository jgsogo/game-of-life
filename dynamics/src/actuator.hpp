
#pragma once

#include "actuator.h"
#include "mass.hpp"


namespace dynamics {

    template <std::size_t NDimensions>
    Actuator<NDimensions>::Actuator(TMass& lhs, TMass& rhs) : _lh_mass(lhs), _rh_mass(rhs) {
        _lh_force = std::make_shared<TForce>();
        _rh_force = std::make_shared<TForce>();
        lhs.add_force(_lh_force);
        rhs.add_force(_rh_force);
    }

    template <std::size_t NDimensions>
    Actuator<NDimensions>::~Actuator() {}

}
