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


int *getSpace(void) {
    int *p = malloc(sizeof(int) * 5);
    if (p == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < 5; i++) {
        p[i] = 100 + i;
    }

    return p;
}

void func1(void) {
    
    int *p = getSpace();
    for (int i = 0; i < 5; i++) {
        printf("%d\n", p[i]);
    }
    
    // 手动创建 手动释放
    free(p);
    p = NULL;
    
}

int main() {

    return EXIT_SUCCESS;
}
