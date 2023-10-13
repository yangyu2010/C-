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


/*
void sort(void *array, int arrayLength, int itemLength, int(*compare)(void *, void *), void(*change)(void *, int, int)) {
    for (int i = 0; i < arrayLength; i++) {
        int min = i;

        for (int j = i + 1; j < arrayLength; j++) {
            void *currentDataPointer = (char *)array + j * itemLength;
            void *minDataPointer = (char *)array + min * itemLength;
            if (compare(minDataPointer, currentDataPointer) < 0) {
                min = j;
            }
        }
        
        if (min != i) {
            change(array, min, i);
        }
    }
}
*/

void sort(void *array, int arrayLength, int itemLength, int(*compare)(void *, void *)) {

    void *tempItemPointer = malloc(itemLength);

    for (int i = 0; i < arrayLength; i++) {
        int min = i;

        for (int j = i + 1; j < arrayLength; j++) {
            void *currentDataPointer = (char *)array + j * itemLength;
            void *minDataPointer = (char *)array + min * itemLength;
            if (compare(minDataPointer, currentDataPointer) < 0) {
                min = j;
            }
        }
        
        if (min != i) {
            void *iPointer = (char *)array + i * itemLength;
            void *minPointer = (char *)array + min * itemLength;
            
            memcpy(tempItemPointer, iPointer, itemLength);
            memcpy(iPointer, minPointer, itemLength);
            memcpy(minPointer, tempItemPointer, itemLength);
        }
    }
    
    if (tempItemPointer != NULL) {
        free(tempItemPointer);
        tempItemPointer = NULL;
    }
}



struct Person {
    char name[64];
    int age;
};


//int personEqual(void *data1, void *data2) {
//    struct Person *p1 = data1;
//    struct Person *p2 = data2;
//
//    if ((strcmp(p1->name, p2->name) == 0) && p1->age == p2->age) {
//        return 1;
//    }
//    return 0;
//}

int comparePerson(void *data1, void *data2) {
    struct Person *person1 = data1;
    struct Person *person2 = data2;
//    printf("%d %d %d\n", person1->age, person2->age, person1->age - person2->age);
//    printf("%d %d %d\n", person1->age, person2->age, person1->age > person2->age);
//    printf("%d %d %d\n", person1->age, person2->age, person1->age < person2->age);
//    printf("\n");
    return person1->age - person2->age;
    
//    if (person1->age > person2->age) {
//        return 1;
//    } else if (person1->age == person2->age) {
//        return 0;
//    }
//    return -1;
}

void changePerson(void *array, int index1, int index2) {
    struct Person *personArray = array;
    struct Person temp = personArray[index1];
    personArray[index1] = personArray[index2];
    personArray[index2] = temp;
}

void printPerson(void *data) {
    struct Person *p = data;
    printf("%s, %d\n", p->name, p->age);
}


void func1(void) {
    struct Person person1 = { "person1", 12 };
    struct Person person2 = { "person2", 2 };
    struct Person person3 = { "person3", 34 };
    struct Person person4 = { "person4", 40 };
    struct Person person5 = { "person5", 1 };

    struct Person array[5] = { person1, person2, person3, person4, person5};
    int arrayLength = sizeof(array) / sizeof(struct Person);
    
    printf("\n排序前:\n");
    for (int i = 0; i< arrayLength; i++) {
        printPerson(&(array[i]));
    }
    
    //sort(&array, arrayLength, sizeof(struct Person), comparePerson, changePerson);
    sort(&array, arrayLength, sizeof(struct Person), comparePerson);
    
    printf("\n排序后:\n");
    for (int i = 0; i< arrayLength; i++) {
        printPerson(&(array[i]));
    }
}





int compareInt(void *data1, void *data2) {
    int *i1 = data1;
    int *i2 = data2;
    return *i1 - *i2;
}

void changeInt(void *array, int index1, int index2) {
    int *intArray = array;
    int temp = intArray[index1];
    intArray[index1] = intArray[index2];
    intArray[index2] = temp;
}

void printInt(void *data) {
    int *i = data;
    printf("%d\n", *i);
}



void func2(void) {
    int array[5] = { 1, 20, 3, 40, 5};
    int arrayLength = sizeof(array) / sizeof(int);
    
    printf("\n排序前:\n");
    for (int i = 0; i< arrayLength; i++) {
        printInt(&(array[i]));
    }
    
    //sort(&array, arrayLength, sizeof(int), compareInt, changeInt);
    sort(&array, arrayLength, sizeof(int), compareInt);
    
    printf("\n排序后:\n");
    for (int i = 0; i< arrayLength; i++) {
        printInt(&(array[i]));
    }
}

int main() {
    func1();
    func2();
    
    return EXIT_SUCCESS;
}

