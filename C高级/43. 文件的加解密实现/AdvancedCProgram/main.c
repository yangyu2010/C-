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
#include <time.h>

void func1(void) {
    char *sourcePath = "/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/43. 文件的加解密实现/config.txt";
    char *destinationPath = "/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/43. 文件的加解密实现/加密文件.txt";
    FILE *sourceFile = fopen(sourcePath, "r");
    FILE *destinationFile = fopen(destinationPath, "w");
    if (sourceFile == NULL || destinationFile == NULL) {
        perror("open file error");
        return;
    }
    
    char ch = '\0';
    while ((ch = fgetc(sourceFile)) != EOF) {
        // # 代表35
        // 先转为short
        
        // 第一步 左移4 数字全是偶数了
        // 0000 0000 0010 0011
        // 0000 0010 0011 0000
        
        // 第二步 把数字改为负数 和1000 0000 0000 0000做或运算
        // 首位是符号位
        // 1000 0010 0011 0000
        
        // 第三部 给后四位 添加一些随机数
        // 其实后四位 是无效的 到时解密时 直接去除
        // 1000 0010 0011 1010
        
        short temp = (short)ch;
        temp = temp << 4;
        temp = temp | 0x8000;
        temp = temp + rand() % 16;

        fprintf(destinationFile, "%hd", temp);
        //printf("%d\n", temp);
    }
    
    fclose(sourceFile);
    fclose(destinationFile);

}

/*
 fprintf函数：用于将数据输出到指定的文件中。它的功能和printf函数类似，只不过printf函数向标准输出设备（一般是显示器）输出数据，而fprintf函数则向指定的文件输出数据。
 fscanf函数：用于从指定的文件读取数据。它的功能和scanf函数类似，但是scanf函数从标准输入设备（一般是键盘）获取数据，而fscanf函数则从指定的文件获取数据。
 
 feof()函数用于检测流sourceFile是否结束。如果文件结束，返回非零值；否则返回0。通常用在读取文件时，通过判断是否到达文件末尾，决定是否继续读取数据。
 */

void func2(void) {
    char *sourcePath = "/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/43. 文件的加解密实现/加密文件.txt";
    char *destinationPath = "/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/43. 文件的加解密实现/解密文件.txt";
    FILE *sourceFile = fopen(sourcePath, "r");
    FILE *destinationFile = fopen(destinationPath, "w");
    if (sourceFile == NULL || destinationFile == NULL) {
        perror("open file error");
        return;
    }
    
    short temp = 0;
    while (!feof(sourceFile)) {
        fscanf(sourceFile, "%hd", &temp);
        
        temp = temp << 1;
        temp = temp >> 5;
        
        fputc(temp, destinationFile);
    }
    
    fclose(sourceFile);
    fclose(destinationFile);
}

int main() {
    /*
     添加随机数种子
     
     这段代码是在设置随机数种子，用于生成随机数。
     srand() 是一个初始化随机数生成器的函数，它需要一个起始值，也叫做种子。如果使用同样的种子去初始化，那么之后生成的随机数序列将完全相同。为了每次运行程序都能得到不同的随机数序列，一般会用系统时间作为种子，因为系统时间是持续变化的。
     (unsigned int)time(NULL) 是获取当前系统时间，并把这个时间转换成无符号整型。time(NULL) 会返回从1970年1月1日至今的秒数。
     总的来说，这段代码就是把当前时间（秒数）作为种子，去初始化随机数生成器，以便生成不同的随机数序列。
     */
    srand((unsigned int)time(NULL));
    
    func1();
    func2();
    
    return EXIT_SUCCESS;
}

