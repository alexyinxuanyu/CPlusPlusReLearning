#include <iostream>

int main()
{
  auto x = 1;
  if (std::is_same<decltype(x), int>::value)
    std::cout << "type x == int" << std::endl;
  // if (std::is_same<decltype(x), float>::value)
  //   std::cout << "type x == float" << std::endl;
  // if (std::is_same<decltype(x), decltype(z)>::value)
  //   std::cout << "type z == type x" << std::endl;
  return 0;
}
