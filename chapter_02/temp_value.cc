#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> vec = {1, 2, 3, 4};
  // const std::vector<int>::iterator iter = std::find(vec.begin(), vec.end(), 2);
  // if (iter != vec.end())
  // {
  //   *iter = 3;
  // }

  if (const std::vector<int>::iterator iter = std::find(vec.begin(), vec.end(), 2); iter != vec.end())
  {
    *iter = 3;
  }
}
