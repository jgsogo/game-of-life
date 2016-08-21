
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
    void Mass<NDimensions>::add_force(std::shared_ptr<TForce> force) {
        _forces.push_back(force);
    }

    template <std::size_t NDimensions>
    void Mass<NDimensions>::compute(float delta_t) {
        // Update position
        _position += _speed*delta_t;

        // Update speed: need to compute new acceleration
        TVector force{};
        for (const auto& it: _forces) {
            force += it->get();
        }
        _speed += force*(delta_t/_mass);
    }

}
