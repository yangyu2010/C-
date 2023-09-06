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
    char *p = malloc(sizeof(char) * 64);
    for (int i = 0; i < 10; i++) {
        *p = i + 97;
        printf("%c\n", *p);
        p++;    //更改指针位置, 释放出错.
    }
    
    if (p != NULL) {
        free(p);
        p = NULL;
    }
}

void func2(void) {
    char *p = malloc(sizeof(char) * 64);
    // 用临时指针操作内存, 防止出错
    char *temp = p;
    
    for (int i = 0; i < 10; i++) {
        *temp = i + 97;
        printf("%c\n", *temp);
        temp++;    //更改指针位置, 释放出错.
    }
    
    if (p != NULL) {
        free(p);
        p = NULL;
    }
}

int main() {
    func2();
    
    return EXIT_SUCCESS;
}

