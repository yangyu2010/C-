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
    int num1 = 5;
    int num2 = 9;
    
    // 12
    int result = num1 ^ num2;
    /*
     0101
     1001
^    ------
     1100
     */
    
    
    printf("%d\n", result);             // 5 ^ 9 = 12
    printf("%d\n", result ^ num1);      // 12 ^ 9 = 5
    printf("%d\n", result ^ num2);      // 12 ^ 5 = 9
}


// 实现两个数的交换
void func2(void) {
    int num1 = 5;
    int num2 = 9;
    
    num1 = num1 ^ num2;     //12=5^9
    num2 = num1 ^ num2;     //5=12^9
    num1 = num1 ^ num2;     //9=12^5

    printf("%d\n", num1);
    printf("%d\n", num2);
}



// 实现两个数的交换
void func3(void) {
    int num1 = 5;
    int num2 = 9;

    num1 = num1 + num2;     //14=9+5
    num2 = num1 - num2;     //9=14-5
    num1 = num1 - num2;     //5=14-9
    
    printf("%d\n", num1);
    printf("%d\n", num2);
}


int main() {
//    func1();
    func2();
//    func3();
    
    return EXIT_SUCCESS;
}


