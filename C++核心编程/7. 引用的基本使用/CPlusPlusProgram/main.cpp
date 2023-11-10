//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;

// 引用的基本语法: 类型 &别名 = 原名
void func1(void) {
    int a = 10;
    int &b = a;

    b = 100;
    
    printf("%d\n", a);
    printf("%d\n", b);
}


void func2(void) {
    int a = 10;
    // 引用必须初始化
    //int &b;

    int &b = a;
    int c = 100;
    
    b = c;
    
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
}



// 对数组进行引用
void func3(void) {
    int array[10] = { 0 };
    
    int (&arrayP)[10] = array;
    
    
    for (int i = 0; i < 10; i++) {
        arrayP[i] = 100 + i;
    }
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    
    // 先定义出数组类型, 再通过类型定义引用
    typedef int(ARRAY_TYPE)[10];
    
    ARRAY_TYPE &arrayPP = array;
    for (int i = 0; i < 10; i++) {
        printf("%d ", arrayPP[i]);
    }
    printf("\n");
    
}

int main() {
    //func1();
    //func2();
    func3();
    //func4();

    return EXIT_SUCCESS;
}
