//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;

#include "Game1.hpp"
#include "Game2.hpp"



//1. 命名空间用途: 解决名称冲突
void func1(void) {
    KingGlory::goATK();
    LOL::goATK();
}




// 2. 命名空间下可以存放: 变量 函数 结构体 类
namespace A {
int num = 20;

void testA() {
    cout << "namespace A testA" << endl;
}

struct Person {
    
};

class Student {
    
};
}

void func2(void) {
    A::testA();
}





// 3. 命名空间必须申明在全局作用域
void func3(void) {
    // Namespaces can only be defined in global or namespace scope
    // namespace B {}
}





// 4.命名空间可以嵌套命名空间
namespace B {
    namespace C {
        void funcB_C() {
            cout << "B C funcB_C" << endl;
        }
    }
}

void func4(void) {
    B::C::funcB_C();
}






// 5.命名空间是开发的, 可以随时把新成员添加到命名空间下
namespace B {
int b_int = 10;
}






// 6.命名空间是可以匿名的
// 在匿名的命名空间下, 相当于写了 static int m_A = 1000;
//                           static int m_B = 2000;
namespace {
int m_A = 1000;
int m_B = 2000;
}

void func5() {
    cout << m_A << endl;
    cout << ::m_B << endl;

}






// 7.命名空间可以起别名
void func6(void) {
    namespace AAAA = A;
    
    cout << A::num << endl;
    cout << AAAA::num << endl;
}



int main() {
    //func1();
    //func2();
    //func4();
    //func5();
    func6();
    
    return EXIT_SUCCESS;
}

