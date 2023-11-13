//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;


void func1(void) {
    //int &ref = 10;
    
    const int &ref = 10;
    //ref = 20;
    
    int *p = (int *)&ref;
    *p = 20;
    cout << ref << endl;
}





void showValue(const int &a) {
    //a = 1000;
    cout << "showValue a = " << a << endl;
}

void func2(void) {
    int a = 10;
    showValue(a);
    cout << "func2 a = " << a << endl;
}



int main() {
    //func1();
    func2();
    
    return EXIT_SUCCESS;
}

