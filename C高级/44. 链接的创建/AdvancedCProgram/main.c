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


struct LinkNode {
    int num;
    struct LinkNode *next;
};


void func1(void) {
    struct LinkNode node1 = { 1, NULL };
    struct LinkNode node2 = { 2, NULL };
    struct LinkNode node3 = { 3, NULL };
    struct LinkNode node4 = { 4, NULL };
    struct LinkNode node5 = { 5, NULL };

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    struct LinkNode *currentNode = &node1;
    while (currentNode != NULL) {
        printf("%d ", currentNode->num);
        currentNode = currentNode->next;
    }
    
    printf("\n");
}


void func2(void) {
    struct LinkNode *node1 = malloc(sizeof(struct LinkNode));
    struct LinkNode *node2 = malloc(sizeof(struct LinkNode));
    struct LinkNode *node3 = malloc(sizeof(struct LinkNode));
    struct LinkNode *node4 = malloc(sizeof(struct LinkNode));
    struct LinkNode *node5 = malloc(sizeof(struct LinkNode));

    node1->num = 10;
    node1->next = node2;
    
    node2->num = 20;
    node2->next = node3;
    
    node3->num = 30;
    node3->next = node4;

    node4->num = 40;
    node4->next = node5;
    
    node5->num = 50;

    struct LinkNode *currentNode = node1;
    while (currentNode != NULL) {
        printf("%d ", currentNode->num);
        currentNode = currentNode->next;
    }
    
    printf("\n");

    
    free(node1);
    node1 = NULL;
    free(node2);
    node2 = NULL;
    free(node3);
    node3 = NULL;
    free(node4);
    node4 = NULL;
    free(node5);
    node5 = NULL;

}

int main() {

    func1();
    func2();

    return EXIT_SUCCESS;
}

