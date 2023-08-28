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

// 变量的修改方式
void func1(void) {
    
    // 1.直接修改
    int a = 10;
    a = 20;
    
    // 2.间接修改
    int *p = &a;
    *p = 40;
    
    printf("a = %d\n", a);
    printf("a = %d\n", *p);

}


struct Person {
    char a; //0-3   1
    int b;  //4-7   4
    char c; //8-11  1
    int d;  //12-15 4
};


void func2(void) {
    struct Person person = {'a', 10, 'c', 20};
    person.d = 40;
    printf("person.d = %d\n", person.d);

    
//    struct Person *p1 = &person;
//    printf("person.d = %ld\n", p1);
//    printf("person.d = %ld\n", p1 + 1);

    /*
     person.d = 140702053823040
     person.d = 140702053823056
     
     Person在内存中占用了16个字节, 因为内存对齐
     */

    
    char *p1 = &person;
    *(int *)(p1 + 12) = 50;
    printf("person.d = %d\n", person.d);
    
    
    int *p2 = &person;
    *(int *)(p2 + 3) = 60;
    printf("person.d = %d\n", person.d);

}

int main() {
    
//    func1();
    
    func2();
    
    return EXIT_SUCCESS;
}
