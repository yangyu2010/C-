//
//  GameCompany.c
//  AdvancedCProgram
//
//  Created by Yu Yang on 10/18/23.
//

#include "GameCompany.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Player {
    char name[64];
    int level;
    int exp;
};


int getExp(int winRate, int level) {
    int random = rand() % 100 + 1;
    if (random <= winRate) {
        return level * 10;
    }
    return 0;
}



/// 初始化游戏
/// player: 玩家指针
/// name: 玩家姓名
void INIT_GAME_COMPANY(void **player, char *name) {
    struct Player *p = malloc(sizeof(struct Player));
    strcpy(p->name, name);
    p->level = 0;
    p->exp = 0;
    
    *player = p;
}

/// 副本战斗 返回是否战斗胜利 1胜利 0失败
/// player: 玩家指针
/// level: 副本的等级难度
int FIGHT_GAME_COMPANY(void *player, int level) {
    struct Player *p = player;
    
    int addExp = 0;
    switch (level) {
        case 1:
            addExp = getExp(80, 1);
            break;
        case 2:
            addExp = getExp(60, 2);
            break;
        case 3:
            addExp = getExp(40, 3);
            break;
        default:
            break;
    }
    p->exp += addExp;
    p->level = p->exp / 10;
    
    if (addExp == 0) {
        return 0;
    } else {
        return 1;
    }
}

/// 查看玩家信息
void PRINT_GAME_COMPANY(void *player) {
    struct Player *p = player;
    printf("玩家的姓名: %s\n", p->name);
    printf("玩家的等级: %d\n", p->level);
    printf("玩家的经验: %d\n", p->exp);

}

/// 退出游戏
void EXIT_GAME_COMPANY(void *player) {
    free(player);
    player = NULL;
}
