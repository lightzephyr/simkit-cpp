# Dependencies
find_package(Boost COMPONENTS filesystem system unit_test_framework REQUIRED)
include(AddBoostTest.cmake)

# Add the tests
#add_boost_test(Model.test.cpp ../src/Model.cpp)
add_boost_test(LinearMotionModel.test.cpp ../src/LinearMotionModel.cpp)
