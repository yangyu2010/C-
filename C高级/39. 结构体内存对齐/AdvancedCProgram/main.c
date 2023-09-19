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


#pragma pack(show)



/**
 

struct Student {
    int age;
    char name;
};


void func1(void) {
    struct Student student = { 18, 'A' };
    
    /*
     3.3    自定义数据类型 对齐规则
     3.3.1    第一个属性开始  从0开始偏移
     3.3.2    第二个属性开始  要放在 该类型的大小  与  对齐模数比  取小的值  的整数倍
     3.3.3    所有属性都计算完后，再整体做二次偏移，将整体计算的结果 要放在  结构体最大类型 与对齐模数比  取小的值的 整数倍上
     *

    printf("%lu\n", sizeof(struct Student));
    printf("%lu\n", sizeof(student));
}

*/


// 3.4    结构体嵌套结构体
// 3.4.1    结构体嵌套结构体时候，子结构体放在该结构体中最大类型 和对齐模数比 取小的值 的整数倍上即可


typedef struct _STUDENT{
    int a;          //0~3
    char b;         //4~7
    double c;       //8~15
    float d;        //16~19
}Student;
// 只占了20个字节, 但是因为要放在最大类型与对齐模数比  取小的值的整数倍上
// 这里是8的整数倍 就是24


typedef struct _STUDENT2{
    char a;         //0
    Student b;      //7~30
    //int c;
    double c;       //31~39
}Student2;

// 占用了40个字节, 因为40是8的整数倍, 8是该结构体内的最大类型, 即使是内部嵌套的结构体.
// 可以把double c 换成 int c 结果还是40, 说明是以内部嵌套的结构体内部的doule c来计算




void func1(void) {
    printf("%lu\n", sizeof(Student));
    printf("%lu\n", sizeof(Student2));
}

int main() {
    func1();
    
    return EXIT_SUCCESS;
}

