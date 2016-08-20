#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(test_suite)

BOOST_AUTO_TEST_CASE(test_case1)
{
    BOOST_CHECK_EQUAL(3, 3);
}

BOOST_AUTO_TEST_CASE(test_fail)
{
    BOOST_CHECK_EQUAL(3, 2);
}

BOOST_AUTO_TEST_SUITE_END()
