#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

#include "Model.hpp"

using namespace std;

int main()
{
   Model model{};
   model.setInput(1);
   cout << "Model output: " << model.getOutput() << '\n';
   model.run();
   cout << "Model output: " << model.getOutput() << '\n';

   return 0;
}