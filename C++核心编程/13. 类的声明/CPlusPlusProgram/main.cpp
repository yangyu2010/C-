//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;


class Circle {
    const double PI = 3.14;
public:
    double radius = 0;
    
    double calculatePerimeter() {
        return 2 * PI * radius;
    }
};

void func1() {
    Circle c1;
    c1.radius = 5;
    double perimeter = c1.calculatePerimeter();
    cout << perimeter << endl;
}


int main() {
    
    func1();
    //func2();
    
    return EXIT_SUCCESS;
}

