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


#pragma pack(show)

/*

struct Student {
    char name;
    int age;
};

struct Teacher {
    int age;
    char name[64];
    struct Student student;
};

void func1(void) {
    struct Teacher teacher = {18, "Jack", 'A', 20};
    printf("%p\n", &teacher);
    printf("%lu\n", offsetof(struct Teacher, age));
    printf("%lu\n", offsetof(struct Teacher, name));
    printf("%lu\n", offsetof(struct Teacher, student));

    // 0x7ff7bfeff1f8
    // 0
    // 4
    // 68

    //图片1.jpg
}
 */




/*
struct Student {
    char name;
    int age;
};

struct Teacher {
    char age;
    char name;
    struct Student student;
    char id;
};

void func1(void) {
    struct Teacher teacher = {'A', 'B', 'C', 20, 'D'};
    printf("%p\n", &teacher);
    printf("%lu\n", offsetof(struct Teacher, age));
    printf("%lu\n", offsetof(struct Teacher, name));
    printf("%lu\n", offsetof(struct Teacher, student));
    printf("%lu\n", offsetof(struct Teacher, id));

    // 0x7ff7bfeff240
    // 0
    // 1
    // 4
    // 12

    //图片2.jpg
}
 */



struct Student {
//    char name;
//    char name2;
//    char name3;

    int age;
//    double score;
    char name;

};

struct Teacher {
    char age;
    char name;
    struct Student student;
    char id;
    char id2;
};

void func1(void) {
    struct Teacher teacher = {'A', 'B', 20, 'C', 'D', 'E'};
    printf("%p\n", &teacher);
    printf("%lu\n", offsetof(struct Teacher, age));
    printf("%lu\n", offsetof(struct Teacher, name));
    printf("%lu\n", offsetof(struct Teacher, student));
    printf("%lu\n", offsetof(struct Teacher, id));
    printf("%lu\n", offsetof(struct Teacher, id2));

    printf("\n");
    printf("%lu\n", sizeof(struct Teacher));
    printf("%lu\n", sizeof(struct Student));
    printf("\n");

    // 结构体 嵌套结构体
    
    // 内部结构体的偏移量必须是内部结构体最大属性的整数倍
}





int main() {
    func1();
    
    return EXIT_SUCCESS;
}

