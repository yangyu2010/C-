//
//  main.c
//  AdvancedCProgram
//
//  Created by Yu Yang on 8/23/23.
//

/*
 c语言中 typedef 本质是什么

 在C语言中，`typedef`是一个关键字，它用来为已存在的数据类型创建一个新的名称（别名）。这主要被用于简化某些复杂的数据类型声明。

 例如，如果你有一个结构体：

 ```c
 struct Student {
   char name[50];
   int age;
 };
 ```

 你可以使用`typedef`来给它创建一个新的名称：

 ```c
 typedef struct Student STUDENT;
 ```
 然后你就可以使用`STUDENT`作为类型名来声明变量了，而不需要写出完整的`struct Student`。

 `typedef`并不创造新的数据类型，只是为现有的数据类型创建一个新的名字，所以说它的“本质”就是一个重命名或者说别名的工具。
 
 
 ------------------------------------------------------------------------
 
 
 typedef 是编译器实现的吗? 本质是替换字符串吗?

 `typedef` 是由编译器实现的。但是，它并不仅仅是替换字符串。

 在 C 语言中，`typedef`并不创造新的数据类型，而是为已存在的数据类型提供一个别名。它的本质功能是为了简化复杂数据类型的书写，使得代码更易于理解和维护。

 当你使用 `typedef` 创建一个别名时，编译器会在编译过程中记住这个别名和原本的数据类型关系，并在后续的代码中，每当遇到这个别名时，就会自动将其视为原本的数据类型处理。这个过程要比简单的字符串替换更复杂，涉及到编译器的符号表（symbol table）等机制。因此，可以说 `typedef`的实现既包括字符串替换，也包括其他编译器级别的操作。
 */



#define _CRI_SECURE_NO_WARNINGS
// VS下使用传统库函数, 会建议用_s更安全的函数, 如果不用会报错 C4996

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    char name[64];
    int age;
};

// typedef使用

// 1.起别名 -  简化struct关键字
void test01() {
    typedef struct Person STRPerson;
    struct Person p1 = {"Jack", 19};
    STRPerson p2 = {"Role", 20};
}


// 2.区分数据类型
void test02() {
    char* p1, p2;
    // p1 是char *
    // p2 是char
    // char* p1, *p2;
    
    typedef char * PChar;
    PChar p3, p4;
    
    // p3 是char *
    // p4 是char *

}


// 3.提高移植性
void test03() {
    long long a = 10;
    long long b = 10;

    typedef long long LInt;
    LInt c = 10;
    
}

int main() {
    
//    char buf[1024];
//    strcpy(buf, "hello word");
//    printf("%s\n", buf);
    
    system("pause");

    return EXIT_SUCCESS;
}
