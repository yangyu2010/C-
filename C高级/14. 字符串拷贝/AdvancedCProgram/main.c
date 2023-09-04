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

void func1(void) {
    //字符数组只能初始化5个字符，当输出的时候，从开始位置直到找到0结束
    char str1[] = { 'h', 'e', 'l', 'l', 'o' };
//    char str1[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
    printf("%s\n",str1);
    
    //字符数组部分初始化，剩余填0
    char str2[100] = { 'h', 'e', 'l', 'l', 'o' };
    printf("%s\n", str2);

    //如果以字符串初始化，那么编译器默认会在字符串尾部添加'\0'
    char str3[] = "hello";
    printf("%s\n",str3);
    printf("sizeof str:%d\n",sizeof(str3));
    printf("strlen str:%d\n",strlen(str3));

    //sizeof计算数组大小，数组包含'\0'字符
    //strlen计算字符串的长度，到'\0'结束

    
    //那么如果我这么写,结果是多少呢？
    char str4[100] = "hello";
    printf("sizeof str:%d\n", sizeof(str4));
    printf("strlen str:%d\n", strlen(str4));

    
    //请问下面输入结果是多少？sizeof结果是多少？strlen结果是多少？
    char str5[] = "hello\0world";
    printf("%s\n",str5);
    printf("sizeof str5:%d\n",sizeof(str5));
    printf("strlen str5:%d\n",strlen(str5));

    //再请问下面输入结果是多少？sizeof结果是多少？strlen结果是多少？
    char str6[] = "hello\012world";
    printf("%s\n", str6);
    printf("sizeof str6:%d\n", sizeof(str6));
    printf("strlen str6:%d\n", strlen(str6));
}




// 字符串拷贝实现

// 1.利用数组实现
void copyString1(char *dest, char *src) {
    unsigned long length = strlen(src);
    for (int i = 0; i < length; i++) {
        printf("%c\n", src[i]);
        dest[i] = src[i];
    }
    // 字符串最后一定要加上\0
    dest[length] = '\0';
}

// 2.利用字符串指针
void copyString2(char *dest, char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void copyString3(char *dest, char *src) {
    while ((*dest++ = *src++)) {
//        printf("1\n");
        printf("%c", *(dest-1));
        printf(" %c\n", *src);
    }
    
    // 本质和上面的的一样 当src移动到\0的位置时 赋值完成后 会退出循环
    
    // 不会进入while循环 但是赋值操作已经进入了 a=0
//    int a = 1;
//    while (a = 0) {
//        printf("enter while");
//    }
//    printf("%d\n", 0);
    
    // 死循环 一直打印
//    int a = 0;
//    while (a = 1) {
//        printf("enter while");
//    }
}

void func2(void) {
    char *str = "hello world";
    char buf[1024];
    
    copyString3(buf, str);
    
    printf("%s\n", buf);
}


int main() {
    func2();
    
    return EXIT_SUCCESS;
}



/*
 来自ChatGPT4
 
 ------------------------------------------------------------------------------------------------------------------------
 c语言中, 下面的代码怎么执行, 为什么?

 int a = 1;
 while (a = 0) {
 printf("enter while");
 }
 printf("%d\n", 0);
 ------------------------------------------------------------------------------------------------------------------------
 这段c语言代码不会进入while循环，直接打印出0。

 解释如下：

 首先定义了一个整型变量a，并赋值为1。然后在while语句中对a进行赋值操作，将a的值设定为0。

 在C语言中, while(条件表达式) 用于判断是否进入循环体。如果条件表达式的值为非零，则执行循环体，否则跳过循环体。

 在这段代码中，条件表达式就是 `a = 0`，它首先给a赋值，然后返回赋值结果，再与0比较。因此，该条件表达式的值为0，所以不会进入while循环，而是直接跳到最后一行代码，输出0。

 总结起来，这段代码实际上是将a的值修改为0，然后因为while循环的条件不满足，所以没有执行while循环体内的代码，直接输出0。
 ------------------------------------------------------------------------------------------------------------------------
 赋值操作也会有返回值吗?
 ------------------------------------------------------------------------------------------------------------------------
 是的，赋值操作在C语言中实际上是有返回值的。赋值操作的返回值就是被赋予的值。

 例如，表达式 `a = 0` 的结果就是0。这个特性在C语言中的一些复杂表达式中会被利用到，例如连续赋值 `a = b = c = 0` 就是利用了这个特性。在这个表达式中，`c = 0` 的结果是0，然后这个结果被赋给b和a。所以最终a、b和c都被赋值为0。

 所以，在你给出的代码中，while循环的条件判断就是利用了这个特性。不过在实际编程中，将赋值操作作为判断条件并不常见，因为很容易引起理解上的混淆，可能导致程序逻辑错误。
 ------------------------------------------------------------------------------------------------------------------------
 */

