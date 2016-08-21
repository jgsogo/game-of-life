
#pragma once

#include <iostream>
#include <memory>

#include "mass.hpp"
#include "actuator.hpp"

namespace dynamics {

    template <std::size_t NDimensions>
    class System {
        using TMass = Mass<NDimensions>;
        using TActuator = Actuator<NDimensions>;
        public:
            using TPosition = vector<NDimensions>;

        public:
            System() {};
            ~System() {};

            template <template <std::size_t> class MassType = Mass, typename... Args>
            MassType<NDimensions>& add_mass(Args... args) {
                auto item = std::make_shared<MassType<NDimensions>>(args...);
                _mass.insert(_mass.end(), item);
                return *item;
            }

            template <template <std::size_t> class ActuatorType>
            ActuatorType<NDimensions>& add_actuator(const TMass& m1, const TMass& m2) {
                auto item = std::make_shared<ActuatorType<NDimensions>>(m1, m2);
                _actuator.push_back(item);
                return *item;
            }

            void print(std::ostream& os) const {
                os << "System " << NDimensions << "D:\n";
                os << " - mass items: " << _mass.size() << std::endl;
                os << " - actuator items: " << _actuator.size() << std::endl;
            }

        protected:
            std::vector<std::shared_ptr<TMass>> _mass;
            std::vector<std::shared_ptr<TActuator>> _actuator;
    };

}

template<class Ch, class Tr, std::size_t NDimensions>
auto operator<<(std::basic_ostream<Ch, Tr>& os, const dynamics::System<NDimensions>& t)
    -> std::basic_ostream<Ch, Tr>& {
    t.print(os);
    return os;
}
