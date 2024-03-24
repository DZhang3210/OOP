////
////  test.cpp
////  Employerr-Employee
////
////  Created by David Zhang on 4/15/22.
////
//#include <iostream>
//using namespace std;
//
//class Hello{
//
//};
//
////class A{
////public:
////    //A():x(0) {}
////private:
////    Hello x;
////};
////class B: public A{
////public:
////    //B():y(0){}
////    virtual void display(){
////        cout << "hi" << endl;
////    }
////private:
////    Hello y;
////};
////class C: public B{
////public:
////    C(){}
////private:
////    Hello z;
////};
//
//class A {
//private:
// string name;
//public:
// A(string& aString) : name(aString) {}
// A() : name() {}
// virtual void getName() const {
// cout << name << endl;
// }
// virtual void bigTimes() =0;
//virtual ~A(){
//
//}
//};
//void A::bigTimes(){
//    cout << "Big Big Times" << endl;
//}
//class B : public A {
//public:
//B(){}
//    void bigTimes() final {
//        A::bigTimes();
//        cout << "BIG BIG TIMES" << endl;
//    }
//    ~B(){
//
//    }
//};
//
//
//class C : public B {
//    /*void bigTimes(){
//        A::bigTimes();
//        B::bigTimes();
//        cout << "big big times" << endl;
//    }*/
//    ~C(){
//
//    }
//};
//
//void func(A& a) { cout << "foo(A)\n"; };
//void func(B& b) { cout << "foo(B)\n"; };
//
//int main(){
////    A a;
////    B b;
////    C c;
//
//B b;
////b.bigTimes();
//A* c = new C;
//c->bigTimes();
//
//delete c;
//}
