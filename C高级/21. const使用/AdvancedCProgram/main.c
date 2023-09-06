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

struct Person {
    char name[64];  //0-63
    int id;         //64-67
    int age;        //68-71
    double score;   //72-79
};


//void showPersonInfo(struct Person person) {
//    printf("姓名:%s\n学号:%d\n年龄:%d\n分数:%f\n", person.name, person.id, person.age, person.score);
//}

// 将struct Person person修改为struct Person *person, 节省资源
//void showPersonInfo(struct Person *person) {
//    person->age = 100;
//    printf("姓名:%s\n学号:%d\n年龄:%d\n分数:%f\n", person->name, person->id, person->age, person->score);
//}

// 添加const修饰, 防止误操作
// 但是还是可以通过内存来修改 只能防止直接修改
void showPersonInfo(const struct Person *person) {
//    char *p = (char *)person;
//    *(int *)(p+68) = 100;

    printf("姓名:%s\n学号:%d\n年龄:%d\n分数:%f\n", person->name, person->id, person->age, person->score);
}

int main() {
    struct Person person = {"Jack", 1, 20, 80};
    showPersonInfo(&person);
    
    printf("\n%d\n", person.age);
    
    return EXIT_SUCCESS;
}

