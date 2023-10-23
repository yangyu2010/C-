//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;


int atk = 1000;
void func1(void) {
    int atk = 2000;
    
    cout << "atk = " << atk << endl;
    // :: 代表作用域 如果前面什么都不添加 代表全局作用域 类似std::cout
    cout << "atk = " << ::atk << endl;
}


int main() {
    func1();
    
    return EXIT_SUCCESS;
}

