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
