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


// 1.不能向NULL或者非法内存 拷贝数据
void func1(void) {
    char *p = NULL;
    strcpy(p, "hello world");
    
    char *q = 0x1122;
    strcpy(q, "hello word");
}


// 2.野指针出现的情况
void func2(void) {
    // 指针变量未初始化
//    int *p;
//    printf("%d\n", *p);
    
    // 指针释放后未置空
    char *str = malloc(100);
    free(str);
    str = NULL;
    
    // 空指针可以重复释放, 野指针不可以重复释放
    // 如果str没有等于NULL, 再次free, 不行
//    free(str);
}

// 3.指针操作超出了变量的作用域
int *func3(void) {
    int a = 10;
    int *p = &a;
    return p;
}

int main() {
    
//    func1();
    
    func2();
    
    return EXIT_SUCCESS;
}

