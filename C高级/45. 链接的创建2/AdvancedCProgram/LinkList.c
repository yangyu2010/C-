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


void delete(struct LinkNode *header, int value) {
    if (header == NULL) {
        return;
    }

    struct LinkNode *currentNode = header->next;
    struct LinkNode *prevNode = header;

    while (currentNode != NULL) {
        if (currentNode->num == value) {
            break;
        }
        
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    
    if (currentNode == NULL) {
        return;
    }
    
    prevNode->next = currentNode->next;
    
    free(currentNode);
    currentNode = NULL;
}


void clearList(struct LinkNode *header) {
    if (header == NULL) {
        return;
    }
    
    struct LinkNode *currentNode = header->next;
    // 清空头的next
    header->next = NULL;
    
    while (currentNode != NULL) {
        struct LinkNode *nextNode = currentNode->next;
        
        currentNode->num = 0;
        currentNode->next = NULL;
        free(currentNode);
        
        currentNode = nextNode;
    }
    
    // 0 10 20 30
}


void destroyList(struct LinkNode *header) {
    if (header == NULL) {
        return;
    }
    clearList(header);
    
    header->num = 0;
    header->next = NULL;
    free(header);
    header = NULL;
}


void insertByPosition(struct LinkNode *header, int position, int value) {
    if (header == NULL) {
        return;
    }

    if (position < 0) {
        return;
    }
    
    struct LinkNode *currentNode = header->next;
    struct LinkNode *prevNode = header;
    int count = 0;
    while (count != position && currentNode != NULL) {
        prevNode = currentNode;
        currentNode = currentNode->next;
        count += 1;
    }
    
    struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
    newNode->num = value;
    newNode->next = NULL;
    
    prevNode->next = newNode;
    newNode->next = currentNode;
}


void deleteByPosition(struct LinkNode *header, int position) {
    if (header == NULL) {
        return;
    }

    if (position < 0) {
        return;
    }
    
    struct LinkNode *currentNode = header->next;
    struct LinkNode *prevNode = header;
    int count = 0;
    while (count != position && currentNode != NULL) {
        prevNode = currentNode;
        currentNode = currentNode->next;
        count += 1;
    }
    
    // 没有找到当前index
    if (currentNode == NULL) {
        return;
    }
    
    prevNode->next = currentNode->next;
    free(currentNode);
    currentNode = NULL;
}


void reverse(struct LinkNode *header) {
    if (header == NULL) {
        return;
    }
    struct LinkNode *currentNode = header->next;
    struct LinkNode *prevNode = header;

    while (currentNode != NULL) {
        struct LinkNode *nextNode = currentNode->next;
        currentNode->next = prevNode;
        
        prevNode = currentNode;
        currentNode = nextNode;
    }
    
    // 变化之前的第一个节点, 它现在变成最后一个了, 所以next要指向null
    struct LinkNode *firstNode = header->next;
    firstNode->next = NULL;
    
    // 现在最新的第一个
    // currentNode已经没有数据了 所以prevNode是最后一个节点
    // 要把header的next指向这个最新的一个
    header->next = prevNode;
}
