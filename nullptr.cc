#include <iostream>

// #ifdef __cplusplus
// #define NULL 0
// #else
// #define NULL ((void *)0)
// #endif

void bar(int a, int *b)
{
  std::cout << "0" << std::endl;
}
void bar(int a, int i)
{
  std::cout << "1" << std::endl;
}
int main()
{
  //这里你必须转换类型之后才有用，因为系统会使用int来表示，而非NULL PTR
  // bar(2, static_cast<int *>(0));
  // quit,这个特性其实并不需要了
  bar(2, nullptr);
  return 0;
}