//
//  main.cpp
//  2-16-22
//
//  Created by David Zhang on 2/16/22.
//

#include <iostream>
#include <fstream>
#include<string>
#include<vector>

using namespace std;

class Thing{
    friend ostream& operator=(ostream& os, const Thing& rhs);
public:
    Thing(int x){p = new int(x);}
    void setValue(int val){*p = val;}
    int getValue() const {return *p;}
    //void clear()
     ~Thing(){  //~ no return type built-in destructor
         //This will delete everything as soon as the variable goes outside of the scope
         //This only affects local variables, clears value and then dereferences pointer
        delete p;   //removes value
        p = nullptr; //resets adress in object
    }
    //when we copy structor
    Thing(const Thing& other){
        int theValue = *(other.p);
        p = new int (theValue);
    }
    
private:
    int* p;
};


int main() {
    // insert code here...
    cout << "Hello, World!\n";
    //Person& p = new Person(name, age);
    /*for(size_t i = 0; i < stooges.size(); i++){
        delete stooges[i]; //deletes item
    }//when you delete the items there are dangling pointers so you have to clear the array first in order to not leave open pointers
    stooges.clear();    //clears array
     */
    
    Thing* thingPtr = new Thing(28);
    //Since outside of scope we only reset 28 local variable
   //Therefore, we have to delete the thingPtr and dereference or free up space
    delete thingPtr;
    thingPtr = nullptr;
    
    int x = 6, y = 28;
    
    return 0;
}
