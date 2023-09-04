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


// 1.指针的步长代表 指针+1之后跳跃的字节数
void func1(void) {
    char *p = NULL;
    printf("%d\n", p);
    printf("%d\n", (p+1));

    int *p2 = NULL;
    printf("%d\n", p2);
    printf("%d\n", (p2+1));

    long *p3 = NULL;
    printf("%d\n", p3);
    printf("%d\n", (p3+1));
}


// 2.解引用的时候, 解出的字节数量
void func2(void) {
    char buf[1024] = { 0 };
    int a = 1000;
    memcpy(buf, &a, sizeof(int));
    
    char *p = buf;
    printf("%d\n", *(int *)p);
}


struct Person {
    char a;         //0 1 2 3
    int b;          //4 5 6 7
    char buf[64];   //8 - 71
    int d;          //72 73 74 75
};


void func3(void) {
    struct Person p = {"a", 10, "hello world", 20};
    
//    unsigned int offset = offsetof(struct Person, d);
//    printf("%d\n", sizeof(p));
    
    printf("%d\n", *(int *)((char *)&p + 72));
    printf("%d\n", offsetof(struct Person, d));
    
    //#define offsetof(s,m) ((size_t)&(((s*)0)->m))
}

/*
 
 void func3(void) {
     unsigned int offset = offsetof(struct Person, d);
 }

 
 AdvancedCProgram`func3:
     0x100003f70 <+0>:  pushq  %rbp
     0x100003f71 <+1>:  movq   %rsp, %rbp
 ->  0x100003f74 <+4>:  movl   $0x48, -0x4(%rbp)
     0x100003f7b <+11>: popq   %rbp
     0x100003f7c <+12>: retq

 */

int main() {
    func3();
    
    return EXIT_SUCCESS;
}


/*
 来自ChatGPT4
 
 ------------------------------------------------------------------------------------------------------------------------
 c语言下 解释一下下面的宏定义
 #define offsetof(s,m) ((size_t)&(((s*)0)->m))
 ------------------------------------------------------------------------------------------------------------------------
 这是一个常用于计算结构体成员在结构体中的偏移量的宏。其中`s`是结构体类型，而`m`是该结构体的一个成员。

 解析如下：

 1. `(s*)0`：首先把0转换为`s`类型的指针。因为0是空指针，此语句的目的主要是获取到类型为`s`的指针。
 2. `((s*)0)->m`：然后尝试去访问该结构体的成员`m`。此时并不会真正去访问内存地址为0处的数据（那样会造成程序崩溃），编译器仅仅需要知道如何从`s`类型的对象开始找到它的成员`m`即可。
 3. `&(((s*)0)->m)`：接着取该成员在结构体中的相对地址（偏移量）。由于指针是从0开始的，所以这个偏移量就代表了成员`m`在结构体`s`中的位置。
 4. `((size_t)&(((s*)0)->m))`：最后将该偏移量转换为`size_t`类型返回。

 例如，我们有一个如下的结构体:
 ```c
 struct test {
     int a;
     double b;
     char c;
 };
 ```
 使用`offsetof(struct test, b)`将会返回4(在大多数系统上)，代表`b`在`test`中的偏移量是4字节。
 ------------------------------------------------------------------------------------------------------------------------
 */

