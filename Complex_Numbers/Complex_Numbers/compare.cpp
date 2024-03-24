//
//  compare.cpp
//  Complex_Numbers
//
//  Created by David Zhang on 3/25/22.
//

/*
   Arithmetic Operator Overloading
   InClass Sec C
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Complex {
    // op<< as a friend
    friend ostream& operator<<(ostream& os, const Complex& rhs) {
        os << rhs.real;
        if (rhs.imag >= 0) os << '+';
        os << rhs.imag << 'i';
        //os << showpos << rhs.imag << 'i' << noshowpos;
        return os;
    }
    friend bool operator==(const Complex& lhs, const Complex& rhs);
    friend Complex& operator+=(Complex& lhs, const Complex& rhs);
    
public:
Complex(double real = 0, double imag = 0) : real(real), imag(imag) {}


    explicit operator bool() const {
    return (real != 0) || (imag != 0);
    }

private:
    double real, imag;
};

bool operator==(const Complex& lhs, const Complex& rhs) {
    return rhs.real == lhs.real && rhs.imag == lhs.imag;
}

bool operator!=(const Complex& lhs, const Complex& rhs) {
    return ! (lhs == rhs);
}

Complex& operator+=(Complex& lhs, const Complex& rhs) {
    lhs.real += rhs.real;
    lhs.imag += rhs.imag;
    return lhs;
    }

Complex& operator++(Complex& lhs) {
lhs += Complex(1,1);
return lhs;
}
Complex operator++(Complex& lhs, int) {
Complex original(lhs);
++lhs;
return original;
}

//Complex& operator+(const Complex& lhs, const Complex& rhs) {
Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex result = Complex(lhs);
    result += rhs;
    return result;
}

/*
// Test code
int main() {
    Complex c1;         // 0+0i
    Complex c2(17);     // 17+0i
    Complex c3(3, -5);  // 3-5i
    cout << "c1: " << c1 << endl
         << "c2: " << c2 << endl
         << "c3: " << c3 << endl;

    // Testing equality and inequality operators
    cout << "c1 ";
    if (c1 == c2) cout << "==";
    else cout << "!=";
    cout << " c2\n";

    // The above four lines in one line:
    cout << "c1 " << (c1 == c2 ? "==" : "!=") << " c2\n";
    // c1 == c2;
    // c1.operator==(c2);
    // operator==(c1, c2);

    cout << "c1 " << (c1 == c1 ? "==" : "!=") << " c1\n";

    cout << "c1 " << (c1 != c2 ? "!=" : "==") << " c2\n";
    cout << "c1 " << (c1 != c1 ? "!=" : "==") << " c1\n";

    Complex one(1);
    cout << "one == 1 " << (one == 1) << endl;
    
    cout << "c2 + c3 " << (c2 + c3) << endl;
    //    one == 1;
    // one.operator==(1);
    // one.operator==(Complex(1));

    cout << "1 " << (1 == one ? "==" : "!=") << " one\n";
    // 1 == one;
    // 1.operator==(one);
    // operator==(1, one);


    // Testing "combination operator" op+=
    c1 += c2;

    // Testing op+
    c1 = c2 + c3;

    // Testing pre-increment
    cout << ++c1 << ' ' << c1 << endl;
    // ++c1;
    // c1.operator++();

    // Testing post-increment
    cout << c1++ << ' ' << c1 << endl;
    //    c1.operator++(0);

    Complex zero(0);
    cout << "zero is " << (zero ? "true" : "false") << endl;
    cout << "one is " << (one ? "true" : "false") << endl;

}
*/
