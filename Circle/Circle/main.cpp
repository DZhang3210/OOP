//
//  main.cpp
//  Circle
//
//  Created by David Zhang on 3/26/22.
//

#include <iostream>
#include "Circle.hpp"

using namespace std;
using namespace Hello;



int main() {
    Complex a(1,1);
    Complex b(3,1);
    cout <<"a: " << a << endl;
    cout << "a+=b: " << (a+=b) << endl;
    cout <<"a: " << a << endl;
    cout << "a + b: " << (a+b) << endl;
    cout <<"a: " << a << endl;

    
    
    return 0;
}

