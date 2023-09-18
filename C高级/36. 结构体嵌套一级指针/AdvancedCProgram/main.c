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


struct Person {
    char *name;
    int age;
};


struct Person **allocateSpace(int length) {
    struct Person **pArray = malloc(sizeof(struct Person *) * length);

    for (int i = 0; i < length; i++) {
        pArray[i] = malloc(sizeof(struct Person));

        pArray[i]->name = malloc(sizeof(char) * 64);
        sprintf(pArray[i]->name, "name_%d", i + 1);
        
        pArray[i]->age = 18 + i;
    }
    
    return pArray;
}


void printArray(struct Person **pArray, int length) {
    for (int i = 0; i < length; i++) {
        printf("%s %d\n", pArray[i]->name, pArray[i]->age);
    }
}

void freeArray(struct Person **pArray, int length) {
    for (int i = 0; i < length; i++) {
        if (pArray[i]->name != NULL) {
            free(pArray[i]->name);
            pArray[i]->name = NULL;
        }
        
        if (pArray[i] != NULL) {
            free(pArray[i]);
            pArray[i] = NULL;
        }
    }
    
    if (pArray != NULL) {
        free(pArray);
        pArray = NULL;
    }
}

void func1(void) {
    struct Person **pArray = NULL;
    int length = 10;
    pArray = allocateSpace(length);
    printArray(pArray, length);
    freeArray(pArray, length);
    pArray = NULL;
}

int main() {
    func1();
    
    return EXIT_SUCCESS;
}

