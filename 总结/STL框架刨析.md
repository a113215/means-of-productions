## STL框架刨析

说明：STL所实现的，是依据泛型思维[^1]架设起来的一个概念结构。这个以抽象概念为主体而非以实际类为主体的结构，形成了一个严谨的接口标准。在此接口之下，任何组件都有最大的独立性，并以所谓迭代器胶合起来，或以所谓配接器互相配接，或以所谓仿函数动态选择某种策略。

### STL六大组件

分别是容器、算法、迭代器、仿函数、配接器、配置器。容器通过配置器取得数据储存空间，算法通过迭代器存取容器内容，仿函数协助算法完成不同的策略变化，配接器修饰或套接仿函数。

#### 容器（containers）：

各种结构数据，一种class template。

#### 算法(algorithms)：

各种常用算法，一种function template。

#### 迭代器(iterators)：

容器与算法之间的胶合剂，是所谓的”泛型指针“，是一种将operator*, operator->, operator++, operater--等指针相关操作予以重载的class template； 

#### 仿函数(functors)：

行为类似函数，可作为算法的某种策略，重载了operator{}的class或class template。

#### 配接器(adapters)：

一种用来修饰容器或仿函数或迭代器接口的东西。

#### 配置器(allocators)：

负责空间配置与管理。

### 代码写法解析

#### 临时对象的产生与运行

作用：调用相应构造函数且不指定对象名称

```C++
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
//定义模板T
template <typename T>
class print {
public :
	void operator()(const T& elem) { cout << elem << ' '; }//重载符号()：print()触发此重载
};
void main()
{
	int ia[6] = { 0,1,2,3,4,5 };
	vector<int > iv(ia, ia + 6);
	//print<int>()是一个临时对象，被传入for_each之中起作用，for_each结束后释放该对象
	//for_each函数功能:将指定的函数对象按向前顺序应用于范围中的每个元素并返回此函数对象。
	for_each(iv.begin(),iv.end(),print<int>());//指定模板T为int并触发重载。
}
```

#### 

[^1 ]:用于代表一种通用离开类型，具体的类型由调用时指定。