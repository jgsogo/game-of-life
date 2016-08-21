
#include <iostream>
#include <iomanip>
#include "../src/system.hpp"

#include "../src/spring.hpp"
#include "../src/dumper.hpp"


int main() {
    std::cout << "=== Dynamics example ===" << std::endl;

    // 1D system
    float mass = 1.f;
    float stiffness = 1.f;
    float damping = std::sqrt(4*stiffness*mass)*0.9f; // Underdamped

    using System1D = dynamics::System<1>;
    System1D mySystem;
    auto& m1 = mySystem.add_mass(mass, System1D::TPosition{1.f});
    auto& m2 = mySystem.add_mass<dynamics::MassFixed>(System1D::TPosition{.0f});
    auto& s1 = mySystem.add_actuator<dynamics::Spring>(m1, m2);
    s1.initialize(0.f, stiffness);
    auto& c1 = mySystem.add_actuator<dynamics::Dumper>(m1, m2);
    c1.initialize(damping);

    std::cout << mySystem << std::endl;

    float delta_t = 0.001;
    for (std::size_t i = 0; i<10000; ++i) {
        if (i % 100 == 0) {
            std::cout << std::setw(4) << i << " - " << m1.get_position() << std::endl;
        }
        mySystem.compute(delta_t);
    }
}
