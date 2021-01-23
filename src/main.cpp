#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

#include <boost/timer/timer.hpp>

#include "LinearMotionModel.hpp"
#include "scheduling.hpp"

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

   bool interrupt = false;
   std::thread schedulingThread(scheduling::runSchedule, 60, 0.01, std::ref(interrupt));
   std::cin.get();
   interrupt = true;
   schedulingThread.join();

   return 0;
}