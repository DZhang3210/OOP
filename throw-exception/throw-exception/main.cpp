//
//  main.cpp
//  throw-exception
//
//  Created by David Zhang on 5/6/22.
//

#include <iostream>
#include <vector>
#include<cstdlib>
#include<stdexcept>
using namespace std;

//class Out_Bounds_Exception: public exception{
//    char* what () const noexcept{
//        return "Out of Bounds Exceptions :D";
//    }
//};

//void Throw(){
//    throw out_of_range();
//}

int main(int argc, const char * argv[]) {
    
    
    try{
        vector<int> v {2, 1,3};
        v.at(19);
//    Throw();
    }catch(const out_of_range& b){
        cout << "Caught an out_of_range exception" << endl;
    }catch(double b){
        cout << b << endl;
    }catch(...){
        cout << "Caught an Exception" << endl;
    }
    return 0;
}
