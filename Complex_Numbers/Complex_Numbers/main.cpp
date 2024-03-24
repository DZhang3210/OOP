//
//  main.cpp
//  Complex_Numbers
//
//  Created by David Zhang on 3/25/22.
//

#include <iostream>
#include "Complex.hpp"
using namespace std;
using namespace Ambiguity;


int main() {
    ComplexNumber a, b;
    a = ComplexNumber (10, 3);

    cout << "a: "<< a << endl<< "b: " << b << endl;
    //cout << "a+b: " << (a+b) << endl;
    cout << "a: " << a << endl;
    //cout << "a+=b: " << (a+=b) << endl;
    //cout << "a: " << a << endl;
    cout << "a++ "<< (++a) << endl;
    cout << "a: " << a << endl;
    cout << "a==b " << (a==b) << endl;
}


