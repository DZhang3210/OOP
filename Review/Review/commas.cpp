////////////
////////////  commas.cpp
////////////  Review
////////////
////////////  Created by David Zhang on 5/10/22.
////////////
//////////#include<iostream>
//////////
//////////using namespace std;
//////////
//////////struct Base{
//////////    void eat () const{
//////////        cout << "Eat Const" << endl;
//////////    }
//////////    virtual ~Base(){
//////////        cout << "Base Delete" << endl;
//////////    }
//////////};
//////////struct Derived: public Base{
//////////    void eat(){
//////////        cout << "Regular Eat" << endl;
//////////    }
//////////    ~Derived(){
//////////        cout << "Derived Delete" << endl;
//////////    }
//////////};
//////////
//////////template <typename B>
//////////
//////////int main(){
//////////    Derived** data = new Derived*[3];
//////////    data[0] = new Derived();
//////////    data[1] = new Derived();
//////////    data[2] = new Derived();
//////////
//////////    cout << "=========="<< endl;
//////////    for(Derived** i = data; i < data + 3; i++){
//////////        delete *i;
//////////    }
//////////    cout << "=========="<< endl;
//////////
//////////    delete [] data;
//////////}
////////#include<iostream>
////////using namespace std;
////////
////////class A{
//////// public:
//////// int f(){return 1;}
//////// virtual int g(){return 2;}
//////// };
//////// class B: public A{
//////// public:
//////// int f(){return 3;}
//////// virtual int g(){return 4;}
//////// };
//////// class C: public A{
//////// public:
//////// virtual int g(){
////////     return 5;}
//////// };
//////// int main(){
//////// A *pa;
//////// A a;
//////// B b;
//////// C c;
////////pa=&a; cout<<pa -> f()<<endl; cout<<pa -> g()<<endl;
////////pa=&b; cout<<pa -> f() + pa -> g()<<endl;
////////pa=&c; cout<<pa -> f()<<endl; cout<<pa -> g()<<endl;
////////return 0;
////////}
//////
//////
//////
//////
//////
//////
//////#include<iostream>
////// class A{
////// public:
////// A(){}
////// virtual int output() = 0;
////// private:
////// int i;
////// };
////// class B: public A{
////// private:
////// int j;
//////};
////// class C{
////// public:
////// int f(int a){return x*a;}
////// protected:
////// void setX(int a){x=a;}
////// int getX(){return x;}
//////private:
////// int x;
//////};
////// class D: public C{
//////private:
////// int z;
////// };
////// int main(){
//////// A objA;
//////// B objB;
////// C objC;
////// D objD;
//////// C.setX(2);
//////// cout<<C.getX();
////////
//////// D.setX(1);
//////// D.f(3);
////// return 0;
////// }
////
////#include<iostream>
////using namespace std;
////
////class Quad{
////public:
////    Quad(int x, int y, int f, int z):x(x), y(y), f(f), z(z){}
////    virtual int Area () = 0;
////    int getX(){return x;}
////    int getY(){return y;}
////
////
////private:
////    int x, y, f, z;
////};
////
////class Rectangle: public Quad{
////public:
////    Rectangle(int x, int y, int f, int z): Quad(x,y,f,z){}
////    int Area(){
////        return getX()*getY();
////    }
////};
////
////int returnArea(Quad& quad){
////    return quad.Area();
////}
////
//////int main(){
//////    Rectangle rect(1,7,1,2);
//////    cout << returnArea(rect);
//////}
////
////class Triple{
////private:
////    friend ostream& operator << (ostream& os, const Triple& rhs){
////        cout << "Triple: " << rhs.x << "," << rhs.y << "," << rhs.z << endl;
////        return os;
////    }
////    int x, y, z;
////public:
////    Triple(int x, int y, int z):x(x), y(y), z(z){}
////    Triple():x(0), y(0), z(0){}
////
////    void operator() (int x1, int y1, int z1){
////        x = x1, y=y1, z=z1;
////    }
////};
//////int main(){
//////    Triple trip(4,8,9);
//////    cout << trip;
//////    trip(3,2,1);
//////    cout << trip;
//////}
////
////template<typename U>
////class Point{
////private:
////    U x, y;
////
////    friend ostream& operator<<(ostream& os, const Point& rhs){
////        os << "(" << rhs.x << "," << rhs.y << ")" << endl;
////        return os;
////    }   //don't forget the operators
////    friend Point& operator++ (Point& lhs){
////        lhs.x++, lhs.y++;
////        return lhs;
////    }
////public:
////    Point(U x, U y):x(x), y(y) {}
////    void swap(){
////        U t = x;
////        x= y;
////        y= t;
////    }
////};
////
////
//////int main(){
//////    Point p(3.2,2.5);
//////    cout << p;
//////    p.swap();
//////    ++p;
//////    cout << p;
//////}
////
////template <class T>
////
////// Template overloading of function
////void display(T t1)
////{
////    cout << "Displaying Template: "
////         << t1 << "\n";
////}
////
////// Template overloading of function
////void display(int t1)
////{
////    cout << "Explicitly display: "
////         << t1  << "\n";
////}
////
////// Driver Code
//////int main()
//////{
//////    // Function Call with a
//////    // different arguments
//////    display(200);
//////    display(12.40);
//////    display('G');
//////
//////    return 0;
//////}
////
////class Super {
//// public:
//// virtual void foo() {
////cout << "Super::foo()" << endl;
//// }
//// virtual void foo(int i) {
////cout << "Super::foo(" << i << ")" << endl;
//// }
////};
////class Sub : public Super {
//// public:
//// virtual void foo() {
////cout << "Sub::foo()" << endl;
//// }
////};
////
////struct A{
////    virtual ~A() {cout << "Destructor" << endl;}
////};
////struct B: public A{
////    ~B() {cout << "Destructor" << endl;}
////};
////struct C: public B{
////    ~C() {cout << "Destructor" << endl;}
////};
//////int main(){
//////    A* a = new C();
//////    delete a;
//////}
////
////
////// class Base {
////// public:
////// Base(){cout<<"Base"<<endl;}
////// Base(int i){cout<<"”Base”"<<i<<endl;}
////// ~Base(){cout<<"”Destruct Base”"<<endl;}
////// };
////// class Der: public Base{
////// public:
////// Der(){cout<<"”Der”"<<endl;}
////// Der(int i): Base(i) {cout<<"”Der”"<<i<<endl;}
////// ~Der(){cout<<"”Destruct Der”"<<endl;}
////// };
////// int main(){
////// Base a;
////// Der d(2);
////// return 0;
////// }
////
////
/////*
////  9.polyNonMember
////  22S Sec B
//// */
//////
//////#include <iostream>
//////using namespace std;
//////
//////class Base {
//////public:
////////    virtual void display(ostream& os) const {
////////    os << "Base";
////////    }
////////};
////////
////////ostream& operator<<(ostream& os, const Base& rhs) {
////////    //    os << "Base";
////////    rhs.display(os);
////////    return os;
////////}
////////
////////class Derived : public Base {
////////public:
////////    void display(ostream& os) const override {
////////    os << "Derived";
////////    }
////////};
//////
///////*
//////ostream& operator<<(ostream& os, const Derived& rhs) {
//////    //os << "Derived";
//////    rhs.display(os);
//////    return os;
//////}
//////*/
//////
////////=============CLient code===========
////////void func(const Base& base) {
////////    cout << base << endl;
//////    //operator<<(cout, base);
//////    //base.operator<<(cout);
//////    //    cout.operator<<(base);
////////}
//////
////////int main() {
////////    Derived der;
////////    cout << der << endl;
////////    //operator<<(cout, der);
////////    func(der);
////////}
//////
//////
//////
//////
///////*
//////    Copy Control with Inheritance
//////    Sec Base
//////*/
//////
//////#include <iostream>
//////using namespace std;
//////
//////class Base {
//////public:
//////    Base() {
//////        cerr << "Base()\n";
//////    }
//////    Base(const Base& rhs) {
//////        cerr << "Base(const Base&)\n";
//////    }
//////    //~Base() {
//////    virtual ~Base() {
//////        cerr << "~Base()\n";
//////    }
//////    Base& operator=(const Base& rhs) {
//////        cerr << "Base::operator=(const Base&)\n";
//////        return *this;
//////    }
//////};
//////
//////class Member {
//////public:
//////    Member() {
//////        cerr << "Member()\n";
//////    }
//////    ~Member() {
//////        cerr << "~Member()\n";
//////    }
//////    Member(const Member& rhs) {
//////        cerr << "Member(const Member&)\n";
//////    }
//////    Member& operator=(const Member& rhs) {
//////        cerr << "Member::operator=(const Member&)\n";
//////        return *this;
//////    }
//////};
//////
//////class Derived : public Base {
//////    Member mem;
//////public:
//////    //Derived() : Base() {}
//////    Derived() { cerr << "Derived()\n"; }
//////
//////    ~Derived() {
//////    cerr << "~Derived()\n";
//////    }
//////
//////    Derived(const Derived& rhs) : Base(rhs), mem(rhs.mem) {
//////    cerr << "Derived(const Derived&)\n";
//////    }
//////
//////    Derived& operator=(const Derived& rhs) {
//////    //*this Base::= rhs;
//////    //(*this).Base::operator=(rhs);
//////    //this->Base::operator=(rhs);
//////    Base::operator=(rhs);
//////
//////    mem = rhs.mem;
//////        cerr << "Derived::operator=(const Derived&)\n";
//////        return *this;
//////    }
//////};
//////
//////int main() {
//////    cerr << "Derived der;\n"
//////         << "------------\n";
//////    Derived der;
//////    cout << "===\n";
//////
//////    cerr << "Derived der2(der);\n"
//////         << "------------------\n";
//////    Derived der2(der);
//////    cout << "===\n";
//////
//////    cerr << "Derived der3 = der;\n"
//////         << "-------------------\n";
//////    Derived der3 = der;
//////    cout << "===\n";
//////
//////    cerr << "der = der2;\n"
//////         << "-----------\n";
//////    der = der2;
//////    cout << "===\n";
//////
//////    cerr << "Derived* p = new Derived();\n"
//////         << "delete p;\n"
//////         << "---------------------------\n";
//////    Derived* p = new Derived();
//////    delete p;
//////
//////    cout << "===\n";
//////    cerr << "Base* bp = new Derived();\n"
//////         << "delete bp;\n"
//////         << "---------------------------\n";
//////    Base* bp = new Derived();
//////    delete bp;
//////    cout << "===\n";
//////
//////}
////
////// 08.polyConst
////
////#include <iostream>
////using namespace std;
////
////class Base {
////public:
////    Base() {
////    //foo();
////    this->foo();
////    }
////    virtual void foo() const { cout << "Base\n"; }
////    void display() {
////    //this->foo();
////    foo();
////    }
////};
////
////class Derived : public Base {
////public:
////    Derived(int n) : Base(), x(n) {}
////    void foo() const override { cout << "Derived: x == " << x << endl; }
////private:
////    int x;
////};
////
////int main() {
////    Derived der(17);
////    der.display();
////}
//
///*
//  linked-list.cpp
//  22S Sec B
// */
//
//#include <iostream>
//using namespace std;
//
//struct Node {
//    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
//    int data;
//    Node* next;
//};
//
///*
//  display
//  length/size
//  add, remove at front / back / etc.
//  clear
//  duplicate
// */
//
//Node* listDuplicate(const Node* headPtr) {
//    // edge case
//    if (headPtr == nullptr) return nullptr;
//    
//    // initialization code
//    Node* result = new Node(headPtr->data);
//    const Node* p = headPtr->next;
//    Node* last = result;
//
//    while (p != nullptr) {
//    last->next = new Node(p->data);
//    last = last->next;
//    p = p->next;
//    }
//
//    return result;
//}
//
//
//void listAddTail(Node*& headPtr, int data) {
//    if (headPtr == nullptr) {
//    headPtr = new Node(data);
//    } else {
//    // find last node
//    Node* last = headPtr;
//    while (last->next != nullptr) {
//        last = last->next;
//    }
//    // Append the data to that last node
//    last->next = new Node(data);
//    }
//
//}
//
//void listAdd(Node* where, int data) {
//    // create a node for the data;
//    // Node* tmp = new Node(data);
//
//    // // Make our node point to the one after the "where" node
//    // tmp->next = where->next;
//
//    //Node* tmp = new Node(data, where->next);
//
//    // make where node point to the new one
//    //where->next = tmp;
//
//    if (where != nullptr) {
//    where->next = new Node(data, where->next);
//    }
//    
//}
//
//void listDisplayR(Node* headPtr) {
//    if (headPtr != nullptr) {
//    cout << headPtr->data << ' ';
//    //    if (headPtr->next != nullptr) {
//    listDisplayR(headPtr->next);
//    //    }
//    }
//}
//
////void listDisplay(Node* headPtr) const {
//void listDisplay(const Node* headPtr) {
//    while (headPtr != nullptr) {
//    cout << headPtr->data << ' ';
//    headPtr = headPtr->next;
//    }
//    cout << endl;
//}
//
//void listDisplay2(const Node* headPtr) {
//    const Node* p = headPtr;
//    while (p != nullptr) {
//    cout << p->data << ' ';
//    p = p->next;
//    }
//    cout << endl;
//}
//
//int listLength(const Node* headPtr) {
//    const Node* p = headPtr;
//    int count = 0;
//    while (p != nullptr) {
//    ++count;
//    p = p->next;
//    }
//    return count;
//}
//
//void listAddHead(Node*& headPtr, int data) {
//    // // create a node for the data
//    // Node* tmp = new Node(data);
//
//    // // made that node point to the old head node
//    // tmp->next = headPtr;
//    // Node* tmp = new Node(data, headPtr);
//
//    // // make the headPtr point to that node
//    // headPtr = tmp;
//    headPtr = new Node(data, headPtr);
//}
//
//int main() {
//    Node* myList = nullptr;
//    listDisplay(myList);
//    
//    listAddHead(myList, 17);
//    myList->next = new Node(28);
//    listDisplay(myList);
//
//
//    listAddHead(myList, 6);
//    listDisplay(myList);
//    Node* hel = listDuplicate(myList);
//    listDisplay(hel);
//}
