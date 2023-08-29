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



// Address of stack memory associated with local variable 'a' returned
int *myFunc(void) {
    int a = 10;
    return &a;
    
    // a变量会在函数结束后被销毁, 因为在栈区, 所以返回的地址已经被收回了.
}

void func1(void) {
    int *p = myFunc();
    printf("*p = %d\n", *p);
    printf("*p = %d\n", *p);
    printf("*p = %d\n", *p);
}


char* getString(void) {
    char string[] = "hello world";
    return string;
}

void func2(void) {
    char *p = NULL;
    p = getString();
    printf("p = %s\n", p);
}

int main() {

//    func1();
    
    func2();
    
    return EXIT_SUCCESS;
}


/*
 
 栈区
 0x0000 [   ]
 0x0003 [   ]
 0x0004 [   ]
 [   ]
 */
