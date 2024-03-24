//
//  Circle.cpp
//  Circle
//
//  Created by David Zhang on 3/26/22.
//

#include "Circle.hpp"

namespace Hello{

    Complex& Complex::operator += (const Complex& rhs){
        imag += rhs.imag;
        real = rhs.real;
        return *this;
    }
    Complex operator+ (const Complex& lhs, const Complex& rhs){
        Complex copy = Complex(lhs);
        copy += rhs;
        return copy;
    }
}
