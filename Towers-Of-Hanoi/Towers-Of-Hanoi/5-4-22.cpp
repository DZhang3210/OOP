//
//  5-4-22.cpp
//  Towers-Of-Hanoi
//
//  Created by David Zhang on 5/4/22.
//
//#define NDEBUG

#include <vector>
#include<iostream>
using namespace std;
void foo(){
    vector<int> v;
    //v[17] = 42;
    v.at(17) = 42;
    
    
    //cout << v[17]<< endl;
    cout << v.at(17)<< endl;
}
double hey(){
    cout << "Hey Running" << endl;
    return 3.0;
}

struct Exception{
    const char* what() const {return "I'm an Exception";}
};
struct MyException: public Exception{
    MyException(int val): val(val){}
    const char* what() const noexcept {return "I'm a MyException";}
    
    int val;
};

void bar(int n){
    assert(n <= 200);
    
    if(n > 200){
        throw MyException(n);
    }
}
void foo1(int n){
    vector<int> v {1,4,9,16};
    
    bar(n);
    
}

int main(){
    try{
        foo1(300);
    }
    catch(double d){
        cerr << "Caught a double: " << d << endl;
    }catch(MyException& d){
        cerr << d.what() << endl;
    }
    
    
    
    
    
    
    try{
        hey();
        foo();
    }catch(double d){
        cerr << "Caught a double: " << d << endl;
    }catch(...){    //any exception
        cerr << "So long and thanks for all the fish \n";
        exit(1);
    }
    
//    catch(out_of_range& ex){
//        cerr << "Caught an out_of_range exception: " << ex.what() << endl;
//    }
//    catch(exception& ex){
//        cerr << "Caught an exception: " << ex.what() << endl;
//    }

    //Works like if else statement
    
    cerr << "still running \n" << endl;
}
