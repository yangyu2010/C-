//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;


struct Person {
    int age;
};





void allocateSpace1(Person **p) {
    *p = (Person *)malloc(sizeof(struct Person));
    //*p->age = 10;
    (*p)->age = 10;
}

void func1(void) {
    Person *p = NULL;
    allocateSpace1(&p);
    
    printf("%d\n", p->age);
}





//类型 &别名 = 原名
//Person* &p = p; 类型是Person*
void allocateSpace2(Person* &p) {
    p = (Person *)malloc(sizeof(struct Person));
    p->age = 20;
}

void func2(void) {
    Person *p = NULL;
    allocateSpace2(p);
    
    printf("%d\n", p->age);
}





int main() {
    func1();
    func2();
    
    return EXIT_SUCCESS;
}

