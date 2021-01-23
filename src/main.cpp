#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

#include "LinearMotionModel.hpp"

using namespace LinearMotion;

int main()
{
   LinearMotionModel model{};
   const State &state = model.getOutput();

   auto printState{
       [&state]() {
          std::cout << "Model output: position = " << state.position << ", velocity = " << state.velocity << ", acceleration = " << state.acceleration << '\n';
       }};

   printState();
   model.setInput(1.0);
   printState();
   model.run();
   printState();

   return 0;
}