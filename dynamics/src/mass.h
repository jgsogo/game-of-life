
#pragma once

#include <vector>
#include "common.h"
#include "force.hpp"


namespace dynamics {

    template <std::size_t NDimensions>
    class Mass {
        protected:
            using TVector = vector<NDimensions>;
            using TForce = Force<NDimensions>;

        public:
            Mass(float mass);
            Mass(float mass, const TVector& position);
            ~Mass();

            const TVector& get_position() const {
                return _position;
            }

            const TVector& get_speed() const {
                return _speed;
            }

            void add_force(std::shared_ptr<TForce> force);

            virtual void compute(float delta_t);

            virtual void print(std::ostream& os) const {
                os << "Mass " << NDimensions << "D (" << _mass << "u):\n";
                os << " - position: " << _position << std::endl;
                os << " - speed: " << _speed << std::endl;
            }

        protected:
            float _mass;
            TVector _position;
            TVector _speed;

        private:
            std::vector<std::shared_ptr<TForce>> _forces;
    };

    template <std::size_t NDimensions>
    class MassFixed : public Mass<NDimensions> {
        using TMass = Mass<NDimensions>;
        public:
            MassFixed(const typename TMass::TVector& position) :
                TMass(0.f, position) {
            };

            ~MassFixed() {};

            virtual void compute(float delta_t) {};

            virtual void print(std::ostream& os) const {
                os << "MassFixed " << NDimensions << "D:\n";
                os << " - position: " << TMass::_position << std::endl;
            }

    };

}


template<class Ch, class Tr, int NDimensions>
auto operator<<(std::basic_ostream<Ch, Tr>& os, const dynamics::Mass<NDimensions>& t)
    -> std::basic_ostream<Ch, Tr>& {
    t.print(os);
    return os;
}
