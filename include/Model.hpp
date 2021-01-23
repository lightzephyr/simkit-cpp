#ifndef MODEL_H
#define MODEL_H

class Model
{
private:
  int m_input;
  int m_state;
  int m_output;

public:
  Model() : m_input{0}, m_state{0}, m_output{0} {};
  virtual ~Model(){};

  void setInput(int input);
  void run();
  int getOutput() const;
};

#endif