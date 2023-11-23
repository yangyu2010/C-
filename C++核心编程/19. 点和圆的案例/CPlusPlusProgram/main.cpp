//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
#include "point.hpp"
#include "circle.hpp"
using namespace std;




int main() {

    Point p;
    p.setX(10);
    p.setY(9);
    
    
    Circle c;
    c.setR(10);
    Point p_c;
    p_c.setX(10);
    p_c.setY(0);
    c.setP(p_c);
    
    c.isInCircle(p);

    printf("外面p_c %p\n", &p_c);
    
    
    
    return EXIT_SUCCESS;
}



/*
 在c++语言中, 下面的代码中.
 p_c变量和Circle对象内部的m_P变量, 两者是一个对象吗?

 class Point {
 }

 class Circle {
     Point m_P;

     void setP(Point p) {
         m_P = p;
     }
 }

 Circle c;

 Point p_c;
 c.setP(p_c);


 
 
 
 
 
 
 
 在C++中，对于以下代码：

 ```cpp
 class Point {
     // 假设这里有坐标属性等
 };

 class Circle {
     Point m_P;

 public:
     void setP(Point p) {
         m_P = p;
     }
 };

 int main() {
     Circle c;
     Point p_c;
     c.setP(p_c);
 }
 ```

 `p_c`变量是一个`Point`类型的实例，在`main`函数中创建。当你调用`c.setP(p_c);`时，你实际上是将`p_c`作为参数传递给Circle类的`setP`成员函数。

 在`setP`函数中，参数`p`接收了`p_c`的副本。注意，由于没有指定按引用传递（通过引用符号&），所以这里发生的是值传递（pass-by-value），意味着`m_P`将被赋予一个`p_c`的副本，而不是`p_c`自身。所以`m_P`和`p_c`是两个不同的对象，它们各自占有不同的内存空间，但拥有相同的值（假设`Point`类有复制构造函数或默认复制行为足以复制其值）。

 简短回答您的问题：`p_c`变量和Circle对象内部的`m_P`变量不是同一个对象，它们是两个拥有相同值的独立对象。
 
 */
