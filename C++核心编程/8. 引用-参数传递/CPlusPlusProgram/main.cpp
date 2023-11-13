//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;


void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    
    printf("swap a = %d b = %d\n", a, b);
}

void func1(void) {
    int a = 10;
    int b = 20;
    swap(a, b);
    
    printf("func1 a = %d b = %d\n", a, b);
}






void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    
    printf("swap2 a = %d b = %d\n", *a, *b);
}

void func2(void) {
    int a = 10;
    int b = 20;
    
    printf("func2 before a = %d b = %d\n", a, b);
    swap2(&a, &b);
    printf("func2 after a = %d b = %d\n", a, b);
}







void swap3(int &a, int &b) {    // int &a = a; int &b = b;
    int temp = a;
    a = b;
    b = temp;
    
    printf("swap2 a = %d b = %d\n", a, b);
}

void func3(void) {
    int a = 10;
    int b = 20;
    
    printf("func3 before a = %d b = %d\n", a, b);
    swap3(a, b);
    printf("func3 after a = %d b = %d\n", a, b);
}



int main() {
    //func1();
    //func2();
    func3();
    
    
    return EXIT_SUCCESS;
}
