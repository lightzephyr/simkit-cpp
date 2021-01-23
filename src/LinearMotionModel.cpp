#include <cmath>

#include "LinearMotionModel.hpp"

namespace LinearMotion
{

  void LinearMotionModel::setInput(double acceleration)
  {
    m_state.acceleration = acceleration;
  }

  void LinearMotionModel::run(int dt)
  {
    double _dt = dt / 1000;
    double velocity = m_state.velocity + m_state.acceleration * _dt;
    double position = m_state.velocity * _dt + 0.5 * m_state.acceleration * pow(_dt, 2);

    m_state = {position, velocity, m_state.acceleration};
  }

  const State &LinearMotionModel::getOutput() const
  {
    return m_state;
  }

} // namespace LinearMotion