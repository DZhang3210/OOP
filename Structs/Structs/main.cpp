//
//  main.cpp
//  Structs
//
//  Created by David Zhang on 3/26/22.
//

#include <iostream>
using namespace std;

struct rectangle{
    int height;
    int width;
};

class Holodeck{
public:
    //Holodeck():program(0){}
    //Holodeck(int val): program(val){}
    
    void display() {cout << "Holodeck program: " << program << endl;}
private:
    int program;
};
class Galaxy{
public:
    void display(){cout << "Galaxy class ship \n"; }
private:
    Holodeck something;
};

const int& changeX(int& x){
    x+=3;
    return x;
}

class CLASS {
public:
    CLASS(int k): i(k){}
    int getK(){return i;}
    const int& returnStuff(const int& w){
        return w;
    }
    
private:
    int i;
};

double* update (const double& num){
    const double* dbl_ptr = &num;
    cout << *dbl_ptr << ' ';
    dbl_ptr = new double(num*2);
    return dbl_ptr;
}



int main() {
    double val = -2.3;
    double * result_ptr = update(val);
    cout << *result_ptr << ' ';
    delete result_ptr;
    
    
    rectangle* rect = new rectangle{1,2};
    delete rect;

    Galaxy galaxy;
    galaxy.display();
    
    
    int w = 3;
    CLASS g = 2;
    const int c = g.returnStuff(w);
    cout << g.getK() << endl;
    cout << w << endl;
    
    
    int b = 0;
    int a = changeX(b);
    cout << a << endl;
}

