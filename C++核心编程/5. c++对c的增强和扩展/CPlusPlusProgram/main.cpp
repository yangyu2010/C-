//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;


// 1.全局变量检测增强
//int a;
int a = 20;


// 2.函数检测增强 返回值 形参类似 形参个数
//sum(a, b) {
//    return a * b;
//}


// 3.类型转换检测增强
//Cannot initialize a variable of type 'char *' with an rvalue of type 'void *'
//char *p = (char *)malloc(64);



// 4.struct 增强 C++可以放函数 简化struct关键字
struct Person {
    int age;

    void func() {
        age++;
    };
};

void func1(void) {
    Person p = { 10 };
    p.func();
    cout << p.age << endl;
}




// 5.bool类型 非0即是true
bool b_a = false; //0
bool b_b = true;  //1
void func2(void) {
    cout << b_a << endl;
    cout << b_b << endl;
}




// 6. 三目运算符增强
void func3(void) {
    int a = 10;
    int b = 20;
    printf("%d\n", a > b ? a : b);
    //(a < b ? a : b) = 100; C++中 返回的是变量 而C中返回的是值
    a < b ? a : b = 100;
    printf("%d\n", a);
    printf("%d\n", b);
}



// 7.const增强
/*
 6.7.1    C语言下
 6.7.1.1    全局const   直接修改 失败  间接修改  语法通过，运行失败
 6.7.1.2    局部 const  直接修改  失败  间接修改  成功
 6.7.2    C++语言下
 6.7.2.1    全局 const  和C结论一样
 6.7.2.2    局部 const  直接修改失败   间接修改 失败
 6.7.2.3    C++const可以称为常量
 */
const int c_a = 100;
void func4(void) {
    //c_a = 200;
    //int *p = (int *)&c_a;
    //*p = 200; // 修改失败 运行时报错
    
    
    const int c_b = 100;
    int *p = (int *)&c_b;
    *p = 200; // 修改失败
    
    cout << c_b << endl;
    cout << *p << endl;
}




int main() {
    //func1();
    //func2();
    //func3();
    func4();

    return EXIT_SUCCESS;
}



/*
 在c++环境中,

 int a = 10;
 int b = 20;

 分别执行下面两句代码, a和b的值是多少?

 a < b ? a : b = 100;
 a > b ? a : b = 100;

 
 
 
 
 
 在 C++ 中，条件运算符 `?:` 的优先级低于赋值运算符 `=`。但是，由于条件运算符的语法，其中包含的赋值部分实际上会只对选择的操作数生效，即冒号 `:` 右边的部分。

 首先来看第一句：

 ```cpp
 a < b ? a : b = 100;
 ```

 这里，`a < b` 是 `true`，所以根据条件运算符 `?:` 的规则，我们选择 `a`，而不是 `b = 100`。由于 `a` 已经被选择，并且没有对它进行任何操作，所以 `a` 和 `b` 的值都不会改变。因此，执行该语句后，`a` 仍然是 10，`b` 仍然是 20。

 接下来看第二句：

 ```cpp
 a > b ? a : b = 100;
 ```

 这里，`a > b` 是 `false`，所以我们选择 `b = 100`。这意味着将 `b` 的值设置为 100。因此，执行该语句后，`a` 的值仍然是 10，`b` 的值变成了 100。

 总结一下：

 - 第一行代码执行后：`a` = 10, `b` = 20
 - 第二行代码执行后：`a` = 10, `b` = 100

 如果你希望在第一个表达式中也赋值，请确保用括号正确地分组表达式：

 ```cpp
 (a < b ? a : b) = 100; // 这样会将100赋给正确的变量，依赖于条件的结果。
 ```
 */
