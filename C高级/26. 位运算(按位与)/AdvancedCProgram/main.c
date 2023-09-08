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


void isEvenNumber(int num) {
    if ((num & 1) == 1) {
        printf("%d是基数\n", num);
    } else {
        printf("%d是偶数\n", num);
    }
}

void func1(void) {
    int a = 201;
    isEvenNumber(a);
}


int main() {
    func1();
    
    return EXIT_SUCCESS;
}



/*
 c语言中

 void isEvenNumber(int num) {
    if ((num & 1) == 1) {
        printf("%d是基数\n", num);
    } else {
        printf("%d是偶数\n", num);
    }
 }

 为什么和1做与运算后, 能知道一个数是偶数 奇数?

 
 
 
 这是因为在二进制表示中，奇数的最低位总是1，而偶数的最低位总是0。当一个整数和1进行与运算（&）时，如果结果是1，则说明该整数的最低位是1，即该整数是奇数；如果结果是0，则说明该整数的最低位是0，即该整数是偶数。

 例如，假设我们有一个整数5，其二进制表示为101。当我们将其和1（二进制表示为1）进行与运算时，得到的结果是1，表示5是奇数。

 再比如，假设我们有一个整数6，其二进制表示为110。当我们将其和1（二进制表示为1）进行与运算时，得到的结果是0，表示6是偶数。
 
 */
