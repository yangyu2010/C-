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

#include "GameCompany.h"

/// 初始化游戏
/// player: 玩家指针
/// name: 玩家姓名
typedef void(*INIT_GAME) (void **player, char *name);

/// 副本战斗 返回是否战斗胜利 1胜利 0失败
/// player: 玩家指针
/// level: 副本的等级难度
typedef int (*FIGHT_GAME)(void *player, int level);

/// 查看玩家信息
typedef void(*PRINT_GAME)(void *player);

/// 退出游戏
typedef void(*EXIT_GAME)(void *player);




void play(INIT_GAME init, FIGHT_GAME fight, PRINT_GAME print, EXIT_GAME exit) {
    
    void *player = NULL;
    printf("请输入姓名:\n");
    char name[64] = {'\0'};
    scanf("%s", name);
    
    init(&player, name);
    
    while (1) {
        
        int level = 0;
        printf("请选择游戏的难度:\n");
        printf("1. 简单:\n");
        printf("2. 中等:\n");
        printf("3. 困难:\n");

        scanf("%d", &level);
        
        int result = fight(player, level);
        if (result == 0) {
            printf("游戏失败\n");
            print(player);
            exit(player);
            break;
        } else {
            printf("游戏胜利\n");
            print(player);
        }
        
    }
    
}


int main() {

    play(INIT_GAME_COMPANY, FIGHT_GAME_COMPANY, PRINT_GAME_COMPANY, EXIT_GAME_COMPANY);
    
    return EXIT_SUCCESS;
}


/**
 
 c语言中
 typedef void(*INIT_GAME) (void **player, char *name);
 typedef void(INIT_GAME) (void **player, char *name);
 分别是什么意思, 有什么区别?

 
 
 这两个声明所定义的类型和变量是不同的。

 1. `typedef void(*INIT_GAME) (void **player, char *name);`
 这行代码定义了一个新的类型名 INIT_GAME。INIT_GAME 是一个函数指针类型，指向的函数接受两个参数（一个是`void **`类型，另一个是`char *`类型）并且返回`void`。

 例如，你可以使用它来定义一个函数指针变量：
 ```
 INIT_GAME game_initializer;
 ```

 2. `typedef void(INIT_GAME) (void **player, char *name);`
 这行代码定义的是一个函数类型而不是函数指针类型。INIT_GAME 是一个函数类型，这个函数接受两个参数（一个是`void **`类型，另一个是`char *`类型）并且返回`void`。

 由于C语言没有直接支持函数类型的变量，因此这种形式的定义在实际中使用较少。但是，你可以使用指向该类型的指针：
 ```
 INIT_GAME *game_initializer_ptr;
 ```

 总结起来说，区别在于第一种是定义了一个函数指针类型，而第二种是定义了一个函数类型。
 */
