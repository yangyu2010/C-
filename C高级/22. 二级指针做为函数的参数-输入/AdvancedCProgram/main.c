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


void printArray(int **pArray, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", *pArray[i]);
    }
}

void func1(void) {
    int **pArray = malloc(sizeof(int *) * 5);
    int a1 = 10;
    int a2 = 20;
    int a3 = 30;
    int a4 = 40;
    int a5 = 50;
    
    *pArray = &a1;
    *(pArray + 1) = &a2;
    *(pArray + 2) = &a3;
    *(pArray + 3) = &a4;
    *(pArray + 4) = &a5;

//    pArray[0] = &a1;
//    pArray[1] = &a2;
//    pArray[2] = &a3;
//    pArray[3] = &a4;
//    pArray[4] = &a5;

    printArray(pArray, 5);
    
    if (pArray != NULL) {
        free(pArray);
        pArray = NULL;
    }
}

void func2(void) {
    // 创建在栈区
    int *pArray[5];
    
    for (int i = 0; i < 5; i++) {
        // 在堆区开辟空间
        pArray[i] = malloc(sizeof(int));
        *(pArray[i]) = 10 + i;
    }
    
    printArray(pArray, 5);

    // 释放堆区
    for (int i = 0; i < 5; i++) {
        free(pArray[i]);
        pArray[i] = NULL;
    }
}

int main() {
    func1();
//    func2();
    
    return EXIT_SUCCESS;
}

