//
//  point.hpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 11/23/23.
//

#ifndef point_hpp
#define point_hpp

#include <stdio.h>




class Point {
public:
    void setX(int x);
    int getX();
    void setY(int y);
    int getY();
    
private:
    int m_X;
    int m_Y;
};




#endif /* point_hpp */
