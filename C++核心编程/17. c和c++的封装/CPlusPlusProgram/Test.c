//
//  Test.c
//  CPlusPlusProgram
//
//  Created by Yu Yang on 11/22/23.
//

#include "Test.h"
#include <string.h>
#include <stdlib.h>

struct Person {
    char name[64];
    int age;
};

void PersonEat(struct Person *p) {
    printf("%s吃饭了\n", p->name);
}


struct Dog {
    char name[64];
    int age;
};

void DogEat(struct Dog *p) {
    printf("%s吃狗粮了\n", p->name);
}






void cFunc(void) {
    struct Person p;
    strcpy(p.name, "Jack");
    p.age = 20;
    //PersonEat(&p);
    
    
    struct Dog d;
    strcpy(d.name, "A Dog");
    d.age = 20;
    //DogEat(&d);
    
    
    PersonEat(&d);
    DogEat(&p);
}


//int main() {
//    cFunc();
//    
//    return EXIT_SUCCESS;
//}

