//
//  main.c
//  AdvancedCProgram
//
//  Created by Yu Yang on 8/23/23.
//

#define _CRI_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// int array[]等价于 int *
// int array[]可读性更高
// array在传参时, 是指向数组第一个元素的指针
void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", array[i]);
    }
}


void func1(void) {
    int array[5] = {1, 2, 3, 4, 5};
    printf("%lu\n", sizeof(array));
    
    // 有两种特殊情况, 一维数组名不是 指向第一个元素的指针
    // 1. sizeof
    // 2. 对数组名 取地址, 得到的是数组指针, 步长是整个数组长度
    
    int length = sizeof(array) / sizeof(int);
    printArray(array, length);
    
    // array数组名 是一个指针常量 类似于int * const a;
    // 指针常量的意思是, 指针的指向不可以修改, 指针指向的值可以修改
    // const修饰的是右边的内容
    
    //可以
    array[0] = 10;
    
    //不可以
    //array = {6, 7, 8, 9, 10};
    //array = NULL;

    
}


// 参考 21. const使用(补充)
//void func2(void) {
//    int age = 10;
//    const int *p1 = &age;
//    int const * p2 = &age;
//    int * const p3 = &age;
//    const int * const p4 = &age;
//    int const * const p5 = &age;
//}




int main() {
    func1();
    
    return EXIT_SUCCESS;
}


