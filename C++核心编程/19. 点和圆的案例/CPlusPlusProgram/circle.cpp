//
//  circle.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 11/23/23.
//

#include "circle.hpp"

#include <iostream>
using namespace std;


void Circle::setR(int r) {
    m_R = r;
}
int Circle::getR() {
    return m_R;
}

void Circle::setP(Point p) {
    m_P = p;
}
Point Circle::getP() {
    return m_P;
}



void Circle::isInCircle(Point p) {
    int distance = (p.getX() - m_P.getX()) * (p.getX() - m_P.getX()) + (p.getY() - m_P.getY()) * (p.getY() - m_P.getY());
    int radius2 = getR() * getR();
    
    if (distance > radius2) {
        cout << "点在圆外面" << endl;
    } else if (distance < radius2) {
        cout << "点在圆内部" << endl;
    } else {
        cout << "点在圆上" << endl;
    }
    
    printf("内部m_P %p\n", &m_P);
}
