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


struct Teacher {
    char *name;
    char **students;
};



void allocateSpace(struct Teacher ***teachers, int teacherCount, int studentCount) {
    // 开辟老师数组内存
    struct Teacher **teachersArray = malloc(sizeof(struct Teacher *) * teacherCount);
    for (int i = 0; i < teacherCount; i++) {
        // 开辟每个老师的内存
        teachersArray[i] = malloc(sizeof(struct Teacher));
        
        // 开辟每个老师的名字内存
        teachersArray[i]->name = malloc(sizeof(char) * 64);
        sprintf(teachersArray[i]->name, "Teacher_Name_%d", i+1);
        
        // 开辟每个老师下的学生数组内存
        teachersArray[i]->students = malloc(sizeof(char *) * studentCount);
        for (int j = 0; j < studentCount; j++) {
            
            // 开辟每个老师下的每个学生内存
            teachersArray[i]->students[j] = malloc(sizeof(char) * 64);
            sprintf(teachersArray[i]->students[j], "%s_Student_Name_%d", teachersArray[i]->name, j+1);
        }
    }
    
    *teachers = teachersArray;
}



void printArray(struct Teacher ***teachers, int teacherCount, int studentCount) {
    for (int i = 0; i < teacherCount; i++) {
        printf("%s\n", (*teachers)[i]->name);
        
        for (int j = 0; j < studentCount; j++) {
            printf("    %s\n", (*teachers)[i]->students[j]);
        }
    }
}


//void freeArray(struct Teacher ***teachers, int teacherCount, int studentCount) {
//    for (int i = 0; i < teacherCount; i++) {
//        // 释放老师的名字
//        if ((*teachers)[i]->name != NULL) {
//            free((*teachers)[i]->name);
//            (*teachers)[i]->name = NULL;
//        }
//
//        for (int j = 0; j < studentCount; j++) {
//            // 释放每个老师下的每个学生名字
//            if ((*teachers)[i]->students[j] != NULL) {
//                free((*teachers)[i]->students[j]);
//                (*teachers)[i]->students[j] = NULL;
//            }
//        }
//
//        // 释放老师的学生数组
//        if ((*teachers)[i]->students != NULL) {
//            free((*teachers)[i]->students);
//            (*teachers)[i]->students = NULL;
//        }
//
//        // 释放每个老师
//        if ((*teachers)[i] != NULL) {
//            free((*teachers)[i]);
//            (*teachers)[i] = NULL;
//        }
//    }
//
//    // 释放老师数组
//    if (*teachers != NULL) {
//        free(*teachers);
//        *teachers = NULL;
//    }
//
//}

void freeArray(struct Teacher **teachers, int teacherCount, int studentCount) {
    for (int i = 0; i < teacherCount; i++) {
        // 释放老师的名字
        if (teachers[i]->name != NULL) {
            free(teachers[i]->name);
            teachers[i]->name = NULL;
        }
        
        for (int j = 0; j < studentCount; j++) {
            // 释放每个老师下的每个学生名字
            if (teachers[i]->students[j] != NULL) {
                free(teachers[i]->students[j]);
                teachers[i]->students[j] = NULL;
            }
        }
        
        // 释放老师的学生数组
        if (teachers[i]->students != NULL) {
            free(teachers[i]->students);
            teachers[i]->students = NULL;
        }
        
        // 释放每个老师
        if (teachers[i] != NULL) {
            free(teachers[i]);
            teachers[i] = NULL;
        }
    }

    // 释放老师数组
    if (teachers != NULL) {
        free(teachers);
        teachers = NULL;
    }
    
}


void func1(void) {
    struct Teacher **teachers = NULL;
    int teacherCount = 5;
    int studentCount = 10;
    allocateSpace(&teachers, teacherCount, studentCount);
    printArray(&teachers, teacherCount, studentCount);
    //freeArray(&teachers, teacherCount, studentCount);
    freeArray(teachers, teacherCount, studentCount);
    teachers = NULL;
}

int main() {
    func1();
    
    return EXIT_SUCCESS;
}

