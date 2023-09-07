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
        printf("%d\n", *(pArray[i]));
//        printf("%d\n", (*pArray)[i]);

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
//    func1();
    func2();
    
    return EXIT_SUCCESS;
}



/*
 

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

     printArray(pArray, 5);
     
     if (pArray != NULL) {
         free(pArray);
         pArray = NULL;
     }
 }

 pArray, a1, a2, a3, a4, a5内存在栈上
 a5地址是0x00007ff7bfeff234
 a4地址是0x00007ff7bfeff238
 a3地址是0x00007ff7bfeff23c
 a2地址是0x00007ff7bfeff240
 a1地址是0x00007ff7bfeff244
 pArray地址是0x00007ff7bfeff248
 
 a5的存储内容是 50
 a4的存储内容是 40
 a3的存储内容是 30
 a2的存储内容是 20
 a1的存储内容是 10
 pArray的存储内容是 0x600000c0c690
 以上内存地址如图1

 
 查看0x600000c0c690的内存
 0x600000c0c690的存储内容是 0x00007ff7bfeff244 (a1的地址)
 0x600000c0c698的存储内容是 0x00007ff7bfeff240 (a2的地址)
 0x600000C0C6A0的存储内容是 0x00007ff7bfeff23c (a3的地址)
 0x600000C0C6A8的存储内容是 0x00007ff7bfeff238 (a4的地址)
 0x600000C0C6B0的存储内容是 0x00007ff7bfeff234 (a5的地址)
 以上内存地址如图2
 
 
 
 *pArray = &a1;
 *(pArray + 1) = &a2;
 *(pArray + 2) = &a3;
 *(pArray + 3) = &a4;
 *(pArray + 4) = &a5;
 
 pArray指向的是0x600000c0c690
 *pArray就是解引用 取出这个地址的存储内容
 pArray + 1指向的是0x600000c0c698
 *(pArray + 1)就是解引用 取出这个地址的存储内容
 以此内推
 
 
//    pArray[0] = &a1;
//    pArray[1] = &a2;
//    pArray[2] = &a3;
//    pArray[3] = &a4;
//    pArray[4] = &a5;
 
 这种写法就是把pArray, 当做数组来访问.
 本质来上面的写法没有区别, 可以通过查看汇编代码, 两者没有区别.
 那就可以这样理解
 int **pArray = malloc(sizeof(int *) * 5);
 malloc方法返回的是void *类型
 假如你用int *p = malloc(sizeof(int) * 5); 这里就是在堆上开辟5个int的内存, 存储int值, p的值就是这段内存的起始位置, 可以看开辟的这一段连续的内存看成一个int数组
 那int **pArray = malloc(sizeof(int *) * 5); 就是在堆上开辟5个int*的内存, 存储int*, p的值就是这段内存的起始位置, 可以看开辟的这一段连续的内存看成一个int *数组
 
 */


/*
 
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

 int *pArray[5];
 在栈区, 创建了一个数组, 数组类型是int *, 也是数组存储的是int *.
 可以参考 int array[5]; 是创建了一个数组, 存储的是int.
 
 for (int i = 0; i < 5; i++) {
     // 在堆区开辟空间
     pArray[i] = malloc(sizeof(int));
     *(pArray[i]) = 10 + i;
 }
 pArray的每个元素里, 都存储的是, 在堆上开辟的空间
 */
