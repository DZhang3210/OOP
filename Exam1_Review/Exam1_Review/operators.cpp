//
//  operators.cpp
//  Exam1_Review
//
//  Created by David Zhang on 2/27/22.
//

#include "operators.hpp"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Thing{
    friend ostream& operator << (ostream& os, const Thing& rhs);
public:
    //Declare variables before initialization for optimization
    //Also if an object is initialized not in there then it will error since no default state
    Thing(int input1, const string& input2, int x, const string& y): g(input2), i(input1), b(x, y){}
    void modifyInput(){
        i -= 2;
        //i = new int(7);
    }
    Thing(const Thing& copy):g(copy.g), i(copy.i),b(copy.b){}
    ~Thing(){
        //nothing to delete since
    }
    Thing& operator = (const Thing& rhs){   //Operator overloader for = sign
        if(this != &rhs){   //check if same
            //delete i;      free up resources
            //i = new int (rhs.i);      //create new redesignation on heap
            //g = rhs.g                 //reassign other stack variables
        }
        //Must return *this since * this is a pointer
        return *this;
    }
private:
    class Inner{
        friend ostream& operator << (ostream& os, const Inner& rhs);
    public:
        Inner(int x, const string& y):x(x), y(y){}
        Inner(const Inner& copy):x(copy.x), y(copy.y){}
        
    private:
        int x;
        string y;
    };
    //const int* i;  i points to a CONSTANT INT
int i;   //int* const i points to a CONSTANT REFERENCE
string g;
Inner b;

friend ostream& operator << (ostream& os, const Thing::Inner& rhs);
          
};
ostream& operator << (ostream& os, const Thing::Inner& rhs){
    os << "x: " << rhs.x << " y: " << rhs.y << endl;
    return os;
}
ostream& operator << (ostream& os, const Thing& rhs){
    os << "i: " << (rhs.i) << " g: " << rhs.g << " Inner: " << rhs.b << endl;
    return os;
}

/*int main(){
    Thing newt = Thing(7, "get", 2, "retrieve");
    cout << newt;
    cout << Thing(newt);
    return 0;
}*/
