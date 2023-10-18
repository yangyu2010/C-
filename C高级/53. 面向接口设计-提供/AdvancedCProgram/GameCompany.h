//
//  GameCompany.h
//  AdvancedCProgram
//
//  Created by Yu Yang on 10/18/23.
//

#ifndef GameCompany_h
#define GameCompany_h

#include <stdio.h>


/// 初始化游戏
/// player: 玩家指针
/// name: 玩家姓名
void INIT_GAME_COMPANY(void **player, char *name);

/// 副本战斗 返回是否战斗胜利 1胜利 0失败
/// player: 玩家指针
/// level: 副本的等级难度
int FIGHT_GAME_COMPANY(void *player, int level);

/// 查看玩家信息
void PRINT_GAME_COMPANY(void *player);

/// 退出游戏
void EXIT_GAME_COMPANY(void *player);






#endif /* GameCompany_h */
