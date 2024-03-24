////
////  main.cpp
////  Const
////
////  Created by David Zhang on 4/15/22.
////
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void hello(int*& input){
//    *input +=1;
//    
//}
//
//class Base{
//public:
//    virtual void foo () const{
//        cout << "Base Foo" << endl;
//    }
//    void display() const{
//        this->foo();
//    }
//private:
//};
//class Derived : public Base{
//    void foo() const{
//        cout << "Derived Foo" << endl;
//    }
//    void custom() const{
//        cout << "Custom" << endl;
//    }
//};
//
//void overload(const Base& bas){
//    bas.display();
//}
//
//
///*
//ostream& operator<<(ostream& os, const Derived& rhs) {
//    //os << "Derived";
//    rhs.display(os);
//    return os;
//}
//*/
//
//int main() {
//    int someNumber = 34;
//    const int* i = &someNumber;
//    someNumber = 42;
//    //*i = 28;
//    
////    Base* bas = new Derived();
////    overload(*bas);
////
////
////
////    delete bas;
//    
//}
