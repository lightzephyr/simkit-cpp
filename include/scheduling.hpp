#include <cassert>
#include <cmath>
#include <iostream>
#include <thread>

#include <boost/timer/timer.hpp>

using namespace boost::timer;

namespace scheduling
{

  /*
   * @param frequency [Hz]
   * @param tolerance [ms]
   * @param interrupt
   */
  void runSchedule(int frequency, double tolerance, const bool &interrupt)
  {
    assert(frequency > 0);
    const std::uint32_t period = (1.0 / frequency) * 1e9; // [nanoseconds]
    const std::uint32_t toleranceNs = tolerance * 1e6;    // [nanoseconds]

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
        const int error = abs(tickTimer.elapsed().wall - 16670000);
        if (error > toleranceNs)
        {
          clockTimer.stop();
          throw "Tick duration exceeded tolerance of 16.67±" + std::to_string(tolerance) + " ms by " + std::to_string(error * 1e-6) + " ms.";
        }
      }
      std::cout << "Scheduler finished after " << clockTimer.elapsed().wall * 1e-6 << " ms" << '\n';
    }
    catch (const std::string &e)
    {
      std::cerr << e << '\n';
      double tickDuration = tickTimer.elapsed().wall * 1e-6;
      std::cerr << "Tick duration was: " << tickDuration << " ms" << '\n';
      std::cout << "Scheduler finished after " << clockTimer.elapsed().wall * 1e-6 << " ms with error." << '\n';
    }
  }

} // namespace scheduling