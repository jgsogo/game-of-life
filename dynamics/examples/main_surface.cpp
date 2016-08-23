
#include <iostream>
#include <iomanip>
#include "../src/surface.h"


int main() {
    std::cout << "=== Dynamics example surface ===" << std::endl;

    // 1D system
    using Surface = dynamics::Surface<4, 4>;
    Surface mySystem;
    mySystem.initialize();

    std::cout << mySystem << std::endl;
    auto& m1 = mySystem.get_mass(1);

    const float delta_t = 0.001;
    while (true) {
        mySystem.compute(delta_t);
        std::cout << m1.get_position() << std::endl;
    }


}
