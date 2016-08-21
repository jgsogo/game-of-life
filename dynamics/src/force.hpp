
#pragma once

#include "common.h"

namespace dynamics {

    template <std::size_t NDimensions>
    class Force {
        using TVector = vector<NDimensions>;
        public:
            Force() : _force{} {};
            ~Force() {};

            void set(const TVector& v) { _force=v; }
            const TVector& get() const { return _force;}

            void reset() {_force = TVector{};}

        protected:
            TVector _force;
    };

}
