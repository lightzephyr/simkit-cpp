#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>

#include <boost/timer/timer.hpp>

using namespace boost::timer;

namespace scheduler
{

  void run(cpu_timer &timer, int period, const bool &interrupt)
  {
    try
    {
      while (!interrupt)
      {
        timer.start();
        while (true)
        {
          if (timer.elapsed().wall > period)
          {
            timer.stop();
            break;
          }
        }
        int elapsedTime = timer.elapsed().wall;
        //std::cout << "Elapsed time: " << timer.elapsed().wall * 1e-6 << '\n';
        if (elapsedTime < 16660000 || elapsedTime > 16680000)
        {
          throw "Timer accurancy error exceeded tolerance of ±0.01 ms";
        }
      }
    }
    catch (const char *e)
    {
      std::cerr << e << '\n';
      double elapsedTime = timer.elapsed().wall * 1e-6;
      std::cerr << "Elapsed time was: " << elapsedTime << '\n';
      std::cerr << "Error was: " << elapsedTime - 16.67 << '\n';
    }
  }

  int runScheduler()
  {
    constexpr int frequency = 60;                             // [Hz]
    constexpr std::uint32_t period = (1.0 / frequency) * 1e9; // [nanoseconds]

    cpu_timer timer;
    std::cout << "Scheduler started with period = " << period * 1e-6 << " miliseconds." << '\n';
    bool interrupt = false;
    std::thread scheduler(run, std::ref(timer), period, std::ref(interrupt));
    std::cin.get();
    interrupt = true;
    scheduler.join();
    std::cout << "Scheduler finished." << '\n';

    return 0;
  }

} // namespace scheduler