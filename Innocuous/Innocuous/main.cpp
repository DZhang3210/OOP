//
//  main.cpp
//  Innocuous
//
//  Created by David Zhang on 4/21/22.
//

#include <iostream>
using namespace std;

class A{
public:
    ~A(){
        cout << "destroyed" << endl;
    }
};

void func(){
    A a;
}

int main() {
    func();
    cout << "---------" << endl;
    A a;
    
    return 0;
}
