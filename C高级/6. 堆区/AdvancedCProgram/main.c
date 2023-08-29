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


//int *getSpace(void) {
//    int *p = malloc(sizeof(int) * 5);
//    if (p == NULL) {
//        return NULL;
//    }
//
//    for (int i = 0; i < 5; i++) {
//        p[i] = 100 + i;
//    }
//
//    return p;
//}
//
//void func1(void) {
//
//    int *p = getSpace();
//    for (int i = 0; i < 5; i++) {
//        printf("%d\n", p[i]);
//    }
//
//    // 手动创建 手动释放
//    free(p);
//    p = NULL;
//
//}
//


void allocateSpace(char *pp) {
    char *temp = malloc(100);
    memset(temp, 0, 100);
    strcpy(temp, "hello world");
    pp = temp;
}

void func2(void) {
    char * p = NULL;
    allocateSpace(p);
    printf("%s\n", p);
}


void allocateSpace2(char **pp) {
    char *temp = malloc(100);
    memset(temp, 0, 100);
    strcpy(temp, "hello world");
    *pp = temp;
}

void func22(void) {
    char * p = NULL;
    allocateSpace2(&p);
    printf("%s\n", p);
    
    free(p);
    p = NULL;
}

int main() {
    func22();
    return EXIT_SUCCESS;
}


/*
 ------------------------------------------------------------------------------------------------------------------------

 void allocateSpace(char *pp) {
    char *temp = malloc(100);
    memset(temp, 0, 100);
    strcpy(temp, "hello world");
    pp = temp;
 }

 void func2(void) {
    char * p = NULL;
    allocateSpace(p);
    printf("%s\n", p);
 }

 C语言中, 调用func2, 会得到什么结果?

 
 ------------------------------------------------------------------------------------------------------------------------
  
 
 调用func2时，会发生段错误（Segmentation fault）。这是因为我们试图打印一个NULL指针p。

 在allocateSpace函数中，我们为temp分配了内存，并将"hello world"复制到temp指向的内存区域。 然后尝试通过将temp赋值给pp来更改原来的指针p，但是这没有效果。当我们返回到func2时，p仍然是NULL。这是因为在C语言中，所有函数参数都是按值传递的。这意味着当我们修改pp时，只更改了一个局部副本，而原指针p并未受影响。

 所以当我们试图打印p指向的内容时，程序就会崩溃，因为p是一个NULL指针，它没有指向任何有效的内存区域。

 为了解决这个问题，我们需要把pp的地址传给allocateSpace，这样我们就可以直接修改原指针p，而不是它的一个副本。下面是修改后的代码：

 ```c
 void allocateSpace(char **pp) {
     char *temp = malloc(100);
     memset(temp, 0, 100);
     strcpy(temp, "hello world");
     *pp = temp;
 }

 void func2(void) {
     char * p = NULL;
     allocateSpace(&p);
     printf("%s\n", p);
 }
 ```

 这个版本的程序会打印出"hello world"。
 
 ------------------------------------------------------------------------------------------------------------------------

 因为在C语言中，所有函数参数都是按值传递的
 这句话怎么理解?

 ------------------------------------------------------------------------------------------------------------------------

 在C语言中，当你把一个参数传递给函数时，实际上是在为该参数创建了一个新的副本。这个副本和原来的变量是完全独立的，修改副本的值不会影响到原来的变量。

 例如，在以下代码中：

 ```c
 void func1(int a) {
     a = 5;
 }

 void main() {
     int x = 10;
     func1(x);
     printf("%d\n", x); // 输出10，而不是5
 }
 ```

 `func1(x)`中的x只是传递给func1函数的一个副本，func1中改变a的值并不会影响到main函数中的x。

 然而，如果你传递的是一个指针，并在函数内部修改这个指针所指向的值，那么原来的数据确实会被更改。但如果你尝试改变指针本身（即更改指针指向的地址），如在`allocateSpace`函数中那样，那么这种更改就只会影响局部副本，不会影响到原来的指针。因为你只是更改了副本的值，而原来的指针仍然保持不变。
 */
