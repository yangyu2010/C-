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


void func1(void) {
    printf("hello world\n");
}

void func2(int num) {
    printf("%d\n", num);
}

void func3(void) {
    printf("hello world 3\n");
}

void test1(void) {
    void (*p)(void) = func1;
    p();

    void (*p2)(int) = func2;
    p2(100);
}

void test2(void) {
    typedef void(FUNC_TYPE)(void);
    FUNC_TYPE *p1 = func1;
    p1();

    typedef void(* FUNC_P)(void);
    FUNC_P p2 = func1;
    p2();
    
    //Incompatible pointer types initializing 'int *' with an expression of type 'void (void)'
    //int *p = func1;
    
    void (*p)(void) = func1;
    p();
}

void test3(void) {
    void (*p [3])(void) = { func1, func1, func3 };
    p[0]();
    p[1]();
    p[2]();
}

int main() {
    
    test3();
    
    return EXIT_SUCCESS;
}

