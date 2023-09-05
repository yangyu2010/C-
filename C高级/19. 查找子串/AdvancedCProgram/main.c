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



int findSubString(char *str, char *sub) {
    int index = -1;
    
    while (*str != '\0') {
        index++;
        
        // 如果当前不想等 直接跳到下一个
        if (*str != *sub) {
            str++;
            continue;
        }
        
        char *subStr = str+1;
        char *subSub = sub+1;
        
        while (*subSub != '\0') {
            if (*subStr != *subSub) {
                str++;
                break;
            }
            subStr++;
            subSub++;
        }
        
        if (*subSub == '\0') {
            return index;
        }
    }
    
    return -1;
}


int findSubstr(char *mainStr, char *subStr) {
   int mainSize = strlen(mainStr);
   int subSize = strlen(subStr);

   for(int i = 0; i <= mainSize - subSize; i++) {
      int j;

      for(j = 0; j < subSize; j++) {
         if(mainStr[i + j] != subStr[j]) {
            break;
         }
      }

      if(j == subSize) {
         return i; // 子串在主串中的起始位置
      }
   }

   return -1; // 如果子串不在主串中，则返回-1
}


int main() {

    char *str = "nfabdcdnfef";
//    int index = findSubString(str, "dnf");
    int index = findSubstr(str, "dnf");
    printf("%d\n", index);
    
    return EXIT_SUCCESS;
}



/*
 c语言实现一个字符串查找子串的逻辑, 比如abcdefg中查找edf

 
 以下是一个使用C语言实现的函数，用于在字符串中查找子串：

 ```C
 #include <stdio.h>
 #include <string.h>

 int findSubstr(char *mainStr, char *subStr) {
    int mainSize = strlen(mainStr);
    int subSize = strlen(subStr);

    for(int i = 0; i <= mainSize - subSize; i++) {
       int j;

       for(j = 0; j < subSize; j++) {
          if(mainStr[i + j] != subStr[j]) {
             break;
          }
       }

       if(j == subSize) {
          return i; // 子串在主串中的起始位置
       }
    }

    return -1; // 如果子串不在主串中，则返回-1
 }

 int main() {
    char mainStr[] = "abcdefg";
    char subStr[] = "edf";

    int position = findSubstr(mainStr, subStr);

    if(position != -1) {
       printf("Found at index: %d\n", position);
    } else {
       printf("Not found\n");
    }

    return 0;
 }
 ```

 这个函数`findSubstr`接收两个参数：一个主字符串和一个子字符串。 它通过遍历主字符串并与子字符串进行比较来查找子字符串。 如果找到子字符串，它将返回子字符串在主字符串中的起始位置。如果没有找到子字符串，它将返回-1。

 注意，请确保主字符串长于或等于子字符串，否则此代码将不起作用。
 
 */
