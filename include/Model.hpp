#ifndef MODEL_H
#define MODEL_H

class Model
{
public:
  Model(){};
  virtual ~Model(){};

  /* Run the model for the specified time interval
   * @param dt The time interval in miliseconds
   */
  virtual void run(int dt) = 0;
};

#endif