//
//  circle.hpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 11/23/23.
//

#ifndef circle_hpp
#define circle_hpp

#include <stdio.h>

#include "point.hpp"

class Circle {
public:

    void setR(int r);
    int getR();
    
    void setP(Point p);
    Point getP();

    void isInCircle(Point p);
    
private:
    int m_R;
    Point m_P;
};

#endif /* circle_hpp */
