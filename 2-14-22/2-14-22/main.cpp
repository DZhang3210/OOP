//
//  main.cpp
//  2-14-22
//
//  Created by David Zhang on 2/14/22.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int hello;
    int* p = &hello;
    string he = "Hhey";
    string* c = &he;
    //string* means it refers to the address of an & string element
    //int* means it refers to the address of an & int element
    
    cout << c << " " << *c << endl;
    //c refers to adress *c refers to item within element
    cout << sizeof(c) << " " << sizeof(*c) << " " << sizeof(string) << endl;
    //c stands for the element so only 8 bytes while *c is a string and therefore 24 bytes
    
    //nullptr is important to decide if a variable or pointer_adress is unitialized
    string* hey = nullptr;
    //hey = &he;
    if(hey == nullptr)
        cout << "Nuthin.. " << endl;
    
    // *(rhs.spouse).name   ||  rhs.spouse->name
        // how to dereference a pointer in an object and then access other variables
        //Also rhs.spouse would have access to others since method is also in class {spouse}
    //betrothed.spouse = this <- refers to adress of current object calling {this}
    //spouse = &betrothed
        //&betrothed is important so we reference object and not clone
    
    int x = 42;
    const int* f = &x;
    
    //How can we define a pointer that can only ever point at one item, the item it was intialized to point to
    
    int* const q = &x;
        //*q = & y;   //How can we prevent this?
        //int* const q will prevent q from being modified and turn it constant, and we need two seperate constances since this variable is really referencing 2 {<=>}
    //____ int* ____ q = &x
    
    const int z = 100;
    //int* r = &z;        //Potential Backdoor?? No... Must make a commitment w/ const int* r = &z
    //*r = 100;     //Make sure your pointer is congruent with the variable you're representing
    
    /*
     void marries(const Person& betrothed){
        const int* spouse = &betrothed
        betrothed.spouse = this
     }
     */
    
    //Vector<Person*> stooges <- holding pointer variables of strings
    /*for (const Person* stooge : stooges){  ||  !(const Person& stooge : stooges)
    cout << stooge-> getName() << endl;
    cout << *stooge << endl;
    }*/
    
    /*while(ifs >> name >> age){
        //Person someone(name, age);
        Person* p = new Person(name, age);
        //stooges.push_back(someone);
        stooges.push_back(p);
        //stooges.push_back(new Person(name, age));
    }*/
    /*for(size_t i = 0; i < stooges.size(); ++i){
        delete stooges[i];
    }
    stooges.clear();
    */
    
    
    return 0;
}
