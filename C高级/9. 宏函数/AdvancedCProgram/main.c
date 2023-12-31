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


#define MYADD(x, y) ((x) + (y))

// 宏函数需要添加小括号修饰, 保证运行的完整性
// 通常会讲频繁 短小的函数, 写成宏函数
// 宏函数 会比普通函数载一定程度上 效率高, 省区普通函数入栈, 出栈时间上的开销

int main() {
    
    int r = MYADD(10, 20);
    printf("%d\n", r);
    
    return EXIT_SUCCESS;
}


/*
 来自ChatGPT4
 
 ------------------------------------------------------------------------------------------------------------------------
 c语言 宏定义函数
 ------------------------------------------------------------------------------------------------------------------------
 在C语言中，宏定义是预处理器的一部分，用于在编译前替换代码。我们可以使用#define指令来定义一个宏。与函数相比，宏有一些优点，比如无需为参数分配存储空间，没有函数调用的开销等。然而，对于复杂的代码，宏可能会导致错误，因此建议谨慎使用。

 以下是如何在C语言中定义一个宏的示例：

 ```c
 #include <stdio.h>

 // 定义一个计算两数之和的宏
 #define ADD(x, y) ((x) + (y))

 int main() {
     int a = 10;
     int b = 20;
     
     // 使用定义的宏进行计算
     int sum = ADD(a, b);
     
     printf("The sum is: %d\n", sum);
     
     return 0;
 }
 ```

 在这个示例中，我们定义了一个名为ADD的宏，该宏接受两个参数x和y并返回它们的和。注意，在宏中使用参数时，通常会将它们括在括号内，以防止操作符优先级的问题。例如，如果我们写的是`#define ADD(x, y) x + y`，那么`ADD(1, 2) * 3`将会被展开为`1 + 2 * 3`，结果为7，而我们期望的结果是9。 ------------------------------------------------------------------------------------------------------------------------
 */


