#include "Model.hpp"

void Model::setInput(int input)
{
  m_input = input;
}

void Model::run()
{
  m_state += m_input;
  m_output = m_state;
}

int Model::getOutput() const
{
  return m_output;
}