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

int main() {

    func1();


    return EXIT_SUCCESS;
}

