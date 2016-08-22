
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
    float damping = std::sqrt(4*stiffness*mass)*0.5f; // Underdamped

    using System1D = dynamics::System<1>;
    System1D mySystem;
    auto& m1 = mySystem.add_mass(mass, System1D::TPosition{1.f});
    auto& m2 = mySystem.add_mass<dynamics::MassFixed>(System1D::TPosition{.0f});
    auto& s1 = mySystem.add_actuator<dynamics::Spring>(m2, m1);
    s1.initialize(0.f, stiffness);
    auto& c1 = mySystem.add_actuator<dynamics::Dumper>(m2, m1);
    c1.initialize(damping);

    std::cout << mySystem << std::endl;

    const float delta_t = 0.001;
    const float error_t = 0.00001;
    float error = 1.f;
    std::size_t i = 0;
    while (error > error_t) {
        using namespace dynamics;
        if (++i % 100 == 0) {
            std::cout << m1.get_position()[0] << "\t\t" << m2.get_position()[0] << std::endl;
        }
        mySystem.compute(delta_t);
        error = dynamics::length(m1.get_position());
    }

}
