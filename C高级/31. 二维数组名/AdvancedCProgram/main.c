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


// 二维数组的定义方式
void func1(void) {
//    int array[3][3] = {
//        {1, 2, 3},
//        {4, 5, 6},
//        {7, 8, 9}
//    };
    
    //int array[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    int array[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}


void func2(void) {
    int array[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // 36
    // printf("%d\n", sizeof(array));
    
    // 除了两种特殊情况外, 二维数组名称是 指向第一个一维数组的数组指针
    // 特殊情况1 sizeof
    // 特殊情况2 对数组名称取地址 &array 对二维数组取地址 获取的是二维数组的指针 int (*p)[3][3] = &array;
    
    int(*p)[3][3] = &array;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //p是一个指向三维数组的指针，它存放着数组array的地址。
            //*p是指向array第一行的数组的指针 不是指向第一行第一个元素的指针
            //(*p + i)是指向第几行的数组指针 每次+1是跳跃的整个一维数组 也是一个指向数组的指针
            //*(*p + i)是解引用, 得到的是第几行数组的第一个元素的地址 也就是 1 4 7的地址
            //*(*p + i) + j是第几行数组第几列元素的地址
            //*(*(*p + i) + j)是解引用, 取出第几行数组第几列元素的具体值
            printf("%d ", *(*(*p + i) + j));
        }
        printf("\n");
    }
    
    
}


void func3(void) {
    int array[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Incompatible pointer types initializing 'int *' with an expression of type 'int[3][3]'
    // int *p = array;
    int (*p)[3] = array;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //p是指向array第一行的数组的指针 不是指向第一行第一个元素的指针
            //(p + i)是指向第几行的数组指针 每次+1是跳跃的整个一维数组 也是一个指向数组的指针
            //*(p + i)是解引用, 得到的是第几行数组的第一个元素的地址 也就是 1 4 7的地址
            //*(p + i) + j是第几行数组第几列元素的地址
            //*(*(p + i) + j)是解引用, 取出第几行数组第几列元素的具体值
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }

}


//void printArray(int array[3][3], int row, int col) {
//void printArray(int array[][3], int row, int col) {
void printArray(int (*p)[3], int row, int col) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //printf("%d ", array[i][j]);
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}


void func4(void) {
    int array[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printArray(array, 3, 3);
}

int main() {
    //func2();
    //func3();
    func4();
    
    return EXIT_SUCCESS;
}


/*
 
 ============================================================================================================================================

 c语言中

 int array[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
 };
 int (*p)[3] = array;

 下面几个值分别代表什么?
 p
 p + i
 *(p + i)
 *(p + i) + j
 *(*(p + i) + j)
 
 ============================================================================================================================================
 
 - `p`：这是一个指向数组的指针，它指向整个`array`数组的首地址。
 - `p + i`：这是对数组中的行进行移位。具体来说，`i`表示偏离数组开始位置的行数。例如，如果`i = 1`，那么`p + i`就会指向`array`数组中第二行的首地址。
 - `*(p + i)`：这是对行的解引用，得到的结果是一个指向该行第一个元素的指针。换句话说，它会访问第`i`行的首元素。
 - `*(p + i) + j`：这是在第`i`行中，对列进行移位。具体来说，`j`表示偏离行开始位置的列数。例如，如果`j = 2`，那么`*(p + i) + j`就会指向第`i`行、第三列的元素的地址。
 - `*(*(p + i) + j)`：这是对上述地址进行解引用，得到的结果是`array[i][j]`的值。换句话说，它会访问第`i`行、第`j`列的元素的值。
 
 ============================================================================================================================================

 *(*(p + i))
 
 ============================================================================================================================================
 
 `*(*(p + i))`：这是对地址进行二次解引用，得到的结果是第`i`行、第0列的元素的值。换句话说，它会访问并返回二维数组`array[i][0]`的值。
 
 ============================================================================================================================================

 p + i 不是指向了每一行数组中的首位, 为什么*(p + i)是指向该行第一个元素的指针?

 对不起，我可能没有表述清楚。
 `p + i`确实指向了每一行数组中的首位，也就是第`i`行的地址。然而，这个地址本身是针对整个行数组的（例如array[1]、array[2]等），因此，它是一个指向数组的指针。
 当你做`*(p + i)`操作时，你其实是在解引用这个指向数组的指针。根据C语言的规则，解引用一个指向数组的指针将得到数组的首元素的地址。所以说，`*(p + i)`可以看作是指向第`i`行的首个元素的指针。同时，你也可以通过增加偏移量来访问该行的其它元素，例如`*(p + i) + 1`会指向第`i`行的第二个元素的地址。
 
 ============================================================================================================================================

 */




/*
 
 ============================================================================================================================================

 c语言
 int array[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
 };

 int(*p)[3][3] = &array;

 下面几个值分别代表什么?

 p
 *p
 *p + i
 *(*p + i)
 *(*p + i) + j
 *(*(*p + i) + j)

 ============================================================================================================================================

 ============================================================================================================================================
 
 p: 是一个指向三维数组的指针，它存放着数组array的地址。
 *p: 解引用p，得到的是整个二维数组{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }。
 *p + i: 对二维数组进行加法操作，指代的是数组中的第i个行数组。例如，当i=1时，该表达式就表示的是第二个行数组{4, 5, 6}。
 *(*p + i): 对上一步得到的行数组解引用，可以得到这个行数组的第一个元素值。例如，当i=1时，该表达式的结果就是4。
 *(*p + i) + j: 对第i个行数组进行加法操作，表示的是该行数组中的第j个元素。例如，当i=1且j=2时，该表达式表示的是数字6。
 *(*(*p + i) + j): 对上一个表达式解引用，得到的就是第i行第j列的那个元素值。例如，当i=1且j=2时，该表达式表示的是数字6。
 
 ============================================================================================================================================

 
 */
