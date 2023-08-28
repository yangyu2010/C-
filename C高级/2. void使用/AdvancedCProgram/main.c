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


// void 无类型, 不可以通过void创建变量, 原因是无法给void无类型变量分配内存

// 用途: 限定函数返回值 限定函数参数
void func1() {
    printf("func1 called\n");
    
    return;
}

// Too many arguments to function call, expected 0, have 1
//void func1(void) {
//    printf("func1 called\n");
//
//    return;
//}


// This old-style function definition is not preceded by a prototype
//void func2() {
//    void *v1 = NULL;
//}

// void * 万能指针, 可以不通过强制类型转换, 就可以转换成其他类型指针

void func2(void) {
    void *v1 = NULL;
    int *i1 = NULL;
    char *c1 = NULL;
    
    //Incompatible pointer types assigning to 'char *' from 'int *'
    c1 = i1;
    c1 = (char *)i1;
    
    // 上面两行的写法不一致, 第一行有警告, 第二行没有警告, 这只是编译器的功能(有没有警告)
    // 和实质运行代码没有关系, 也就是说, 两行代码没区别
    // 因为查看汇编代码 发现是一样的
    // 加 (char *) 也就是告诉编译器 强制转
    
    c1 = v1;
}


/*
AdvancedCProgram`func2:
    0x100003d50 <+0>:  pushq  %rbp
    0x100003d51 <+1>:  movq   %rsp, %rbp
    0x100003d54 <+4>:  movq   $0x0, -0x8(%rbp)
    0x100003d5c <+12>: movq   $0x0, -0x10(%rbp)
    0x100003d64 <+20>: movq   $0x0, -0x18(%rbp)
->  0x100003d6c <+28>: movq   -0x10(%rbp), %rax
    0x100003d70 <+32>: movq   %rax, -0x18(%rbp)
    0x100003d74 <+36>: movq   -0x10(%rbp), %rax
    0x100003d78 <+40>: movq   %rax, -0x18(%rbp)
    0x100003d7c <+44>: movq   -0x8(%rbp), %rax
    0x100003d80 <+48>: movq   %rax, -0x18(%rbp)
    0x100003d84 <+52>: popq   %rbp
    0x100003d85 <+53>: retq

*/

int main() {
    
//    func1(10);
    
    
    func2();

    return EXIT_SUCCESS;
}
