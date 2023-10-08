//
//  LinkList.c
//  AdvancedCProgram
//
//  Created by Yu Yang on 10/8/23.
//

#include "LinkList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct LinkNode *initLinkList(void) {
    struct LinkNode *header = malloc(sizeof(struct LinkNode));
    if (header == NULL) {
        return NULL;
    }
    
    struct LinkNode *footer = header;
    
    int val = -1;
    while (1) {
        printf("请初始化链表, 输入数字代表插入, 输入-1代表退出.\n");
        scanf("%d", &val);
        
        if (val == -1) {
            break;
        }
        
        struct LinkNode *node = malloc(sizeof(struct LinkNode));
        node->num = val;
        node->next = NULL;
        
        footer->next = node;
        footer = node;
    }
    
    return header;
}

void foreachList(struct LinkNode *header) {
    if (header == NULL) {
        return;
    }
    
    struct LinkNode *node = header->next;
    while (node != NULL) {
        printf("%d ", node->num);
        node = node->next;
    }
    
    printf("\n");
}


void insert(struct LinkNode *header, int oldValue, int newValue) {
    if (header == NULL) {
        return;
    }

    struct LinkNode *currentNode = header->next;
    struct LinkNode *prevNode = header;

    while (currentNode != NULL) {
        if (currentNode->num == oldValue) {
            break;
        }
        
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    
    struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
    newNode->num = newValue;
    newNode->next = NULL;
    
    prevNode->next = newNode;
    newNode->next = currentNode;
}
