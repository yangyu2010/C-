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

void allocateSpace(int **p) {
    int *temp = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        temp[i] = 100 + i;
    }
    *p = temp;
}


/*
 
 void printArray(int **pArray, int length) {
     for (int i = 0; i < length; i++) {
         printf("%d\n", *pArray[i]);
     }
 }
 
 上一个DEMO中, 打印方法如上.
 是把pArray做为数组, 取出第几个, 然后再解引用   *(pArray[i])
 
 下面的是pArray先解引用, 可以理解是pArray是指向数组的指针, 先把这个数组取出来
 然后再取出数组的第几个 (*pArray)[i]
 */
void printArray(int **pArray, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", (*pArray)[i]);
//        printf("%d\n", *(p[i]));
    }
}

// 同级指针释放有问题
void freeSpace(int *pArray) {
    if (pArray != NULL) {
        free(pArray);
        pArray = NULL;
    }
}

void freeSpace2(int **pArray) {
    if (*pArray != NULL) {
        free(*pArray);
        *pArray = NULL;
    }
}

void func1(void) {
    int *p = NULL;
    allocateSpace(&p);
    printArray(&p, 10);
    
    freeSpace(p);
//    freeSpace2(&p);
    if (p == NULL) {
        printf("空指针\n");
    } else {
        printf("野指针\n");
    }
    
//    if (p != NULL) {
//        free(p);
//        p = NULL;
//    }
}


int main() {
    func1();
//    func2();
    
    return EXIT_SUCCESS;
}

