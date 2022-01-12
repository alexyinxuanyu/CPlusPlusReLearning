#include <iostream>
#include <time.h>

int factorial(int n)
{
  if (n == 0)
  {
    return 1;
  }
  return n * factorial(n - 1);
}

void foo()
{
  int x = factorial(4);
  int y = factorial(0);
  // std::cout << x << std::endl;
  // std::cout << y << std::endl;
}

template <int N>
struct Factorial
{
  enum
  {
    value = N * Factorial<N - 1>::value
  };
};

template <>
struct Factorial<0>
{
  enum
  {
    value = 1
  };
};

int main()
{
  //能带来30倍的加速
  clock_t start, end;
  start = clock();
  foo();
  end = clock();
  std::cout << double(end - start) / CLOCKS_PER_SEC * 1000 << std::endl;
  start = clock();
  int x = Factorial<4>::value;
  int y = Factorial<0>::value;
  end = clock();
  std::cout << double(end - start) / CLOCKS_PER_SEC * 1000 << std::endl;
  return 0;
}
