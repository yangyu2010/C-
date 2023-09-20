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
 // 按照字符读写文件：fgetc(), fputc()
 
 void func1(void) {
     FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/40. 文件读写/test1.txt", "w");
     if (file == NULL) {
         printf("open file error");
         return;
     }
     char string[] = "hello world";
     for (int i = 0; i < strlen(string); i++) {
         fputc(string[i], file);
     }
     fclose(file);
 }


 void func2(void) {
     FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/40. 文件读写/test1.txt", "r");
     if (file == NULL) {
         printf("open file error");
         return;
     }
     
     char buf = 0;
     while ((buf = fgetc(file)) != EOF) {
         printf("%c\n", buf);
     }
     printf("\n");
     fclose(file);
 }
 */






/*
// 按照行读写文件：fputs(), fgets()

void func1(void) {
    FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/40. 文件读写/test2.txt", "w");
    if (file == NULL) {
        printf("open file error");
        return;
    }
    char *string[] = {
        "锄禾日当午\n",
        "汗滴禾下土\n",
        "谁知盘中餐\n",
        "粒粒皆辛苦\n"
    };
    
    for (int i = 0; i < 4; i++) {
        fputs(string[i], file);
    }
    fclose(file);
}


void func2(void) {
    FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/40. 文件读写/test2.txt", "r");
    if (file == NULL) {
        printf("open file error");
        return;
    }
    
    while (!feof(file)) {
        char buf[1024] = { 0 };
        fgets(buf, 1024, file);
        printf("%s", buf);
    }
    
    fclose(file);
}
 */







/*

// 按照块读写文件：fread(), fwirte()

struct Hero {
    char name[64];
    int age;
};

void func1(void) {
    FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/40. 文件读写/test3.txt", "wb");
    if (file == NULL) {
        printf("open file error\n");
        return;
    }
    
    struct Hero heroes[4] = {
        {"亚瑟", 28},
        {"赵云", 38},
        {"妲己", 18},
        {"孙悟空", 999},
    };

    // 一次性写入
    fwrite(&heroes, sizeof(struct Hero), 4, file);
    
  
     // 分开写入
    //for (int i = 0; i < 4; i++) {
//        printf("%p\n", &heroes);
//        printf("%p\n", &heroes[i]);
//        printf("%p\n", (&heroes)[i]);
//        printf("%p\n", &(heroes[i]));
//        printf("\n\n");
        //fwrite(&(heroes[i]), sizeof(struct Hero), 1, file);
   // }
     
    
    fclose(file);
}


void func2(void) {
    FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/40. 文件读写/test3.txt", "rb");
    if (file == NULL) {
        printf("open file error\n");
        return;
    }
    struct Hero heroes[4];
    
    fread(&heroes, sizeof(struct Hero), 4, file);
    
    for (int i = 0; i < 4; i++) {
        printf("姓名:%s 年龄:%d\n", heroes[i].name, heroes[i].age);
    }
    
    fclose(file);
}
 */





/*

// 按照格式化读写文件：fprintf(), fscanf()

void func1(void) {
    FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/40. 文件读写/test4.txt", "w");
    if (file == NULL) {
        perror("open file error");
        return;
    }
    
    fprintf(file, "Hello world, %d年%02d月%02d日", 2018, 07, 05);
    
    fclose(file);
}


void func2(void) {
    FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/40. 文件读写/test4.txt", "r");
    if (file == NULL) {
        perror("open file error\n");
        return;
    }
    
    char buf[1024] = { 0 };
    while (!feof(file)) {
        perror("open file error");
        printf("%s\n", buf);
    }
    
    fclose(file);
}
 */






// 按照随机位置读写文件：fseek(), ftell(), rewind()


struct Hero {
    char name[64];
    int age;
};

void func1(void) {
    FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/40. 文件读写/test5.txt", "wb");
    if (file == NULL) {
        perror("open file error");
        return;
    }
    
    struct Hero heroes[4] = {
        {"亚瑟", 28},
        {"赵云", 38},
        {"妲己", 18},
        {"孙悟空", 999},
    };

    // 一次性写入
    fwrite(&heroes, sizeof(struct Hero), 4, file);
    
    fclose(file);
}


void func2(void) {
    FILE *file = fopen("/Users/yangyu/iOS/传智播客C++32期-学习笔记/C高级/40. 文件读写/test5.txt", "r");
    if (file == NULL) {
        perror("open file error");
        return;
    }
    printf("%ld\n", ftell(file));
    //fseek(file, sizeof(struct Hero) * 2, SEEK_SET);
    fseek(file, -(long)sizeof(struct Hero) * 2, SEEK_END);
    printf("%ld\n", ftell(file));
    
    struct Hero hero;
    fread(&hero, sizeof(struct Hero), 1, file);
    printf("姓名:%s 年龄:%d\n", hero.name, hero.age);

    printf("%ld\n", ftell(file));
    rewind(file);
    printf("%ld\n", ftell(file));

    fread(&hero, sizeof(struct Hero), 1, file);
    printf("姓名:%s 年龄:%d\n", hero.name, hero.age);

    fclose(file);
}



int main() {
    func1();
    func2();
    
    return EXIT_SUCCESS;
}

