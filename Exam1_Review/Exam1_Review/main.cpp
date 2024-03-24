//
//  main.cpp
//  Exam1_Review
//
//  Created by David Zhang on 2/27/22.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

/*class Thing{
    friend ostream& operator << (ostream& os, const Thing& rhs);
public:
    Thing(int& input1, const string& input2): g(input2), i(&input1){}
    void modifyInput(){
        *i -= 2;
        //i = new int(7);
    }
private:
    //const int* i;  i points to a CONSTANT INT
int* const i;   //int* const i points to a CONSTANT REFERENCE
string g;
          
};*/
/*ostream& operator << (ostream& os, const Thing& rhs){
    os << "*i: " << *(rhs.i) << " g: " << rhs.g<< endl;
    return os;
}*/




/*int main(int argc, const char * argv[]) {
    // insert code here...
    int fill = 2;
    
    int input1 = 7;
    string input2 = "German";
    Thing prints = Thing(input1, input2);

    
    cout << prints;
    
    int i = 7;
    int* b = &i;
    cout << b << endl;
    cout << *b << endl;
    
    
    return 0;
}*/
