#ifndef LINEARMOTIONMODEL_H
#define LINEARMOTIONMODEL_H

#include "Model.hpp"

namespace LinearMotion
{

  struct State
  {
    double position;
    double velocity;
    double acceleration;
  };

  class LinearMotionModel : Model
  {
  private:
    State m_state;

  public:
    LinearMotionModel() : m_state{0, 0, 0} {};
    virtual ~LinearMotionModel(){};

    void setInput(double acceleration);
    virtual void run(int dt = 1000) override;
    const State &getOutput() const;
  };

} // namespace LinearMotion

#endif