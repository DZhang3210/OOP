//
//  main.cpp
//  22
//
//  Created by David Zhang on 2/28/22.
//

/*
  Vector Class
  Demonstrates:
     Good example of copy control
     Dynamic arrays and pointer arithmetic
     Square bracket operator
     Implementation of an important data structure
  Sec Base
 */

#include <iostream>
using namespace std;

class Vector {
public:
    Vector() {
    theSize = 0;
    theCapacity = 0;
    data = nullptr;
    }
    
    //Another constructor
    explicit Vector(size_t size, int value = 0) {
        theSize = value;
        theCapacity = size;
        data = new int[theCapacity];
        data[0] = value;
    }

    // Copy control / BIG 3: ~Vector,  Vector(const Vector& vect), Vector& operator = (const Vector& vect)
    
    ~Vector(){
        delete [] data; //Delete what's on the heap
    }
    
    //Copy Constructor
    Vector(const Vector& rhs){
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        data = new int[theCapacity];
        for (size_t i = 0; i < theSize; i++){
            data[i] = rhs.data[i];
        }
    }
    
    //Operator = Overloader
    Vector& operator=(const Vector& rhs){
        if(this != &rhs){
            delete [] data;
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            data = new int[theCapacity];
            for (size_t i = 0; i < theSize; i++){
                data[i] = rhs.data[i];
            }
        }return *this;
    }

    const int operator [] (size_t index) const{
        return data[index];
    }
    
    int& operator [] (size_t index){
        return data[index];
    }
    
    
    void printVector(const Vector& v){
        for(size_t i = 0; i < v.size(); ++i){
            cout << v[i] << ' ';
        }
        cout << endl;
    }
    
    
    
    void push_back(int val) {
    // Make sure we have enough space
    if (theSize == theCapacity) {
        if(theSize == 0){
            delete [] data;
            //theCapacity = 1
            data = new int [theCapacity = 1];
        }else{
        int* oldData = data;
        data = new int [2*theCapacity];
        for (size_t i = 0; i < theSize; i++){
            data[i] = oldData[i];
        }theCapacity *= 2;
        delete [] oldData; //Operator which deletes entire oldData array
        }
    }

    // add the value to the array
    //*(data+theSize) = val;
    //(data + theSize); pointer arithmatic
    data[theSize] = val;    //syntactic sugar {space not allocated here, already allocated}
    ++theSize;

    }

    size_t size() const {return theSize;};
    void clear(){
        theSize = 0;
    }
    void pop_back(){
        --theSize;
    }
    const int* begin() const{
        return data;
        //return &data[0]
    }//Pointers/References can be used to create backdoors
    const int* end() const{
        return & data[theSize];
        //return data + theSize;
    }
    const int back() const{
        return data[theSize - 1];
    }
    //EXACT SAME BUT CONST SEPERATES
    int* end() {
        return & data[theSize];
        //return data + theSize;
    }
    int back() {
        return data[theSize - 1];
    }
    
    // Square brackets
    
private:
    size_t theSize;
    size_t theCapacity;
    int* data;  //This stands for the 0th element of the array
};


int main() {

    Vector v;  // Not templated.  Our Vector class can only hold ints.
    v.push_back(17);
    v.push_back(42);
    v.push_back(6);
    v.push_back(28);
    
    Vector v2(v);
    
    Vector v4 = v;  //Still intializing a field
    
    Vector v3;
    v3 = v;

    for (size_t i = 0; i < v.size(); ++i){
         cout << v[i] << endl;
    }
    
    for (int val : v){
        cout << val << ' ';
    }cout<<endl;
    
    /*for(int* p = v.begin(); p != v.end(); ++p){
        int val = *p;
        cout << val << ' ';
    }*/
    for(int& val: v){
        val*=2;
    }
    for(int*p = v.begin(); p != v.end(); ++p){
        int& val = *p;
        val *= 2;
    }
    
    
    v[0] = 100;

    //v = 17;
    v = Vector(17);
    
    //cout << v.back() << ' ' << v[v.size()-1] << endl;
}
