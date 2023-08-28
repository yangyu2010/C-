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

// 1.sizeof 本质 不是函数, 而是操作符
void func1(void) {
    int a = sizeof(int);
    int b = sizeof(int *);
    int c = sizeof(double);
    int d = sizeof(double *);
    
    
    /*
     AdvancedCProgram`func1:
         0x100003de0 <+0>:  pushq  %rbp
         0x100003de1 <+1>:  movq   %rsp, %rbp
         0x100003de4 <+4>:  movl   $0x4, -0x4(%rbp)
     ->  0x100003deb <+11>: movl   $0x8, -0x8(%rbp)
         0x100003df2 <+18>: movl   $0x8, -0xc(%rbp)
         0x100003df9 <+25>: movl   $0x8, -0x10(%rbp)
         0x100003e00 <+32>: popq   %rbp
         0x100003e01 <+33>: retq
     */
    
//    printf("size of int = %d\n", sizeof(int));
//
//    double d = 3;
//    printf("size of double = %d\n", sizeof(d));
//    printf("size of double = %d\n", sizeof d);
}

// 2.sizeof 返回值类型 无符号类型
void func2(void) {
    unsigned int a = 10;
    int b = a - 20;
//    printf("b = %d\n", b);
//    
    if (b > 0) {
//        printf("大于0\n");
    } else {
//        printf("小于等于0\n");
    }

    /*
     unsigned int a = 10;
     int b = a - 20;

     AdvancedCProgram`fun2:
         0x100003f40 <+0>:  pushq  %rbp
         0x100003f41 <+1>:  movq   %rsp, %rbp
         0x100003f44 <+4>:  movl   $0xa, -0x4(%rbp)
         0x100003f4b <+11>: movl   -0x4(%rbp), %eax
         0x100003f4e <+14>: subl   $0x14, %eax
         0x100003f51 <+17>: movl   %eax, -0x8(%rbp)
     ->  0x100003f54 <+20>: popq   %rbp
         0x100003f55 <+21>: retq
     */
    
    
    /*
     int a = 10;
     int b = a - 20;

     AdvancedCProgram`fun2:
         0x100003f40 <+0>:  pushq  %rbp
         0x100003f41 <+1>:  movq   %rsp, %rbp
         0x100003f44 <+4>:  movl   $0xa, -0x4(%rbp)
         0x100003f4b <+11>: movl   -0x4(%rbp), %eax
         0x100003f4e <+14>: subl   $0x14, %eax
         0x100003f51 <+17>: movl   %eax, -0x8(%rbp)
     ->  0x100003f54 <+20>: popq   %rbp
         0x100003f55 <+21>: retq
     */
    
}

// 上面的方法写错了, 直接用int修饰了b, 所以看不出来
void func22(void) {
     int a = 10;
     int b = a - 20;
//    printf("b = %d\n", b);
//
    if (b > 0) {
//        printf("大于0\n");
    } else {
//        printf("小于等于0\n");
    }

    /*
     unsigned int a = 10;
     unsigned int b = a - 20;
     if (b > 0) {
     } else {
     }
     
     AdvancedCProgram`fun22:
         0x100003f30 <+0>:  pushq  %rbp
         0x100003f31 <+1>:  movq   %rsp, %rbp
         0x100003f34 <+4>:  movl   $0xa, -0x4(%rbp)
     ->  0x100003f3b <+11>: movl   -0x4(%rbp), %eax
         0x100003f3e <+14>: subl   $0x14, %eax
         0x100003f41 <+17>: movl   %eax, -0x8(%rbp)
         0x100003f44 <+20>: cmpl   $0x0, -0x8(%rbp)
         0x100003f48 <+24>: jbe    0x100003f53               ; <+35> at main.c
         0x100003f4e <+30>: jmp    0x100003f58               ; <+40> at main.c:85:1
         0x100003f53 <+35>: jmp    0x100003f58               ; <+40> at main.c:85:1
         0x100003f58 <+40>: popq   %rbp
         0x100003f59 <+41>: retq
     */
    
    /*
     unsigned int a = 10;
     unsigned int b = a - 20;
     if (b > 0) {
     } else {
     }
     
     AdvancedCProgram`fun22:
         0x100003f30 <+0>:  pushq  %rbp
         0x100003f31 <+1>:  movq   %rsp, %rbp
         0x100003f34 <+4>:  movl   $0xa, -0x4(%rbp)
     ->  0x100003f3b <+11>: movl   -0x4(%rbp), %eax
         0x100003f3e <+14>: subl   $0x14, %eax
         0x100003f41 <+17>: movl   %eax, -0x8(%rbp)
         0x100003f44 <+20>: cmpl   $0x0, -0x8(%rbp)
         0x100003f48 <+24>: jle    0x100003f53               ; <+35> at main.c
         0x100003f4e <+30>: jmp    0x100003f58               ; <+40> at main.c:125:1
         0x100003f53 <+35>: jmp    0x100003f58               ; <+40> at main.c:125:1
         0x100003f58 <+40>: popq   %rbp
         0x100003f59 <+41>: retq
     */
    
    
    /*
     jle jbe 只要这里不同 以下来自ChatGPT
     
     jle和jbe是两条汇编跳转指令，分别表示“小于等于跳转”和“以下等于跳转”。

     1) jle：Jump if Less or Equal，如果源操作数小于或等于目标操作数，则控制将转移到目标指令。这通常用于有符号的比较。

     2) jbe：Jump if Below or Equal，如果源操作数小于或等于目标操作数，则控制将转移到目标指令。这通常用于无符号的比较。

     所以主要区别在于，jle通常用于有符号的比较，而jbe通常用于无符号的比较。
     */
}



void func222(void) {
    if (sizeof(int) - 5 > 0) {
        printf("大于0\n");
    } else {
        printf("小于等于0\n");
    }
}


// Sizeof on array function parameter will return size of 'int *' instead of 'int[]'
// 当数组名作为函数参数时, 会退化为指针, 指向数组中第一个元素的位置
int getArrayLength(int array[]) {
    return sizeof(array);
}

// sizeof 用途: 统计数组长度
void func3(void) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    
//    array length = 32
//    printf("array length = %d\n", sizeof(arr));
    
//    array length = 8
    printf("array length = %d\n", getArrayLength(arr));
    printf("array length = %d\n", sizeof(int *));

}


int main() {
    
    func1();
    
    
    return EXIT_SUCCESS;
}
