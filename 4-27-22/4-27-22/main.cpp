//
//  main.cpp
//  4-27-22
//
//  Created by David Zhang on 4/27/22.
//

#include <iostream>
using namespace std;

template<typename T>
void mySwap(T& x, T& y){
    T temp = x;
    x = y;
    y = temp;
}

//pair<int, double> foo(){
//    //return 42, 3.14;
//    return make_pair(42, 3.14);
//}
auto foo(){
    //return 42, 3.14;
    return make_pair(42, 3.14);
}

int main() {
    int a = 17, b = 42;
    cout << a << ' ' << b << endl;
    a,b = b,a; //Evaluate a, assign b to itself, Evaluate a
    a,(b = b),a;
    
    cout << a << ' ' << b << endl;
    
    int l = a;
    a = b, b = l;
    
    mySwap(a,b);
    
    cout << a << ' ' << b << endl;
    
    pair<int, double> val = foo();
    cout << val.first << ' ' << val.second << endl;
    
    auto [r,s] = foo();
    cout << r << ' ' << s << endl;
    
    return 0;
}
