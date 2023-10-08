//
//  LinkList.h
//  AdvancedCProgram
//
//  Created by Yu Yang on 10/8/23.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>

#endif /* LinkList_h */



struct LinkNode {
    int num;
    struct LinkNode *next;
};



struct LinkNode *initLinkList(void);
void foreachList(struct LinkNode *);
void insert(struct LinkNode *, int, int);
