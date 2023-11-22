//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;

/*
 struct Person {
     char name[64];
     int age;
     
     void eat() {
         printf("%s吃饭了\n", name);
     }
     
 };
 
 
 int main() {

     struct Person p;
     strcpy(p.name, "Jack");
     p.age = 20;
     p.eat();
     

     return EXIT_SUCCESS;
 }
 */

class Person {
public:
    char name[64];
    int age;
    
    void eat() {
        printf("%s吃饭了\n", name);
    }
    
};

/*
 struct 和 class 的区别
 
 class默认权限是 私有权限
 struct默认权限是 公共权限
 
 
 public     公共权限 成员 类内类外都可以访问
 private    私有权限 成员 类内可访问   类外不可以访问 子类不可以访问
 protected  保护权限 成员 类内可访问   类外不可以访问 子类可以访问
 */


int main() {

    struct Person p;
    strcpy(p.name, "Jack");
    p.age = 20;
    p.eat();
    

    return EXIT_SUCCESS;
}



