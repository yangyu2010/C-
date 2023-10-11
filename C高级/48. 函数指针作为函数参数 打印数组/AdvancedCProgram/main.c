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


void printArray(void *array, int arrayLength, int itemLength, void(*printArrayFunc)(void *data)) {

    // 这里如果是void *
    // 再去做指针偏移时, 会是+1的
    // 而不是根据具体的类型来跳多少字节 所以要根据每个元素的大小来跳
    /*
     0x7ff7bfeff230
     0x7ff7bfeff231
     0x7ff7bfeff232
     */
    printf("%p\n", array);
    printf("%p\n", array + 1);
    printf("%p\n", array + 2);

    char *p = array;
    
    for (int i = 0; i < arrayLength; i++) {
        void *data = p + i * itemLength;
        printArrayFunc(data);
    }
}


void printIntArrayFunc(void *data) {
    int *i = data;
    printf("%d\n", *i);
}

void printDoubleArrayFunc(void *data) {
    double *i = data;
    printf("%f\n", *i);
}



struct Person {
    char name[64];
    int age;
};


void printPerson(void *data) {
    struct Person *p = data;
    printf("%s, %d\n", p->name, p->age);
}


void func1(void) {
    int array[5] = { 10, 20, 30, 40, 50 };
    int arrayLength = sizeof(array) / sizeof(int);
    printArray(&array, arrayLength, sizeof(int), printIntArrayFunc);
}

void func2(void) {
    double array[5] = { 10, 20, 30, 40, 50 };
    int arrayLength = sizeof(array) / sizeof(double);
    printArray(&array, arrayLength, sizeof(double), printDoubleArrayFunc);
}

void func3(void) {
    struct Person person1 = { "person1", 1 };
    struct Person person2 = { "person2", 2 };
    struct Person person3 = { "person3", 3 };
    struct Person person4 = { "person4", 4 };
    struct Person person5 = { "person5", 100 };

    struct Person array[5] = { person1, person2, person3, person4, person5};
    int arrayLength = sizeof(array) / sizeof(struct Person);
    printArray(&array, arrayLength, sizeof(struct Person), printPerson);

}

int main() {
    func3();
    
    return EXIT_SUCCESS;
}

