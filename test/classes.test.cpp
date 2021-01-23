#define BOOST_TEST_MODULE Classes
#include <boost/test/unit_test.hpp>
#include "classes.hpp"

BOOST_AUTO_TEST_CASE(foo_test)
{
  Foo f1{};
  BOOST_CHECK_EQUAL(f1.greeting, "Hello");

  Foo f2{"World"};
  BOOST_CHECK_EQUAL(f2.greeting, "Hello World");
}
