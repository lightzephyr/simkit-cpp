#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

#include <boost/timer/timer.hpp>

#include "LinearMotionModel.hpp"
#include "runScheduler.hpp"

using namespace boost::timer;
using namespace LinearMotion;

int main()
{
   cpu_timer timer;

   LinearMotionModel model{};
   model.setInput(1.0);
   const State &state = model.getOutput();

   auto printState{
       [&timer, &state]() {
          std::cout
              << "Elapsed time = " << timer.elapsed().wall * 1e-6
              << "; Model output: position = " << state.position
              << ", velocity = " << state.velocity
              << ", acceleration = " << state.acceleration
              << '\n';
       }};

   auto runInSchedule{
       [&timer, &model, &printState](LinearMotionModel &model) {
          int i = 0;
          while (i < 10)
          {
             timer.start();
             model.run();
             timer.stop();
             printState();
             i++;
          }
       }};

   runInSchedule(model);

   scheduler::runScheduler();

   return 0;
}