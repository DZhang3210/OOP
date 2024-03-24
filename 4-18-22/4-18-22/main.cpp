//
//  main.cpp
//  4-18-22
//
//  Created by David Zhang on 4/18/22.
//

#include <iostream>
#include <string>
using namespace std;

int& returnLocal(){
    int i = 5;
    return i;
}

class A{
public:
    A(const string& x){}
    //A(string& x){}
    
private:
    
};

int main(int argc, const char * argv[]) {
    A a("string");
    A b();
    cout << returnLocal() << endl;
}
