//
//  Constructor_Call.cpp
//  Employerr-Employee
//
//  Created by David Zhang on 4/19/22.
//
#include <iostream>
using namespace std;

class A{
    friend ostream& operator << (ostream& os, const A& rhs){
        cout << "A" << endl;
        return os;
    }
public:
    A(){display();}
    virtual void display(){
        cout << "A" << endl;
    }
    A& operator +=(const A& rhs){
        cout << "A +=" << endl;;
        return *this;
    }
};
class B: public A{
    friend ostream& operator << (ostream& os, const B& rhs){
        cout << "B" <<endl;
        return os;
    }
public:
    B& operator += (const B& rhs){
        cout << "B += " << endl;
        return * this;
    }
    B(){display();}
    void display(){
        cout << "B" << endl;
    }
};
class C: public B{
public:
    C(){display();}
    void display(){
        cout << "C" << endl;
    }
};

A operator+ (const A& b, const A&e){
    A c;
    cout << "A +" << endl;
    return c;
}
B operator+ (const B& n, const B& e){
    B c;
    cout << "B  +" << endl;
    return c;
}

void displayingPlus(A& a, A& b){
    cout << "A+B  -- Overloaded" << endl;
    a+b;
}
void displayingDisplay(A& a){
    cout << "Display Function -- Overloaded" << endl;
    cout << a << endl;
}
void displayingPlusEqual(A& a, A& b){
    cout << "A+=b -- Overloaded" << endl;
    a +=b;
}

int main(){
    B a;
    B b;
    displayingPlus(a,b);
    displayingDisplay(a);
    displayingPlusEqual(a,b);
}
