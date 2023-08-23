//
//  TestCPP.cpp
//  AdvancedCProgram
//
//  Created by Yu Yang on 8/23/23.
//

#define _CRI_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main1() {
    char* p1, p2;
    char *p3;
    char p4;
    printf("p1的数据类型是: %s\n", typeid(p1).name());
    printf("p2的数据类型是: %s\n", typeid(p2).name());
    printf("p3的数据类型是: %s\n", typeid(p3).name());
    printf("p4的数据类型是: %s\n", typeid(p4).name());

    typedef char * PChar;
    PChar p5, p6;
    printf("p5的数据类型是: %s\n", typeid(p5).name());
    printf("p6的数据类型是: %s\n", typeid(p6).name());

    
    int i1;
    int *i2;
    printf("i1的数据类型是: %s\n", typeid(i1).name());
    printf("i2的数据类型是: %s\n", typeid(i2).name());

    

    
    return EXIT_SUCCESS;
}

/*
 p1的数据类型是: Pc
 p2的数据类型是: c
 p3的数据类型是: Pc
 p4的数据类型是: c
 p5的数据类型是: Pc
 p6的数据类型是: Pc
 i1的数据类型是: i
 i2的数据类型是: Pi
 */
