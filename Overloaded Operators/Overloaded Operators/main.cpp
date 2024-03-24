//
//  main.cpp
//  Overloaded Operators
//
//  Created by David Zhang on 3/25/22.
//

#include <iostream>
//Copy Constructor -> For intializing a new copy
Thing(const Thing& copy):g(copy.g), i(copy.i),b(copy.b){}
//Destructor Method
~Thing(){
    //nothing to delete since
}
//Copy Constructor for reinitalization
Thing& operator = (const Thing& rhs){   //Operator overloader for = sign
    if(this != &rhs){   //check if same
        //delete i;      free up resources
        //i = new int (rhs.i);      //create new redesignation on heap
        //g = rhs.g                 //reassign other stack variables
    }
    //Must return *this since * this is a pointer
    return *this;
}

class Rational{
    friend ostream& operator << (ostream& os, const Rational& rhs);
    friend bool operator == (const Rational& lhs, const Rational& rhs);
    friend bool operator < (const Rational& lhs, const Rational& rhs);
    friend istream& operator>>(istream  &input, Rational& rhs);
public:
    int greatestCommonDivisor(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
    void normalize(){
        //Check this later
        int gcd = greatestCommonDivisor(numerator, denominator);
        numerator/= gcd;
        denominator/=gcd;
        if((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)){
            numerator *= -1;
            denominator  *= -1;
        }
    }
    Rational():numerator(1), denominator(1) {}
    Rational(int input): numerator(input), denominator(1){}
    Rational(int num, int denom): numerator(num), denominator(denom){};
    
    Rational& operator +=(const Rational& rhs){
        numerator += rhs.numerator;
        denominator+= rhs.denominator;
        (*this).normalize();
        return *this;
    }
    
    Rational& operator ++ (){
        numerator += denominator;
        (*this).normalize();
        return *this;
    }
    Rational operator ++ (int dummy){
        Rational original(*this);
        numerator += denominator;
        (*this).normalize();
        return original;
    }
    Rational& operator -- (){
        numerator -= denominator;
        (*this).normalize();
        return *this;
    }
    Rational operator -- (int dummy){
        Rational original(*this);
        numerator -= denominator;
        (*this).normalize();
        return original;
    }
    
    explicit operator bool() const {
        return numerator != 0;
    }
    
private:
    int numerator;
    int denominator;

};
istream& operator >>(istream  &input, Rational& rhs){
    /*string string1;
    string string2;*/
    input >> rhs.numerator >> rhs.denominator;
    rhs.normalize();
    return input;
}

ostream& operator << (ostream& os, const Rational& rhs){
    os << rhs.numerator <<"/" << rhs.denominator;
    return os;
}
Rational operator +(Rational& lhs, const Rational& rhs){
    Rational returns = Rational(lhs);
    returns += rhs;
    returns.normalize();
    return returns;
}
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
    if(lhs == rhs || !(lhs < rhs)){return true;}
    return false;
}
bool operator > (const Rational& lhs, const Rational& rhs){
    if(!(lhs < rhs) && lhs != rhs){return true;}
    return false;
    
}
bool operator <= (const Rational& lhs, const Rational& rhs){
    if(!(lhs < rhs) || lhs == rhs){return true;}
    return false;
}

