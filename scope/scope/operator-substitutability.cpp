//
//  operator-substitutability.cpp
//  scope
//
//  Created by David Zhang on 4/18/22.
//
#include <iostream>
using namespace std;

class A{
    friend bool operator ==(const A& lhs, const A& rhs);
friend ostream& operator<< (ostream& os, const A& rhs){
    rhs.display();
    return os;
    }
public:
    A(int x, int y):x(x), y(y){}
//    bool operator== (const A& rhs){
//        return x = rhs.x && y == rhs.y;
//    }
    virtual void display() const{
        cout << "A" << endl;
    }
    
private:
    int x;
    int y;
};
bool operator== (const A& lhs, const A& rhs){
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

class B : public A{
    friend bool operator ==(const B& lhs, const B& rhs);
public:
    B(int x, int y, int z): A(x, y), z(z){}
    void display() const{
        cout << "B" << endl;
    }
private:
    int z;
    
};
bool operator == (const B& lhs, const B& rhs){
    return (A)lhs == (A)rhs && lhs.z == rhs.z;
}


int main(){
    A a(2,4);
    B b(2,4,9);
    B b1 (2,4,9);
    cout << a << endl;
    cout << b << endl;
    cout << (b==b1) << endl;
}
