#define BOOST_TEST_MODULE Classes
#include <boost/test/unit_test.hpp>
#include "Model.hpp"

BOOST_AUTO_TEST_CASE(Model_intialization)
{
  Model model;
  BOOST_CHECK_EQUAL(model.getOutput(), 0);
}

BOOST_AUTO_TEST_CASE(Model_execution)
{
  Model model;
  model.setInput(1);
  BOOST_CHECK_EQUAL(model.getOutput(), 0);
  model.run();
  BOOST_CHECK_EQUAL(model.getOutput(), 0);
}