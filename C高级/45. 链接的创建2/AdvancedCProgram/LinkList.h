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
void delete(struct LinkNode *header, int value);
void clearList(struct LinkNode *header);
void destroyList(struct LinkNode *header);


void insertByPosition(struct LinkNode *header, int position, int value);
void deleteByPosition(struct LinkNode *header, int position);
void reverse(struct LinkNode *header);
