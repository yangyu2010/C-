//
//  main.cpp
//  CPlusPlusProgram
//
//  Created by Yu Yang on 10/23/23.
//

#include <iostream>
using namespace std;


namespace KingGlory {
    int MonkeyKingId = 10;
}

namespace LOL {
    int MonkeyKingId = 20;
}


void func1(void) {
    //cout << KingGlory::MonkeyKingId << endl;
    
    // Target of using declaration conflicts with declaration already in scope
    // 当using声明与 就近原则同时出现, 会出错
    //int MonkeyKingId = 1;
    
    // using声明
    using KingGlory::MonkeyKingId;
    cout << MonkeyKingId << endl;
}

void func2(void) {
    //int MonkeyKingId = 1;
    // 当using编译指令和就近原则同时出现时, 优先使用就近原则
    using namespace KingGlory;
    
    // Reference to 'MonkeyKingId' is ambiguous
    // 如果有多个namespace, 使用同一个名字的变量, 会有冲突
    //using namespace LOL;
    
    cout << MonkeyKingId << endl;
}


int main() {
    
    //func1();
    func2();
    
    return EXIT_SUCCESS;
}

