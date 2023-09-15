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

//void sortArray(char *array[6], int length) {

void sortArray(char **array, int length) {
    for (int i = 0; i < length; i++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (strcmp(array[j], array[min]) < 0) {
                min = j;
            }
//            if (array[j] < array[min]) {
//                min = j;
//            }
        }
        
        if (min != i) {
            char *temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
    
}

void printArray(char **array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%s ", array[i]);
    }
    printf("\n");
}

void func1(void) {
     char *array[6] = {"dddd", "e", "g", "aaa", "bbb", "ccc"};
    
    // void sortArray(char *array, int length)
    // Incompatible pointer types passing 'char *[5]' to parameter of type 'char *'
    // sortArray(array, 5);
    
    int length = sizeof(array) / sizeof(char *);
    sortArray(array, length);
    printArray(array, length);
}

int main() {
    func1();
    
    return EXIT_SUCCESS;
}

