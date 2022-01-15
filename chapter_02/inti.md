# 初始化列表

初始化是一个飞创重要的语言特征，最创建的就是在对象进行初始化的时候使用，不同对象有不同的初始化方法，比如普通数据，POD，类型都可以使用{}进行初始化，也就是我们所说的初始化列表。而对于类对象的初始化，要么需要听过拷贝构造，也么就需要使用()进行。这些不同方法针对各自对象，不能通用。

其实对于工程项目来说重点就是使用初始化列表来对类进行初始化
```
Fred::Fred() : x_(whatever) { } //better way
Fred::Fred() { x_ = whatever; }
```

# 结构绑定

结构绑定提供了类似多返回值功能, 我们会学到 C++11 新
增了 std::tuple 容器用于构造一个元组，进而囊括多个返回值。但缺陷是，C++11/14 并没有提供一种
简单的方法直接从元组中拿到并定义元组中的元素，尽管我们可以使用 std::tie 对元组进行拆包，但
我们依然必须非常清楚这个元组包含多少个对象，各个对象是什么类型，非常麻烦。

C++17 完善了这一设定，给出的结构化绑定可以让我们写出这样的代码：
```
#include <iostream>
#include <tuple>
std::tuple<int, double, std::string> f() {
return std::make_tuple(1, 2.3, "456");
}
int main() {
auto [x, y, z] = f();
std::cout << x << ", " << y << ", " << z << std::endl;
return 0;
}·
```

# AUTO
 
有了auto之后变化最大的就是迭代器，如下：
```
for(vector<int>::const_iterator it = vec.begin();it!=vec.end();++i)

有了auto之后
for(auto it = vec.begin();it!=vec.end();++i)
```
c20之后甚至还可以用函数传参，比如：
```
int add(auto x, auto y){
  return x+y;
}
```
**注意** auto不能用来推导数组类型

**注意** typename 和 class 在模板参数列表中没有区别，在typename这个关键字出现之前，都是使用class来定义模板参数的。但在模板定义中有嵌套依赖类型的变量时，需要用typename消除歧义。

**尾返回类型推导**

你可能会思考，在介绍 auto 时，我们已经提过 auto 不能用于函数形参进行类型推导，那么 auto
能不能用于推导函数的返回类型呢？还是考虑一个加法函数的例子，在传统 C++ 中我们必须这么写：
20
2.3 类型推导 第 2 章语言可用性的强化
template<typename R, typename T, typename U>
R add(T x, U y) {
return x+y;
}
注意：typename 和 class 在模板参数列表中没有区别，在 typename 这个关键字出现之前，都
是使用 class 来定义模板参数的。但在模板中定义有嵌套依赖类型的变量时，需要用 typename
消除歧义