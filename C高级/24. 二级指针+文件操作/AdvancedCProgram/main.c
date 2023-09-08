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


int getFileLines(FILE *file) {
    if (file == NULL) {
        return -1;
    }
    char buf[1024] = { 0 };
    int lines = 0;
    while (fgets(buf, 1024, file) != NULL) {
        lines++;
    }
    // 把光标移动到文件首行
    fseek(file, 0, SEEK_SET);
    return lines;
}

//void readFile(FILE *file, int length, char ***pArray) {
//    if (file == NULL) {
//        return;
//    }
//    if (length <= 0) {
//        return;
//    }
//    if (pArray == NULL) {
//        return;
//    }
//    char buf[1024] = { 0 };
//    int index = 0;
//    while (fgets(buf, 1024, file) != NULL) {
//        int currentLength = (int)strlen(buf) + 1;    //strlen 是没有\0的长度 需要加上\0的
//        char *p = malloc(sizeof(char) * currentLength);
//        strcpy(p, buf);
//        (*pArray)[index++] = p;
//
//        memset(buf, 0, 1024);
//    }
//}


void readFile(FILE *file, int length, char **pArray) {
    if (file == NULL) {
        return;
    }
    if (length <= 0) {
        return;
    }
    if (pArray == NULL) {
        return;
    }
    char buf[1024] = { 0 };
    int index = 0;
    while (fgets(buf, 1024, file) != NULL) {
        int currentLength = (int)strlen(buf) + 1;    //strlen 是没有\0的长度 需要加上\0的
        char *p = malloc(sizeof(char) * currentLength);
        strcpy(p, buf);
        (pArray)[index++] = p;
        
        memset(buf, 0, 1024);
    }
}


void showFile(char **pArray, int length) {
    for (int i = 0; i < length; i++) {
//        printf("%s", pArray[i]);
        printf("%s", *(pArray + i));
    }
    printf("\n");
}

void func1(void) {
    // 这里是绝对本机的路径
    FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/24. 二级指针+文件操作/AdvancedCProgram/text.txt", "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    
    int lines = getFileLines(file);
    //printf("%d\n", lines);
    char **pArray = malloc(sizeof(char *) * lines);
//    readFile(file, lines, &pArray);
    readFile(file, lines, pArray);
    showFile(pArray, lines);
    
    for (int i = 0; i < lines; i++) {
        free(pArray[i]);
        pArray[i] = NULL;
    }
    free(pArray);
    pArray = NULL;
}


int main() {
    func1();
//    func2();
    
    return EXIT_SUCCESS;
}




/*
 c语言中, int * 作为函数参数传递时, 有什么问题和注意点?

 
 1. 指针变量为地址，函数参数传递的是复制品：在 C 语言中，当我们将一个指针作为函数参数传递时，实际上传递的是这个指针的复制品，也就是说，在函数内部，我们不能通过改变这个复制品来改变原指针的值，但是可以通过这个复制品（即传递过来的指针）修改它所指向的内容。

 2. 需要注意空指针：在使用指针作为函数参数时，必须考虑到空指针的问题。如果传入的指针可能为NULL，那么在函数内部使用该指针之前，需要先进行判断。否则，如果直接使用空指针去访问数据，将会导致程序崩溃。

 3. 要管理内存：特别是在动态分配内存的情况下，你必须确定何时以及在何处释放内存。如果在函数内部分配了内存，必须在相应的地方释放它，否则可能会导致内存泄漏。

 4. 需要保证指针指向的内存有效：指向的内存不能被意外释放或者覆盖，否则通过指针访问数据就可能出错。

 5. 如果指针用于输出参数：注意函数内部需为其分配内存，调用方则需负责释放这部分内存。

 6. 需要注意线程安全性：如果多个线程可能同时访问和修改同一块内存，就需要考虑同步问题，以防止数据竞争条件。
 
 */


/*
 
 c语言中
 char **pArray

 pArray, *pArray, **pArray, pArray[0], *(pArray[0]), (*pArray)[0] 分布代表什么, 内存是怎么样的?

 
 
 
 在C语言中，`char **pArray` 是一个二级指针，也叫做“指向指针的指针”。

 1. `pArray` 代表了这个二级指针的起始地址。你可以把它想象成二维数组的第一行的首地址。

 2. `*pArray` 指向了第一级（或者说第一个）指针，这个指针又指向一个字符型数值。

 3. `**pArray` 指向的是最后的字符型数值。这个数值实际上就是一个字符。

 4. `pArray[0]`相当于`*(pArray+0)`， 它也是指向第一个指针，这个指针同样指向一个字符型数值。

 5. `*(pArray[0])` 或者`**pArray`则表示的是这个字符型数值。

 6. `(*pArray)[0]` 表示取第一个指针指向的字符串的第一个字符。

 内存方面，你可以将它想象为一个二维的网格。每一行都是一个字符数组，而`pArray`则是指向这些行的指针。所以`pArray`存储的是这些行（也就是字符数组）的地址。

 值得注意的是，`pArray`、`*pArray`和`**pArray`都只是地址，它们并不包含任何实际的数据。但是通过它们，我们可以访问到存储在这些地址中的数据。
 */

/*
 pArray + 1, *(pArray + 1)
 
 pArray + 1 实际上是将指针 pArray 向后移动一位。因为 pArray 是一个指向指针的指针，所以这里“移动一位”的意思是将 pArray 的值（也就是地址）增加一个指针大小。因此，pArray + 1 指向的是下一个字符指针。

 *(pArray + 1) 则是取出由 pArray + 1 指向的字符指针的值，也就是说它返回了第二个字符串的首地址。
 */
