
#pragma once

#include "mass.h"


namespace dynamics {

    template <std::size_t NDimensions>
    Mass<NDimensions>::Mass(float mass) : _mass(mass), _position{}, _speed{} {}

    template <std::size_t NDimensions>
    Mass<NDimensions>::Mass(float mass, const TVector& position) :
        _mass(mass),
        _position(position),
        _speed{} {
    }

    template <std::size_t NDimensions>
    Mass<NDimensions>::~Mass() {}

    template <std::size_t NDimensions>
    void Mass<NDimensions>::compute() {
    }

    template <std::size_t NDimensions>
    void Mass<NDimensions>::update() {
    }

}
