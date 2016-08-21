#include <boost/test/unit_test.hpp>
#include "../src/common.h"

namespace boost { namespace test_tools { namespace tt_detail {

    // Teach Boost how to reach print function for dynamics::vector
    template <std::size_t NDimensions>
    inline std::ostream &operator<<(std::ostream &str, dynamics::vector<NDimensions> const &items) {
        return ::operator<<(str, items);
    }

}}}


BOOST_AUTO_TEST_SUITE(test_vector)

using Vector1D = dynamics::vector<1>;
using Vector3D = dynamics::vector<3>;


BOOST_AUTO_TEST_CASE(test_length)
{
    BOOST_CHECK_EQUAL(dynamics::length(Vector1D{2}), 2);
    BOOST_CHECK_EQUAL(dynamics::length(Vector1D{-3}), 3);

    BOOST_CHECK_CLOSE(dynamics::length(Vector3D{3, 4, 1}), std::sqrt(3*3+4*4+1*1), 1e-6);
    BOOST_CHECK_CLOSE(dynamics::length(Vector3D{1, 1, 1}), std::sqrt(3), 1e-5);
}

BOOST_AUTO_TEST_CASE(test_operator)
{
    using namespace dynamics;
    BOOST_CHECK_EQUAL((Vector3D{2, 2, 2} - Vector3D{1, 1, 3}), (Vector3D{1, 1, -1}));
}


BOOST_AUTO_TEST_SUITE_END()
