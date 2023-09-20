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



 // 注意事项1
 
 void func1(void) {
     FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/41. 文件读写注意点/test1.txt", "w");
     if (file == NULL) {
         perror("open file error");
         return;
     }
     char string[] = "hello world";
     for (int i = 0; i < strlen(string); i++) {
         fputc(string[i], file);
     }
     fclose(file);
 }


 void func2(void) {
     FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/41. 文件读写注意点/test1.txt", "r");
     if (file == NULL) {
         perror("open file error");
         return;
     }
     
     char buf = 0;
//     while ((buf = fgetc(file)) != EOF) {
//         printf("%c", buf);
//     }
     
     // hello worldEOF
     // hello world\377Program ended with exit code: 0
     // 文件指针指向EOF的时候, 还没有到结尾, 会再次进入到while循环中
     // 所以按字符读取时, 推荐使用上面的方法, 每次读取就和EOF做比较
     while (!feof(file)) {
         buf = fgetc(file);
         
         printf("%c", buf);
     }
     
     fclose(file);
 }



// 注意事项2
struct Hero {
    char *name;
    int age;
};
// 如果属性开辟到堆区, 不要存储指针地址到文件中, 要将指针指向的地址的内容存储到文件中.

int main() {
    func1();
    func2();
    
    return EXIT_SUCCESS;
}

