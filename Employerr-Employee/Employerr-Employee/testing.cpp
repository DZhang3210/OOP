////
////  testing.cpp
////  Employerr-Employee
////
////  Created by David Zhang on 4/15/22.
////
//#include <iostream>
//using namespace std;
//
//class Base{
//public:
//    Base(int x):x(x){}
//
//    virtual void display() const{
//        cout << "Base" << endl;
//    }
//    void hey(){
//        cout << "Hey" << endl;
//    }
//    bool operator==(const Base& rhs) const{
//        return (x == rhs.x);
//    }
//private:
//    int x;
//};
//class Derived : public Base{
//public:
//    Derived (int x, int y): Base(x), y(y){}
//
////    void display(int) const{
////        cout << "Derived" << endl;
////    }
//    void display() const{
//        cout << "Derived" << endl;
//    }
//    bool operator==(const Derived& rhs) const{
//        return Base::operator==(rhs) && y == rhs.y;
//    }
//    void unfinished (int z);
//private:
//    int y;
//};
////void overload(const Base& lhs){
////    //return lhs.operator==(rhs);
////    lhs.display();
////}
//
//bool equalsBase(const Base& lhs, const Base& rhs){
//    return lhs.operator==(rhs);
//    //lhs->display();
//}
//bool equalsDerived(const Derived& lhs, const Derived& rhs){
//    return lhs.operator==(rhs);
//}
//
//void mul(int a){
//
//    cout<<a<<" ";
//
//}
//
//void mul(int &a)
//
//{
//
//   cout<<a<<" ";
//
//}
//
//int main(){
//    Derived der(3,7);
//    Derived ber(3,8);
////cout << (der == ber) << endl;
//    cout << equalsBase(der, ber) << endl;
//    //int a  = 7;
//    //mul(a);
//
//
//
//
//    //cout << equalsDerived(der, ber) << endl;
//    //der.hey();
//}
