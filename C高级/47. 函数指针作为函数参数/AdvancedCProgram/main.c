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


void printText(void *data, void(*print)(void *data)) {
    print(data);
}

void printDouble(void *data) {
    double *d = data;
    printf("%f\n", *d);
}

void printChar(void *data) {
    char *c = data;
    printf("%c\n", *c);
}

void printString(void *data) {
    char *c = data;
    printf("%s\n", c);
}



struct Person {
    char name[64];
    int age;
};


void printPerson(void *data) {
    struct Person *p = data;
    printf("%s, %d\n", p->name, p->age);
}



void func1(void) {
    double pi = 3.14;
    printText(&pi, printDouble);
    
    char c = 'D';
    printText(&c, printChar);
    
    char *str = "hello world";
    printText(str, printString);

    struct Person person = { "Jack", 18 };
    printText(&person, printPerson);
}


int main() {
    func1();
    
    return EXIT_SUCCESS;
}

