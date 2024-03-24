//
//  Rational.cpp
//  rec08
//
//  Created by David Zhang on 3/25/22.
//

#include "Rational.hpp"
#include <vector>
#include <string>

using namespace std;

namespace CS2124{

//CONSTRUCTOR METHODS
Rational::Rational():numerator(1), denominator(1) {}
Rational::Rational(int input): numerator(input), denominator(1){}
Rational::Rational(int num, int denom): numerator(num), denominator(denom){};

//CHECKS FOR CERTAIN CONDITION IF(R){}
Rational::operator bool() const {
    return numerator != 0;
}

//NORMALIZING FUNCTIONS
int Rational::greatestCommonDivisor(int x, int y) {
    while (y != 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

void Rational::normalize(){
    //Check this later
    int gcd = greatestCommonDivisor(abs(numerator), abs(denominator));
    numerator/= gcd;
    denominator/=gcd;
    if((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)){
        numerator *= -1;
        denominator  *= -1;
    }
}

//THE ARITHMATIV
Rational& Rational::operator +=(const Rational& rhs){
    numerator *= rhs.denominator;
    numerator += rhs.numerator * denominator;
    denominator *= rhs.denominator;
    normalize();
    return *this;
}

Rational operator +(const Rational& lhs,const Rational& rhs){
    Rational returns = Rational(lhs);
    returns += rhs;
    return returns;
}



Rational& Rational::operator ++ (){
    numerator += denominator;
    return (*this);
}

Rational Rational::operator ++ (int dummy){
    Rational original(*this);
    numerator += denominator;
    return original;
}

Rational& operator --(Rational& lhs){
    lhs += Rational(-1, 1);
    return lhs;
}

Rational operator --(Rational& lhs, int dummy){
    Rational original(lhs);
    --lhs;
    return original;
}

//OSTREAM AND ISTREAM METHODS
istream& operator >>(istream  &input, Rational& rhs){
    input >> rhs.numerator >> rhs.denominator;
    rhs.normalize();
    return input;
}

ostream& operator << (ostream& os, const Rational& rhs){
    os << rhs.numerator <<"/" << rhs.denominator;
    return os;
}


//COMPARISON METHODS
bool operator == (const Rational& lhs, const Rational& rhs){
    return lhs.numerator == rhs.numerator && lhs.denominator == rhs.denominator;
}
bool operator !=(const Rational& lhs, const Rational& rhs){
    return !(lhs == rhs);
}
bool operator < (const Rational& lhs, const Rational& rhs){
    return  lhs.numerator*rhs.denominator < rhs.numerator * lhs.denominator;
}
bool operator >= (const Rational& lhs, const Rational& rhs){
    return (lhs == rhs || !(lhs < rhs));
    
}
bool operator > (const Rational& lhs, const Rational& rhs){
    return (!(lhs < rhs) && lhs != rhs);
    
}
bool operator <= (const Rational& lhs, const Rational& rhs){
    return((lhs < rhs) || lhs == rhs);
}


}
