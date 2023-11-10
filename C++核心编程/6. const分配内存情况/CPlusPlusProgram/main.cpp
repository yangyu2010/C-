//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;

// 1.对const变量取地址, 会分配临时内存
void func1(void) {
    const int a = 10;
    int *p = (int *)&a;
    *p = 1000;
    
    cout << a << endl;
    cout << *p << endl;
}

// 2.使用一个变量来初始化
void func2(void) {
    int a = 10;
    const int b = a;
    
    int *p = (int *)&b;
    *p = 1000;

    cout << b << endl;
}


// 3.对于自定义数据类型
struct Person {
    string name;
    int age;
};

void func3(void) {
    const Person p = {"Jack", 18};
    //p.age = 20;
    
    Person *pp = (Person *)&p;
    pp->age = 20;
    
    cout << p.name << endl;
    cout << p.age << endl;
}


int main() {
    //func1();
    //func2();
    func3();
    //func4();

    return EXIT_SUCCESS;
}
