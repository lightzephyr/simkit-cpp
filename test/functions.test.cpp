#define BOOST_TEST_MODULE Functions
#include <boost/test/unit_test.hpp>
#include "functions.hpp"

BOOST_AUTO_TEST_CASE( add_test )
{
  BOOST_CHECK_EQUAL( add( 2,2 ), 4 );
}

BOOST_AUTO_TEST_CASE( accelerate_test )
{
  BOOST_CHECK_EQUAL( accelerate( 0, 1 ), 9.81 );
}