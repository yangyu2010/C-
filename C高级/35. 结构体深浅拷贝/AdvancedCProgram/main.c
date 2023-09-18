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
    struct Person p1 = {"Tom", 18};
    struct Person p2 = {"Jerry", 20};
    
    printf("%s %d\n", p1.name, p1.age);
    printf("%s %d\n", p2.name, p2.age);

    p1 = p2;
    
    printf("%s %d\n", p1.name, p1.age);
    printf("%s %d\n", p2.name, p2.age);
}
 */


struct Person {
    char *name;
    int age;
};

/*
void func1(void) {
    struct Person p1;
    p1.name = malloc(sizeof(char) * 64);
    strcpy(p1.name, "Tom");
    p1.age = 18;
    
    struct Person p2;
    p2.name = malloc(sizeof(char) * 128);
    strcpy(p2.name, "Jerry");
    p2.age = 18;

    printf("%s %d\n", p1.name, p1.age);
    printf("%s %d\n", p2.name, p2.age);

    p1 = p2;
    
    printf("%s %d\n", p1.name, p1.age);
    printf("%s %d\n", p2.name, p2.age);

    if (p1.name != NULL) {
        free(p1.name);
        p1.name = NULL;
    }
    
    // AdvancedCProgram(15857,0x7ff8585e7640) malloc: *** error for object 0x600002c00180: pointer being freed was not allocated
    // AdvancedCProgram(15857,0x7ff8585e7640) malloc: *** set a breakpoint in malloc_error_break to debug
    if (p2.name != NULL) {
        free(p2.name);
        p2.name = NULL;
    }
}
 */


void func1(void) {
    struct Person p1;
    p1.name = malloc(sizeof(char) * 64);
    strcpy(p1.name, "Tom");
    p1.age = 18;
    
    struct Person p2;
    p2.name = malloc(sizeof(char) * 128);
    strcpy(p2.name, "Jerry");
    p2.age = 20;

    printf("%s %d\n", p1.name, p1.age);
    printf("%s %d\n", p2.name, p2.age);
    
    //
    // p1 = p2;
    if (p1.name != NULL) {
        free(p1.name);
        p1.name = NULL;
    }
    
    p1.name = malloc(strlen(p2.name) + 1);
    strcpy(p1.name, p2.name);
    p1.age = p2.age;
    
    printf("%s %d\n", p1.name, p1.age);
    printf("%s %d\n", p2.name, p2.age);

    if (p1.name != NULL) {
        free(p1.name);
        p1.name = NULL;
    }
    
    if (p2.name != NULL) {
        free(p2.name);
        p2.name = NULL;
    }
}

int main() {
    func1();
    
    return EXIT_SUCCESS;
}

