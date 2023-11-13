//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;



int& func() {
    int a = 10;
    return a;
}

// 引用注意事项
// 引用必须引用一块合法的内存
void func1(void) {
    //int &a = 10;
    //int &ref = func();
    
    
}

int main() {
    func1();
    //func2();
    //func3();
    
    
    return EXIT_SUCCESS;
}
