//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;

/**
 c++封装理念
 将属性和行为作为一个整体, 来表现生活中的事物
 将属性和行为, 加以权限控制
 */

struct Person {
    char name[64];
    int age;
    
    void eat() {
        printf("%s吃饭了\n", name);
    }
    
};


struct Dog {
    char name[64];
    int age;
    
    void eat() {
        printf("%s吃狗粮了\n", name);
    }
};



int main() {

    struct Person p;
    strcpy(p.name, "Jack");
    p.age = 20;
    p.eat();
    
    struct Dog d;
    strcpy(d.name, "A Dog");
    d.age = 20;
    d.eat();

    return EXIT_SUCCESS;
}

