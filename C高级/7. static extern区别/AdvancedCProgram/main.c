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

//static 静态变量
// 在运行前分配内存, 程序运行结束时, 生命周期结束. 在本文件内都可以使用静态变量
static int a = 10;

void func1(void) {
    static int b = 20;
    int c = 10;
    printf("a地址是:%p\n", &a);
    printf("b地址是:%p\n", &b);
    printf("c地址是:%p\n", &c);
}

// a b都是静态变量, 生命周期一样, 而且都存在静态区. 只是作用域不一样.
// b只能在func1函数中使用, a能在当前文件中使用.

int main() {
    func1();
    
    extern int AAA;
    extern void test(void);
    printf("%d\n", AAA);
    test();
    
    return EXIT_SUCCESS;
}


/*
 来自ChatGPT4
 
 ------------------------------------------------------------------------------------------------------------------------
 c 语言中 static关键字
 ------------------------------------------------------------------------------------------------------------------------
 在 C 语言中，static 关键字有三种使用场景：

    1.静态局部变量：在函数内部声明的静态变量。即使函数调用结束，这个变量的值也不会消失，下次调用这个函数时，还能继续使用上次的值。静态局部变量只被初始化一次。

    2.静态全局变量：在函数外部声明的静态变量。这种变量的作用范围仅限于本文件，其他文件不能访问。静态全局变量可以避免全局变量的污染，使得全局变量只服务于一个文件。

    3.静态函数：在函数前加 static，使得这个函数只能在本文件中使用，其他文件不能使用这个函数。这样可以减少命名冲突的可能性。
 ------------------------------------------------------------------------------------------------------------------------
 */



/*
 来自ChatGPT4
 
 ------------------------------------------------------------------------------------------------------------------------
 c语言中, 全局变量会隐式添加extern吗
 ------------------------------------------------------------------------------------------------------------------------
 在C语言中，全局变量或函数默认已经具备了extern的属性。也就是说，如果你在一个源文件中定义了一个全局变量或函数，它可以在其它源文件中被访问，前提是在其他源文件中使用extern进行了声明。

 例如下面两个源文件：

 file1.c
 ```c
    int global_var = 10;

    void global_func() {
        // code here
    }
 ```

 file2.c
 ```c
    extern int global_var;
    extern void global_func();

    int main() {
        printf("%d\n", global_var);  // OK，输出：10
        global_func();  // OK
        return 0;
    }
 ```

 所以，虽然在定义全局变量或函数时我们通常不会显式添加extern关键字，但实际上它们已经具备了extern的效果。
 ------------------------------------------------------------------------------------------------------------------------
 */
