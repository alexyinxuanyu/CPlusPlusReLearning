从c++14开始, constexpr函数可以在内部使用局部变量，循环和分支等简单语句，比如下面的代码在c++11是不同通过编译的。

```
constexpr int fib(const int n){
  if (n==1) return 1;
  if (n==2) return 1;
  return fib(n-1)+fib(n-2);
}
```
