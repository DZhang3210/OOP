//
//  Complex.hpp
//  Complex_Numbers
//
//  Created by David Zhang on 3/25/22.
//

#ifndef Complex_hpp
#define Complex_hpp

#include<iostream>
#include <stdio.h>

namespace Ambiguity {

class ComplexNumber{
    friend std::ostream& operator << (std::ostream& os, const ComplexNumber& rhs);
    friend std::istream& operator >> (std::istream& os, ComplexNumber& rhs);
    friend bool operator == (const ComplexNumber& lhs, const ComplexNumber& rhs);
    friend ComplexNumber& operator+= (ComplexNumber& lhs, const ComplexNumber& rhs);
public:
    ComplexNumber ();
    ComplexNumber (int imag, int real);
    //Copy Control
    
    ComplexNumber(const ComplexNumber& rhs){
        real = rhs.real;
        imag = rhs.imag;
    }
    ~ComplexNumber(){
        //delete anything on the heap
    }
    ComplexNumber& operator = (const ComplexNumber& rhs){
        if(this != &rhs){
            //delete anything on the heap
            real = rhs.real;
            imag = rhs.imag;
            //reallocate for memory
        }
        return *this;
    }
    
    bool operator < (const ComplexNumber& rhs);
    ComplexNumber& operator++();
    
private:
    int imag;
    int real;
};
}
#endif /* Complex_hpp */
