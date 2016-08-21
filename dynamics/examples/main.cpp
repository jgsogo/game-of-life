
#include <iostream>
#include "../src/system.hpp"

#include "../src/spring.hpp"


int main() {
    std::cout << "=== Dynamics example ===" << std::endl;

    // 1D system
    using System1D = dynamics::System<1>;
    System1D mySystem;
    auto m1 = mySystem.add_mass(10.f);
    auto m2 = mySystem.add_mass<dynamics::MassFixed>(System1D::TPosition{.0f});
    auto s1 = mySystem.add_actuator<dynamics::Spring>(m1, m2);

    std::cout << mySystem << std::endl;
    //std::cout << m1.get_position() << std::endl;
}
