//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;

// 引用的本质在C++内部中实现是一个指针常量
// Type &ref = val;
// Type *const ref = &val;
// C++编译器在编译过程中使用常指针作为引用的内部实现 ，因此引用所占用的空间大小与指针相同，只是这个过程是编译器内部实现，用户不可见。

int main() {
    int a = 10;
    //int &ref = a;
    //int *const ref = &a;      表示了ref不能更改, 但是*ref可以更改. 就是说ref的指向不能改, ref指向的内容可以修改
    
    int &aRef = a; //自动转换为 int * const aRef = &a; 这也能说明引用为什么必须初始化
    aRef = 20; //内部发现aRef是引用，自动帮我们转换为：*aRef = 20;
    cout << "a:" << a << endl;
    cout << "aRef:" << aRef << endl;

    return EXIT_SUCCESS;
}


/*
 
 int main() {
     int a = 10;
     int &ref = a;
     
     return EXIT_SUCCESS;
 }

 
 CPlusPlusProgram`main:
     0x100003f90 <+0>:  pushq  %rbp
     0x100003f91 <+1>:  movq   %rsp, %rbp
     0x100003f94 <+4>:  movl   $0x0, -0x4(%rbp)
     0x100003f9b <+11>: movl   $0xa, -0x8(%rbp)
 ->  0x100003fa2 <+18>: leaq   -0x8(%rbp), %rax
     0x100003fa6 <+22>: movq   %rax, -0x10(%rbp)
     0x100003faa <+26>: xorl   %eax, %eax
     0x100003fac <+28>: popq   %rbp
     0x100003fad <+29>: retq

 */



/*
 int main() {
     int a = 10;
     int *const ref = &a;
     
     return EXIT_SUCCESS;
 }

 
 
 CPlusPlusProgram`main:
     0x100003f90 <+0>:  pushq  %rbp
     0x100003f91 <+1>:  movq   %rsp, %rbp
     0x100003f94 <+4>:  movl   $0x0, -0x4(%rbp)
     0x100003f9b <+11>: movl   $0xa, -0x8(%rbp)
 ->  0x100003fa2 <+18>: leaq   -0x8(%rbp), %rax
     0x100003fa6 <+22>: movq   %rax, -0x10(%rbp)
     0x100003faa <+26>: xorl   %eax, %eax
     0x100003fac <+28>: popq   %rbp
     0x100003fad <+29>: retq

 */
