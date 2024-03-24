//
//  main.cpp
//  exam1
//
//  Created by David Zhang on 3/24/22.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
double* update(const double& num){
    const double* dbl_ptr = &num;
    cout << *dbl_ptr << ' ';
    dbl_ptr = new double(num*2);
    return dbl_ptr;
}
int main(){
    double val = -2.3;
    double* result_ptr = update(val);
    cout << *result_ptr << ' ';
    delete result_ptr;
}*/

/*string& add_chars(string& str){
    str+= "mto";
    return str;
}
int main(){
    string orig;
    string upd = add_chars(orig);
    
    for(size_t i =0; i < orig.size(); i++){
        cout << orig[i] << ' ';
    }
}*/

struct newt{
    int region;
    string buff;
};

class Holodeck {
public:
    Holodeck(int val) : program(val){}
    void display () {cout << "Holodeck program: " << program << endl;}
private:
    int program  = 17;
};
class Galaxy{
public:
    void display (){cout << "Galaxy class ship \n";}
private:
    Holodeck something;
};

int main (){
    
    vector<newt*> list;
    list.push_back(new newt{3, "hey"});
    
    /*vector<int*> list;
    list.push_back(new int (3));
    list.push_back(new int (3));
    list.push_back(new int (3));
    list.push_back(new int (3));
    list.push_back(new int (3));
    */
    
}
