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

int main() {
//    int buf[1024] = { 0 };
    
    // 1.格式化字符串
    char buf[1024];
    sprintf(buf, "今天是%d年%d月%d日", 2018, 6, 30);
    printf("%s\n", buf);
    
    // 2.拼接字符串
    memset(buf, 0, 1024);
    char str1[] = "hello";
    char str2[] = "world";
    // 返回字符串的长度 不包括\0
    int len = sprintf(buf,"%s %s",str1,str2);
    printf("buf:%s len:%d\n", buf,len);

    
    int num = 100;
    //设置宽度 右对齐
    memset(buf, 0, 1024);
    sprintf(buf, "%8d", num);
    printf("buf:%s\n", buf);
    //设置宽度 左对齐
    memset(buf, 0, 1024);
    sprintf(buf, "%-8d", num);
    printf("buf:%s\n", buf);
    //转成16进制字符串 小写
    memset(buf, 0, 1024);
    sprintf(buf, "0x%x", num);
    printf("buf:%s\n", buf);

    //转成8进制字符串
    memset(buf, 0, 1024);
    sprintf(buf, "0o%o", num);
    printf("buf:%s\n", buf);

    return EXIT_SUCCESS;
}


