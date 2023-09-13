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


// 数组指针的定义方式


// 1.先定义数组类型, 再通过类型 定义数组指针
void func1(void) {
    
    int array[5] = {1, 2, 3, 4, 5};
    
    // ARRAY_TYPE代表存放了5个int元素的数组的类型
    typedef int(ARRAY_TYPE)[5];
    
//    ARRAY_TYPE array2 = {10, 11, 12, 13, 14};
//    for (int i = 0; i < 5; i++) {
//        printf("%d\n", array2[i]);
//    }
    
    ARRAY_TYPE *p = &array;
    for (int i = 0; i < 5; i++) {
        printf("%d\n", (*p)[i]);
    }
    
}

// 2.先定义数组指针类型 再通过类型 定义数组指针
void func2(void) {
    
    int array[5] = {1, 2, 3, 4, 5};
    
    // ARRAY_TYPE代表存放了5个int元素的数组的类型
    typedef int (*ARRAY_TYPE)[5];
    ARRAY_TYPE p = &array;
    for (int i = 0; i < 5; i++) {
        printf("%d\n", (*p)[i]);
    }
}

// 3.直接定义数组指针变量
void func3(void) {
    
    int array[5] = {1, 2, 3, 4, 5};

    int (*p)[5] = &array;
    for (int i = 0; i < 5; i++) {
        printf("%d\n", (*p)[i]);
    }
}


int main() {
    func3();
    
    return EXIT_SUCCESS;
}


