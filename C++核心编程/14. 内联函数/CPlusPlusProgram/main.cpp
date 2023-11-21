//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;

// 宏缺陷1: 必须加上扣号 保证运算的完整性
#define MYADD(x, y) ((x) + (y))

void func1(void) {
    int a = 10;
    int b = 20;
    int result = MYADD(a, b) * 20;
    cout << result << endl;
}





// 宏缺陷2: 即使加了扣号, 有些运算也是与预期不符合
#define MYCOMPARE(x, y) (((x) > (y)) ? (x) : (y))

void func2(void) {
    int a = 10;
    int b = 20;
    int result = MYCOMPARE(a, ++b);     //(((a) > (++b)) ? (a) : (++b)) 因为++在前面, 所以先进行++的操作
    cout << result << endl;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}


void func3(void) {
    int a = 10;
    int b = 20;
    int result = MYCOMPARE(a, b++);
    // (((a) > (b++)) ? (a) : (b++))
    // 当返回三目运算符的结果时 b只++了一次
    // 所以结果是21, 但是当结果返回后, b会再次++, b就是22了
    cout << result << endl;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}






// 内联函数
inline int myCompare(int x, int y) {
    return x > y ? x : y;
}

void func4(void) {
    int a = 10;
    int b = 20;
    int result = myCompare(a, ++b);
    
    cout << result << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
/*
 内联函数 限制
 
 不能存在任何形式的循环语句
 不能存在过多的条件判断语句
 函数体不能过于庞大
 不能对函数进行取址操作
 */



int main() {
    
    //func1();
    //func2();
    //func3();
    
    func4();
    
    return EXIT_SUCCESS;
}

