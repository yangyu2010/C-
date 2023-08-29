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


const int a = 10;

void func1(void) {
    //a = 20;
    int *p = &a;
    *p = 20;
    
    // Thread 1: EXC_BAD_ACCESS (code=2, address=0x100003f9c)
}

// 在全局定义的const, 是存在常量区的, 直接修改失败, 间接修改失败
// 在函数内定义的const, 是存在栈中, 直接修改失败, 间接修改成功

void func2(void) {
    const int b = 20;
    int c = 40;
    //b = 30;
    
    int *p = &b;
    *p = 30;
    printf("b = %d\n", b);
    
    printf("a的地址是:%p\n", &a);
    printf("b的地址是:%p\n", &b);
    printf("c的地址是:%p\n", &c);

// a的地址是:0x100003f6c    常量区
// b的地址是:0x7ff7bfeff24c 栈区
// c的地址是:0x7ff7bfeff248 栈区

}


void func3(void) {
    char *p1 = "hello world";
    char *p2 = "hello world";
    printf("p的地址是:%p\n", &p1);
    printf("p的地址是:%d\n", p1);
    printf("p的地址是:%p\n", &p2);
    printf("p的地址是:%d\n", p2);

    printf("%s\n", p1);
    printf("%c\n", *p1);
}

int main() {
    
    //func1();
//    func2();
    func3();

    return EXIT_SUCCESS;
}


/*
 来自ChatGPT4
 
 ------------------------------------------------------------------------------------------------------------------------
 在c语言中, 定义了一个
 char *p = "hello world";
 那么, p, *p, &p 分别指什么, 怎么使用?
 ------------------------------------------------------------------------------------------------------------------------
 p: 它是一个字符指针，它指向的是"hello world"这个字符串常量存放的地址。

 *p: 这是对指针进行解引用操作。*p的值就是p所指向的内存地址上保存的内容，即"hello world"中的第一个字符’h’。

 &p: 这是获取p的地址。因为p本身也需要在内存中有一个位置来存储它所保存的地址信息，所以&p就是p这个变量自己的地址。
 ------------------------------------------------------------------------------------------------------------------------
 */


