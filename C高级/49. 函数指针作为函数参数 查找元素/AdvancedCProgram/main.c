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


int find(void *array, int arrayLength, int itemLength, void *data, int(*equal)(void *, void *)) {

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
        void *currentData = p + i * itemLength;
        
        if (equal(currentData, data) == 1) {
            return i;
        }
    }
    
    return -1;
}



struct Person {
    char name[64];
    int age;
};


int personEqual(void *data1, void *data2) {
    struct Person *p1 = data1;
    struct Person *p2 = data2;

    if ((strcmp(p1->name, p2->name) == 0) && p1->age == p2->age) {
        return 1;
    }
    return 0;
}


void func3(void) {
    struct Person person1 = { "person1", 1 };
    struct Person person2 = { "person2", 2 };
    struct Person person3 = { "person3", 3 };
    struct Person person4 = { "person4", 4 };
    struct Person person5 = { "person5", 100 };

    struct Person array[5] = { person1, person2, person3, person4, person5};
    int arrayLength = sizeof(array) / sizeof(struct Person);
    
    struct Person person6 = { "person2", 20 };

    int index = find(&array, arrayLength, sizeof(struct Person), &person6, personEqual);
    printf("%d\n", index);
}

int main() {
    func3();
    
    return EXIT_SUCCESS;
}

