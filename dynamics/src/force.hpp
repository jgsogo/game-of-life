
#pragma once

#include <array>

namespace dynamics {

    template <std::size_t NDimensions>
    class Force {
        public:
            Force() {};
            ~Force() {};

        protected:
            std::array<float, NDimensions> _force;
    };

}
