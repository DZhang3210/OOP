//
//  Rational.hpp
//  rec08
//
//  Created by David Zhang on 3/25/22.
//
#ifndef Rational_hpp
#define Rational_hpp

#include <stdio.h>
#include<iostream>
namespace CS2124{
class Rational{
    friend std::ostream& operator << (std::ostream& os, const Rational& rhs);
    friend bool operator == (const Rational& lhs, const Rational& rhs);
    friend bool operator < (const Rational& lhs, const Rational& rhs);
    friend std::istream& operator >>(std::istream  &input, Rational& rhs);
public:
    Rational(const Rational& rhs){
        numerator = rhs.numerator;
        denominator = rhs.denominator;
    }
    int greatestCommonDivisor(int x, int y);
    void normalize();
    
    Rational& operator ++ ();
    Rational operator ++ (int dummy);
    
    Rational();
    Rational(int input);
    Rational(int num, int denom);
    
    Rational& operator +=(const Rational& rhs);
    explicit operator bool() const;
    
private:
    int numerator;
    int denominator;
};
Rational operator +(const Rational& lhs,const Rational& rhs);
Rational& operator --(Rational& lhs);
Rational operator --(Rational& lhs, int dummy);
bool operator !=(const Rational& lhs, const Rational& rhs);
bool operator >= (const Rational& lhs, const Rational& rhs);
bool operator > (const Rational& lhs, const Rational& rhs);
bool operator <= (const Rational& lhs, const Rational& rhs);
}
#endif /* Rational_hpp */

