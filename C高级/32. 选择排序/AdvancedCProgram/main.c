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

void sortArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            //交换
//            array[i] = array[i] ^ array[min];
//            array[min] = array[i] ^ array[min];
//            array[i] = array[i] ^ array[min];

//            array[i] = array[i] + array[min];
//            array[min] = array[i] - array[min];
//            array[i] = array[i] - array[min];

            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void func1(void) {
    int array[] = {5, 6, 9, 1, 1, 1, 2, 7, 8, 3, 4, };
    int length = sizeof(array) / sizeof(int);
    sortArray(array, length);
    printArray(array, length);
}

int main() {
    func1();
    
    return EXIT_SUCCESS;
}

