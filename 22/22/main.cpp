//
//  main.cpp
//  22
//
//  Created by David Zhang on 2/28/22.
//

//Oh boy I can't wait to learn about vectors ... cpp

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
    // Vector(size_t size, int value = 0) {}

    // Copy control / BIG 3: ~Vector,  Vector(const Vector& vect), Vector& operator = (const Vector& vect)
    
    ~Vector(){
        delete [] data; //Delete what's on the heap
    }
    Vector(const Vector& rhs){
        theSize = rhs.theSize;
        theCapacity = rhs.theCapacity;
        data = new int[theCapacity];
        for (size_t i = 0; i < theSize; i++){
            data[i] = rhs.data[i];
        }
    }
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

    void push_back(int val) {
    // Make sure we have enough space
    if (theSize == theCapacity) {
        if(theSize == 0){
            delete [] data;
            theCapacity = 1;
            data = new int [theCapacity];
        }else{
        int* oldData = data;
        data = new int [2*theCapacity];
        for (size_t i = 0; i < theSize; i++){
            data[i] = oldData[i];
        }theCapacity *= 2;
        delete [] data; //Operator which deletes entire oldData array
        }
    }

    // add the value to the array
    //*(data+theSize) = val;
    //(data + theSize); pointer arithmatic
    data[theSize] = val;    //syntactic sugar {space not allocated here, already allocated}
    ++theSize;

    }

    // size_t size() const;
    // void clear();
    // void pop_back();

    // Square brackets
    
private:
    size_t theSize;
    size_t theCapacity;
    int* data;  //This stands for the 0th element of the array
};


int main() {

    Vector v;  // Not templated.  Our Vector class can only hold ints.
    v.push_back(17);
    // v.push_back(42);
    // v.push_back(6);
    // v.push_back(28);

    // Vector v2(v);
    // Vector v3;
    // v3 = v;

    // for (size_t i = 0; i < v.size(); ++i)
    //     cout << v[i] << endl;
    // v[0] = 100;

    // v = 17;
}
