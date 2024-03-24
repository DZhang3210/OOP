//
//  main.cpp
//  SubClasses
//
//  Created by David Zhang on 3/30/22.
//

#include <iostream>
#include<vector>

using namespace std;

class Hello{
public:
    Hello(int c, int b): x(c), y(b){}
    virtual void greetings (){std::cout << "Hello" << std::endl;}
    
protected:
    const int getX() const{return x;}
    
private:
    int getY(){return y;}
    int x;
    int y;
};
class Hi: public Hello{
public:
    Hi(int c, int b): Hello::Hello(c, b){}
    void greetings(){std::cout << "Hola " << std::endl;}
    
};

void greetMe(Hello& b){
    b.greetings();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Hello h = Hello(4, 3);
    Hi f = Hi(3,4);
    greetMe(f);
    
    
    
    return 0;
}
