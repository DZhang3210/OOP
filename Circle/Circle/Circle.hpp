//
//  Circle.hpp
//  Circle
//
//  Created by David Zhang on 3/26/22.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include<iostream>
//#include "Circle.cpp"
//REMEMBER THAT WE'RE NOT USING NAMESPACE STD

namespace Hello {
    class Complex {
        friend std::ostream& operator << (std::ostream& os, const Complex& rhs){
            os << rhs.real << " " << rhs.imag << "i";
            return os;
        }
     
    public:
        Complex (int im = 0, int re = 0): imag(im), real(re){}
        Complex (int re): real(re), imag(0){}
        
        Complex& operator+= (const Complex& rhs);
        
        
        explicit operator bool(){return imag != 0&& real != 0;}
        
    private:
        int imag;
        int real;
     
        
    };
    Complex operator+ (const Complex& lhs, const Complex& rhs);
    /*Complex operator+ (const Complex& lhs, const Complex& rhs){
        Complex copy = Complex(lhs);
        copy += rhs;
        return copy;
    }*/
}


#endif /* Circle_hpp */
