////
////  main.cpp
////  scope
////
////  Created by David Zhang on 4/17/22.
////
//
//#include <iostream>
//#include<iostream>
//#include <fstream>
//using namespace std;
//
////int* foo(int x) {
////    int y = 2*x;
////    int* p = &y;
////    return p;
////}
////class A {
////public:
////    A(){}
////    A(string& x) {}
////};
////class B: public A{
////public:
////    B():{}
////};
////
////int main(){
////A a("hell");
////B b("what");
////
//////    ifstream read("read.txt");
//////    if(!read){
//////        cerr << "This don't work" << endl;
//////        exit(0);
//////    }
//////
//////
//////    string text;
//////    while (read >> text){
//////        cout << text << endl;
//////    }
//////
//////    cout << "Hullo type something in please" << endl;
//////    cin >> text;
//////    cout << "you typed in " << text << endl;
//////
////
////    int z = 29;
////    cout << *foo(z) << endl;
////}
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
//};
//class B : public A {
//public:
// B() {}
//};
//class C : public B {};
//int main() {
// A a("a"); // line A
// //B b("b"); // line B
// //b.getName(); // line C
// a.getName(); // line D
//}
