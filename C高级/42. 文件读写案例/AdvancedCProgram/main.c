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

/*
strlen()函数求出的字符串长度为有效长度，既不包含字符串末尾结束符 ‘\0’；
sizeof()操作符求出的长度包含字符串末尾的结束符 ‘\0’；
 */

void func1(void) {
    char *path = "/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/42. 文件读写案例/config.txt";
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("open file error");
        return;
    }
    
    char buf[1024] = { 0 };
    while (fgets(buf, 1024, file) != NULL) {
        // 判断字符串中是否包含某个字符
        char *ret = strchr(buf, ':');
        if (ret != NULL) {
            char key[64]  = { 0 };
            char value[64]  = { 0 };
            strncpy(key, buf, ret - buf);
            // heroInfo:前排坦克ROSE
            /*
             ret 返回的是 ':前排坦克ROSE'
             ret - buf 的结果是计算':'前面的长度
             ret + 1就是跳过了':'  从‘前’字开始计算
             注意: 每一行结尾有个 \n 换行符 所以计算的长度需要减1
             */
            strncpy(value, ret + 1, strlen(ret + 1) - 1);
            printf("key: %s ", key);
            printf("value: %s", value);

            printf("\n");
        }
    }
    
    fclose(file);
}


int main() {
    func1();
    
    return EXIT_SUCCESS;
}

