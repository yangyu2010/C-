//
//  TestC.c
//  CPlusPlusProgram
//
//  Created by Yu Yang on 11/9/23.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1.全局变量检测增强
//int a;
//int a = 20;


// 2.函数检测增强 返回值 形参类似 形参个数
//sum(a, b) {
//    return a * b;
//}
//void func(void) {
//    int count = sum(10, 10, 10);
//}



// 3.类型转换检测增强
void cFunc1(void) {
    char *p = malloc(64);
}



// 4.struct 增强
//struct Person {
//    int age;
//
//    //void func();
//};




// 5.bool类型
//bool a;



// 6. 三目运算符增强
void cFunc2(void) {
    int a = 10;
    int b = 20;
    printf("%d\n", a > b ? a : b);
    // 编译失败
    //a < b ? a : b = 100;
    //(a < b ? a : b) = 100;
    
    printf("%d\n", a);
    printf("%d\n", a);
}





// 7.const增强
const int c_a = 100;
void cFunc3(void) {
    //c_a = 200;
    //int *p = (int *)&c_a;
    //*p = 200; // 修改失败 运行时报错
    
    
    const int c_b = 100;
    int *p = (int *)&c_b;
    *p = 200; // 修改成功 C语言下 局部的const是伪常量
}
