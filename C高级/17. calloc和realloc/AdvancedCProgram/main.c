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
    // malloc初始化的内存空间 不会被设置0
//    int *p = malloc(sizeof(int) * 10);
    
    // 第3个参数是长度, 必须是完整的
//    memset(p, 0, sizeof(int) * 10);
//    memset(p, 0, 10);
    
    // calloc初始化的内存空间 会被设置0
    int *p = calloc(10, sizeof(int));
    
    for (int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }
}


// realloc重新申请内存, 新地址可能会变, 可能不会
// 新空间的数据不会被初始化为0
void func2(void) {
    int *p = calloc(10, sizeof(int));
    for (int i = 0; i < 10; i++) {
        p[i] = i+100;
    }
    printf("\n%p\n\n", p);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", p[i]);
    }
    
    p = realloc(p, 11 * sizeof(int));
    printf("\n%p\n\n", p);
    for (int i = 0; i < 11; i++) {
        printf("%d\n", p[i]);
    }
    
    p = realloc(p, 20 * sizeof(int));
    printf("\n%p\n\n", p);
    for (int i = 0; i < 20; i++) {
        printf("%d\n", p[i]);
    }
    
    p = realloc(p, 5 * sizeof(int));
    printf("\n%p\n\n", p);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", p[i]);
    }
}

int main() {
    func2();
    
    return EXIT_SUCCESS;
}


