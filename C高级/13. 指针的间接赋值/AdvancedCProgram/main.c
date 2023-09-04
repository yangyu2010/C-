//
//  main.c
//  AdvancedCProgram
//
//  Created by Yu Yang on 8/23/23.
//

#define _CRI_SECURE_NO_WARNINGS
// VS下使用传统库函数, 会建议用_s更安全的函数, 如果不用会报错 C4996

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 间接赋值的三大条件
// 一个普通变量+指针变量 (或者一个实参+形参)
// 建立关系
// * 操作内存
void func1(void) {
    int a = 10;
    int *p = &a;
    *p = 100;
    printf("%d\n", a);
}


// 传递时必须用指针 传递地址
void changeValue(int *p) {
    *p = 1000;
}

void func2(void) {
    int a = 20;
    printf("%d\n", a);
    changeValue(&a);
    printf("%d\n", a);
}


// 提前知道了内存地址 直接使用内存地址修改
void func3(void) {
    int a = 30;
    printf("%p\n", &a);
    printf("%d\n", a);

    int *p = (int *)0x7ff7bfeff24c;
    *p = 1100;
    
    printf("%d\n", a);
}


int main() {
    func3();
    
    return EXIT_SUCCESS;
}


