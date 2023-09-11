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


// 左移运算<<  a*2^n
void func1(void) {
    int a = 2;
    int b = a << 2;     //a * 2^2
    printf("%d\n", b);
}

// 右移运算>>  a/2^n
void func2(void) {
    int a = 20;
    int b = a >> 2;     //a / 2^2
    printf("%d\n", b);
}


int main() {
//    func1();
    func2();
    
    return EXIT_SUCCESS;
}


/*
 
 func1 汇编
 
 AdvancedCProgram`func1:
     0x100003f60 <+0>:  pushq  %rbp
     0x100003f61 <+1>:  movq   %rsp, %rbp
     0x100003f64 <+4>:  subq   $0x10, %rsp
     0x100003f68 <+8>:  movl   $0x2, -0x4(%rbp)
 ->  0x100003f6f <+15>: movl   -0x4(%rbp), %eax
     0x100003f72 <+18>: shll   $0x2, %eax
     0x100003f75 <+21>: movl   %eax, -0x8(%rbp)
     0x100003f78 <+24>: movl   -0x8(%rbp), %esi
     0x100003f7b <+27>: leaq   0x30(%rip), %rdi          ; "%d\n"
     0x100003f82 <+34>: movb   $0x0, %al
     0x100003f84 <+36>: callq  0x100003fac               ; symbol stub for: printf
     0x100003f89 <+41>: addq   $0x10, %rsp
     0x100003f8d <+45>: popq   %rbp
     0x100003f8e <+46>: retq

 
 汇编语言
 shll $0x2, %eax
 是什么意思?

 
 这是一个x86汇编语言的指令。shll指的是向左移位，$0x2表示移动的位数（2位），%eax则是操作数，也就是将要进行操作的寄存器。
 简单来说，shll $0x2, %eax这条指令的作用就是将寄存器eax中的值左移2位。在二进制中，左移操作等同于乘以2的n次方（n为移动的位数），所以这条指令实际上是将eax中的值乘以4（2的2次方）。
 
 
 shll 是什么单词的缩写

 shll 是 Shift Left Long 的缩写，意思是把一个长整数（通常指32位）向左移位。

*/




/*
 
 func2 汇编

 
 AdvancedCProgram`func2:
     0x100003f60 <+0>:  pushq  %rbp
     0x100003f61 <+1>:  movq   %rsp, %rbp
     0x100003f64 <+4>:  subq   $0x10, %rsp
 ->  0x100003f68 <+8>:  movl   $0x14, -0x4(%rbp)
     0x100003f6f <+15>: movl   -0x4(%rbp), %eax
     0x100003f72 <+18>: sarl   $0x2, %eax
     0x100003f75 <+21>: movl   %eax, -0x8(%rbp)
     0x100003f78 <+24>: movl   -0x8(%rbp), %esi
     0x100003f7b <+27>: leaq   0x30(%rip), %rdi          ; "%d\n"
     0x100003f82 <+34>: movb   $0x0, %al
     0x100003f84 <+36>: callq  0x100003fac               ; symbol stub for: printf
     0x100003f89 <+41>: addq   $0x10, %rsp
     0x100003f8d <+45>: popq   %rbp
     0x100003f8e <+46>: retq

 
 
 sarl $0x2, %eax

 这是x86汇编语言的指令。sarl 指的是算术右移，$0x2 是移动的位数（2位），%eax 则是操作数，也就是将要进行操作的寄存器。

 简单来说，sarl $0x2, %eax 这条指令的作用就是将寄存器 eax 中的值向右进行算术位移两位。在二进制中，一个数向右移n位等同于除以2^n，但是算术右移会保留符号位。因此，这条命令实际上是将 eax 中的值除以 4（即2的2次方），并且保持其符号不变。
 
 sarl 是 Shift Arithmetic Right Long 的缩写，意思是对一个长整数（通常指32位）进行算术右移。
 
 */
