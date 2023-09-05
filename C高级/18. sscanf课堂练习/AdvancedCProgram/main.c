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

//1. 跳过数据
void test01(){
    char buf[1024] = { 0 };
    //跳过前面的数字
    //匹配第一个字符是否是数字，如果是，则跳过
    //如果不是则停止匹配
    sscanf("123456aaaa", "%*d%s", buf);
    printf("buf:%s\n",buf);
}

//2. 读取指定宽度数据
void test02(){
    char buf[1024] = { 0 };
    //跳过前面的数字
    sscanf("123456aaaa", "%7s", buf);
    printf("buf:%s\n", buf);
}

//3. 匹配a-z中任意字符
void test03(){
    char buf[1024] = { 0 };
    //跳过前面的数字
    //先匹配第一个字符，判断字符是否是a-z中的字符，如果是匹配
    //如果不是停止匹配
    sscanf("abcdefg123456", "%[a-z]", buf);
    printf("buf:%s\n", buf);
}

//4. 匹配aBc中的任何一个
void test04(){
    char buf[1024] = { 0 };
    //跳过前面的数字
    //先匹配第一个字符是否是aBc中的一个，如果是，则匹配，如果不是则停止匹配
    sscanf("abcdefg123456", "%[aBc]", buf);
    printf("buf:%s\n", buf);
}

//5. 匹配非a的任意字符
void test05(){
    char buf[1024] = { 0 };
    //跳过前面的数字
    //先匹配第一个字符是否是aBc中的一个，如果是，则匹配，如果不是则停止匹配
    sscanf("bcdefag123456", "%[^a]", buf);
    printf("buf:%s\n", buf);
}

//6. 匹配非a-z中的任意字符
void test06(){
    char buf[1024] = { 0 };
    //跳过前面的数字
    //先匹配第一个字符是否是aBc中的一个，如果是，则匹配，如果不是则停止匹配
    sscanf("123456ABCDbcdefag", "%[^a-z]", buf);
    printf("buf:%s\n", buf);
}


void func1(void) {
    char *str = "helloworld@itcast.cn";
    char buf1[1024] = { 0 };
    char buf2[1024] = { 0 };

    sscanf(str, "%[^@]@%s", buf1, buf2);
    printf("%s\n", buf1);
    printf("%s\n", buf2);
}

void func2(void) {
    char *str = "123abcd$myname@000qwe";
    char buf[1024] = { 0 };

    sscanf(str, "%*[^$]$%[^@]", buf);
    printf("%s\n", buf);
    
}

int main() {
    func2();
    
    return EXIT_SUCCESS;
}


