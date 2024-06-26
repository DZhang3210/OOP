////
////  Test.cpp
////  Const
////
////  Created by David Zhang on 4/15/22.
////
//#include<iostream>
//using namespace std;
//
////class Foo {
////public:
//// Foo() {}
////void func(int x) { cout << x << endl; }
////};
////class Bar : public Foo {
////public:
//// Bar() {}
//// void func() { cout << "SomeNumber" << endl; }
////};
////int main() {
//// Bar b;
//// b.func(17);
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
//
//class B : public A {
//public:
// B() {}
//};
//class C : public B {};
//
//class Shape {
//public:
// Shape() {}
// virtual void draw() = 0;
//};
//class Circle : public Shape {
//public:
// Circle() {}
// void draw() { cout << "I’m a Circle" << endl; }
//}; 
class A {
private:
 string name;
public:
 A(string& aString) : name(aString) {}
 A() : name() {}
 virtual void getName() const {
 cout << name << endl;
 }
};
class B : public A {
public:
 B() {}
};
class C : public B {};
int main {
 A a; // line A
 B b; // line B
 A* ap = &a; // line C
 A* bp = &b; // line D
}

void func(A& a) { cout << “foo(A)\n”; };
void func(B& b) { cout << “foo(B)\n”; };
int main() {
 A a;
 B b;
 C c;
 func(a);
 func(b);
 func(c);
};
