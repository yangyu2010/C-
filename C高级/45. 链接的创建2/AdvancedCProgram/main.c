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

#include "LinkList.h"


void func1(void) {
    struct LinkNode *header = initLinkList();
    foreachList(header);
    
    // 10 20 30
    // 10000 1000 10 200 5 20 30 40 50
    insert(header, 20, 200);
    insert(header, 20, 5);
    insert(header, 100, 40);
    insert(header, 10, 1000);
    insert(header, 1000, 10000);
    insert(header, 2, 50);

    foreachList(header);

    
    delete(header, 444);
    delete(header, 10000);
    delete(header, 444);
    delete(header, 50);
    delete(header, 333);
    delete(header, 444);
    delete(header, 200);
    delete(header, 10);
    delete(header, 333);
    delete(header, 10);
    delete(header, 10);
 
    // 1000 5 20 30 40
    foreachList(header);

    // 清空
    clearList(header);
    foreachList(header);

    // 清空后再次插入
    // 50 30 20 10 40
    insert(header, 100, 10);
    insert(header, 10, 20);
    insert(header, 20, 30);
    insert(header, 1000, 40);
    insert(header, 30, 50);
    foreachList(header);


    destroyList(header);
    header = NULL;
}


void func2(void) {
    struct LinkNode *header = initLinkList();
    foreachList(header);
    
    // 10 20 30
    // 10000 1000 10 200 5 20 30 40 50
    insert(header, 20, 200);
    insert(header, 20, 5);
    insert(header, 100, 40);
    insert(header, 10, 1000);
    insert(header, 1000, 10000);
    insert(header, 2, 50);

    foreachList(header);

    // 1 2 10000 1000 10 4 200 5 20 30 40 50 3
    insertByPosition(header, 0, 1);
    insertByPosition(header, 1, 2);
    insertByPosition(header, 5, 4);
    insertByPosition(header, 10000, 3);

    foreachList(header);

    // 10000 1000 10 4 200 30 40 50 3
    deleteByPosition(header, 1000);
    deleteByPosition(header, 0);
    deleteByPosition(header, 0);
    deleteByPosition(header, 5);
    deleteByPosition(header, 5);
    deleteByPosition(header, 50);
    foreachList(header);

    // 反转
    // 10000 1000 10 4 200 30 40 50 3 反转之前的顺序
    // 3 50 40 30 200 4 10 1000 10000
    reverse(header);
    foreachList(header);
    
    
    // 反转之后再测试插入和删除
    // 70 3 60 20 50 40 30 200 4 10 1000 10000 80
    insert(header, 100, 80);
    insert(header, 50, 20);
    insert(header, 20, 60);
    insert(header, 3, 70);

    foreachList(header);

    // 3 60 20 50 40 30 200 4 10 1000
    delete(header, 100);
    delete(header, 70);
    delete(header, 70);
    delete(header, 100);
    delete(header, 80);
    delete(header, 10000);

    foreachList(header);

}

int main() {

    //func1();
    func2();

    return EXIT_SUCCESS;
}

