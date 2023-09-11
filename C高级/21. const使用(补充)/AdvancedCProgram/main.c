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


// const修饰的是右边的内容
void func1(void) {
    int age = 10;
    int height = 20;
    const int *p1 = &age;
    int const * p2 = &age;
    int * const p3 = &age;
    const int * const p4 = &age;
    int const * const p5 = &age;
    

    // const修饰的是*p1, 所以*p1不能改, p1可以改
    //*p1 = 20;
    //p1 = &height;
    
    // const修饰的是*p2, 所以*p2不能改, p2可以改 和p1一样
    //*p2 = 20;
    //p2 = &height;

    // const修饰的是p3, 所以*p3可以改, p3不可以改
    //*p3 = 20;
    //p3 = &height;

    // const修饰的是p4和*p4, 所以*p4不可以改, p4不可以改
    //*p4 = 20;
    //p4 = &height;

    // const修饰的是p5和*p5, 所以*p5不可以改, p5不可以改 和p4一样
    //*p5 = 20;
    //p5= &height;

}

int main() {
    func1();
    
    return EXIT_SUCCESS;
}

