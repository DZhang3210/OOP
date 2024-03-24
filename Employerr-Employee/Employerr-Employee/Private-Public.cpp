////
////  Private-Public.cpp
////  Employerr-Employee
////
////  Created by David Zhang on 4/16/22.
////
//#include<iostream>
//using namespace std;
//
//class constructor{
//public:
//    constructor(){cout << "constructor" << endl;}
//};
//
//class A{
//    
//public:
//    void printX(){
//        cout << "X: " << x << endl;
//    }
//    A():x(0){cout << "A constructor" << endl;}
//    
//    virtual void hello() {
//        cout << "Hello A" << endl;
//    }
//    virtual ~A(){
//        cout << "deleting A" << endl;
//    }
//private:
//    //A():x(0){}
//    void printTable(){
//        cout << "printing" << endl;
//    }
//    int x;
//};
//
//class B: public A{
//    
//public:
//    B(){cout << "B constructor" << endl;}
//    ~B (){
//        cout << "deleting B" << endl;
//    }
//    
//private:
//    void hello(){
//        //A::hello();
//        cout << "Hello B" << endl;
//    }
//    constructor con;
//};
//class C: public B{
//public:
//    C():B(){cout << "C constructor" << endl;}
//    
//    ~C(){
//        cout << "deleting C" << endl;
//    }
//};
//
//int main(){
//    //A a;
//    //cout << sizeof(a) << endl;
//    
//    A* a = new B;
//    a -> hello();
//    delete a;
//    //b.hello();
//    //cout << sizeof(b) << endl;
//    //C c;
//    //cout << sizeof(c) << endl;
////    B b;
////    b.printX();
//    
//    //delete a;
//}
