//
//  good_syntax.cpp
//  Exam1_Review
//
//  Created by David Zhang on 2/27/22.
//

#include "good_syntax.hpp"
#include <iostream>
#include <vector>
using namespace std;

class sub {
public:
    sub(int input): x(input){}
    int getX() const {return x;}
private:
    int x;
};

class NewThing{
    friend ostream& operator << (ostream& os, const NewThing& rhs);
public:
    NewThing(const string& input): h(input), p(nullptr){}
    void setPointer(int input){p = new int(input);}
    const string& returnH()const {return h;}
    
    NewThing(const NewThing& copy):h(copy.h), p(new int(*(copy.p))){cout << "copy operator " << endl;}
    
    ~NewThing(){
        cout << "deleting " << *p << " at " << p << endl;
        delete p;
        for (sub* c: list){delete c;}
    }
    
    NewThing& operator =(const NewThing& rhs){
        cout << "using equals= overloaded operator " << endl;
        if(this != &rhs){
            delete p;
            p = new int (*(rhs.p));
            h = rhs.h;
        }
        return *this;
    }
    
    void addToList(int input){list.push_back(new sub(input));}
    
private:
    vector<sub*> list;
    int* p;
    string h;
};
ostream& operator << (ostream& os, const NewThing& rhs){
    os << "*p: " << *(rhs.p) << " h: " << rhs.h << endl;
    for (sub* c: rhs.list){
        cout << c->getX() << endl;
    }
    return os;
}

void addToList(const string& add, vector<string>& list){
    list.push_back(add);
    cout << "After: " << &add << endl;
}
//& indicates the desire to modify the variable in question OR save computing by copying element
int main(){
    NewThing fst = NewThing("hello");
    
    fst.addToList(3);
    fst.addToList(4);
    fst.addToList(5);
    fst.addToList(6);

    fst.setPointer(14);
    NewThing dst = fst;
    NewThing rst = NewThing("Konichiwa");
    rst = fst;
        //Assignment operator= is used when reassigning values of already INTIALIZED OBJECT
        //Copy Constructor is used when we want to create a NEW COPY OF THE EXISTING OBJECT

    cout << "fst: " << fst;
    cout << "dst: " << dst;
    cout << "rst: " << rst;
    
    /*vector<int> list;
    const int three = 3;
    list.push_back(&three);
    
    
    for (const int* i: list){
        *i = 17;
        cout << i << endl;
    }
    return 0;*/
    
    string add = "hello";
    cout << "Previous " << &add<< endl;
    vector<string> list;
    addToList("Hello", list);
    
    
}
