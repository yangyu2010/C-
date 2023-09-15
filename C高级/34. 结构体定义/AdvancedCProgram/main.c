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



/*
struct Person {
    char name[64];
    int age;
};


void func1(void) {
    struct Person p = {"Jack", 18};
    printf("姓名:%s 年龄:%d\n", p.name, p.age);
}
 */





/*
struct Person {
    char name[64];
    int age;
};

typedef struct Person MY_PERSON;

void func1(void) {
    MY_PERSON p = {"Jack", 18};
    printf("姓名:%s 年龄:%d\n", p.name, p.age);
}
 */




/*
typedef struct Person {
    char name[64];
    int age;
}MY_PERSON;

void func1(void) {
    MY_PERSON p = {"Jack", 18};
    printf("姓名:%s 年龄:%d\n", p.name, p.age);
}
 */





/*
struct Person {
    char name[64];
    int age;
}p;

void func1(void) {
//    p = {"Jack", 18};
//    p.name = "Jack";
    strcpy(p.name, "Jack");
    p.age = 18;
    printf("姓名:%s 年龄:%d\n", p.name, p.age);
}
 */





/*
struct Person {
    char name[64];
    int age;
}p = {"Jack", 18};

void func1(void) {
    printf("姓名:%s 年龄:%d\n", p.name, p.age);
}
 */





/*
// 匿名结构体
struct {
    char name[64];
    int age;
}p = {"Jack", 18};

void func1(void) {
    printf("姓名:%s 年龄:%d\n", p.name, p.age);
}
 */



struct Person {
    char name[64];
    int age;
};


void func1(void) {
    // 创建在栈上
    struct Person p = {"Jack", 18};
    printf("姓名:%s 年龄:%d\n", p.name, p.age);

    struct Person *pp = malloc(sizeof(struct Person));
    //pp->name = "Jack2";
    
    strcpy(pp->name, "Rose");
    pp->age = 20;
    printf("姓名:%s 年龄:%d\n", pp->name, pp->age);

    if (pp != NULL) {
        free(pp);
        pp = NULL;
    }
}


void printArray(struct Person persons[], int length) {
    for (int i = 0; i < length; i++) {
        printf("姓名:%s 年龄:%d\n", persons[i].name, persons[i].age);
    }
}

void func2(void) {
    struct Person persons[] = {
        {"Jack1", 11},
        {"Jack2", 12},
        {"Jack3", 13},
        {"Jack4", 14},
    };
    int length = sizeof(persons) / sizeof(struct Person);
//    for (int i = 0; i < length; i++) {
//        printf("姓名:%s 年龄:%d\n", persons[i].name, persons[i].age);
//    }
    printArray(persons, length);
    
}


void func3(void) {
    struct Person *persons = malloc(sizeof(struct Person) * 4);
    for (int i = 0; i < 4; i++) {
//        persons[i].name = "";
//        strcpy(persons[i].name, "")
        sprintf(persons[i].name, "Name_%d", i);
        persons[i].age = 10 + i;
    }
//    for (int i = 0; i < 4; i++) {
//        printf("姓名:%s 年龄:%d\n", persons[i].name, persons[i].age);
//    }
    
    printArray(persons, 4);
    
    if (persons != NULL) {
        free(persons);
        persons = NULL;
    }
}

int main() {
    //func1();
    //func2();
    func3();
    
    return EXIT_SUCCESS;
}

