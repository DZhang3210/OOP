//
//  Complex.cpp
//  Complex_Numbers
//
//  Created by David Zhang on 3/25/22.
//

#include "Complex.hpp"
#include<iostream>
using namespace std;

namespace Ambiguity{
    ostream& operator << (ostream& os, const ComplexNumber& rhs){
        os << rhs.real << " + " << rhs.imag << "i";
        return os;
    }
    istream& operator >> (istream& os, ComplexNumber& rhs){
        cout << "Imaginary Number: ";
        os >> rhs.imag;
        cout << endl << "Real Number:";
        os >> rhs.real;
        return os;
    }


    //Constructor Overloading
    ComplexNumber:: ComplexNumber ():real(0), imag(0){};
    ComplexNumber:: ComplexNumber (int imag1, int real1):real(real1), imag(imag1){};


    //Operator Overloading
    bool ComplexNumber::operator < (const ComplexNumber& rhs){
        return imag > rhs.imag && real > rhs.real;
    }


ComplexNumber& operator += (ComplexNumber& lhs, const ComplexNumber& rhs){
    lhs.real += rhs.real;
    lhs.imag += lhs.imag;
    return lhs;
}

ComplexNumber& operator ++ (ComplexNumber& lhs){
    lhs += ComplexNumber(1,1);
    return lhs;
}

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs){
        ComplexNumber copy = ComplexNumber(lhs);
        copy += rhs;
        return ComplexNumber(1,1);
    }
bool operator == (const ComplexNumber& lhs, const ComplexNumber& rhs){
    return lhs.real == rhs.real && lhs.imag == rhs.imag;
}

}
