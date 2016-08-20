#define BOOST_TEST_MODULE "Test Game Of Life - Engine"
#include <boost/test/unit_test.hpp>
#include "spdlog/spdlog.h"
#include <iostream>


struct GlobalConfig {
    GlobalConfig() {
        std::cout << "global setup\n";
    }
    ~GlobalConfig() {
        std::cout << "global teardown\n";
    }
};

BOOST_GLOBAL_FIXTURE(GlobalConfig);

