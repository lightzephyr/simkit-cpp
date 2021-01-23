#define BOOST_TEST_MODULE Classes
#include <boost/test/unit_test.hpp>
#include "LinearMotionModel.hpp"

using namespace LinearMotion;

BOOST_AUTO_TEST_CASE(intialization)
{
  LinearMotionModel model;
  const State &state = model.getOutput();
  BOOST_CHECK_EQUAL(state.position, 0);
  BOOST_CHECK_EQUAL(state.velocity, 0);
  BOOST_CHECK_EQUAL(state.acceleration, 0);
}

BOOST_AUTO_TEST_CASE(execution)
{
  LinearMotionModel model;
  const State &state = model.getOutput();

  BOOST_CHECK_EQUAL(state.position, 0);
  BOOST_CHECK_EQUAL(state.velocity, 0);
  BOOST_CHECK_EQUAL(state.acceleration, 0);

  model.setInput(1.0);
  BOOST_CHECK_EQUAL(state.position, 0);
  BOOST_CHECK_EQUAL(state.velocity, 0);
  BOOST_CHECK_EQUAL(state.acceleration, 1.0);

  model.run();
  BOOST_CHECK_EQUAL(state.position, 0.5);
  BOOST_CHECK_EQUAL(state.velocity, 1.0);
  BOOST_CHECK_EQUAL(state.acceleration, 1.0);
}