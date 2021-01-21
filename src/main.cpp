#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

using namespace std;

int main()
{
   constexpr std::array<std::string_view, 4> arr{"apple", "banana", "walnut", "pear"};

   std::cout << "search for: ";

   std::string search{};
   std::cin >> search;

   const auto found{std::find_if(arr.begin(), arr.end(),
                                 [search](std::string_view str) -> bool {
                                    return (str.find(search) != std::string_view::npos);
                                 })};

   if (found == arr.end())
   {
      std::cout << "No Nuts\n";
   }
   else
   {
      std::cout << "Found " << *found << '\n';
   }

   return 0;
}