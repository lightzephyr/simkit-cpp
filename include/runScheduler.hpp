#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>

#include <boost/timer/timer.hpp>

using namespace boost::timer;

namespace scheduler
{

  void run(const bool &interrupt)
  {
    constexpr int frequency = 60;                             // [Hz]
    constexpr std::uint32_t period = (1.0 / frequency) * 1e9; // [nanoseconds]

    cpu_timer clockTimer;
    cpu_timer tickTimer;

    std::cout << "Scheduler started with period = " << period * 1e-6 << " miliseconds." << '\n';

    try
    {
      while (!interrupt)
      {
        tickTimer.start();
        while (tickTimer.elapsed().wall < period)
        {
          // run as fast as possible
        }
        tickTimer.stop();
        int tickDuration = tickTimer.elapsed().wall;
        //std::cout << "Tick duration: " << tickDuration * 1e-6 << '\n';
        if (tickDuration < 16660000 || tickDuration > 16680000)
        {
          clockTimer.stop();
          throw "Tick duration exceeded tolerance of 16.67±0.01 ms";
        }
      }
      std::cout << "Scheduler finished. after " << clockTimer.elapsed().wall * 1e-6 << " ms" << '\n';
    }
    catch (const char *e)
    {
      std::cerr << e << '\n';
      double tickDuration = tickTimer.elapsed().wall * 1e-6;
      std::cerr << "Tick duration was: " << tickDuration << " ms" << '\n';
      std::cerr << "Error was: " << tickDuration - 16.67 << " ms" << '\n';
      std::cout << "Scheduler finished after " << clockTimer.elapsed().wall * 1e-6 << " ms with error." << '\n';
    }
  }

  int runScheduler()
  {
    bool interrupt = false;
    std::thread scheduler(run, std::ref(interrupt));
    std::cin.get();
    interrupt = true;
    scheduler.join();

    return 0;
  }

} // namespace scheduler