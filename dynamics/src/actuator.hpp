
#pragma once

#include "actuator.h"
#include "mass.hpp"


namespace dynamics {

    template <std::size_t NDimensions>
    Actuator<NDimensions>::Actuator(const TMass& lhs, const TMass& rhs) : _lh_mass(lhs), _rh_mass(rhs) {
    }

    template <std::size_t NDimensions>
    Actuator<NDimensions>::~Actuator() {}

    template <std::size_t NDimensions>
    void Actuator<NDimensions>::compute() {
        this->_compute();
        _lh_mass -= _lh_force;
        _rh_mass += _rh_force;
    }

    template <std::size_t NDimensions>
    void Actuator<NDimensions>::update() {}

}
