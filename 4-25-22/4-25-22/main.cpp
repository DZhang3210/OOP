//
//  main.cpp
//  4-25-22
//
//  Created by David Zhang on 4/25/22.
//

#include <iostream>
using namespace std;
template <typename T> // template header
//template is some data type
//only creates type creation per type
class Vector{
public:
    explicit Vector(size_t howMany = 0, T val = T()){   //Integers do have a default constructor, but we simply don't use it that often, and T will need to have a default constructor
    
    }
};

//int main(){
//    Vector<int> v;      //No more code duplication in creating vector<int> v
//    Vector<double> vecOfDouble; //No more code duplication in creating vector<double> vecOfDouble
//}
