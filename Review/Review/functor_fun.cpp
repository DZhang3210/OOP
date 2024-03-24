//
//  functor_fun.cpp
//  Review
//
//  Created by David Zhang on 5/10/22.
//

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
using namespace std;




bool isOdd(int n){
    assert(n%2 == 1);
    return n%2 == 1;
}
struct NewException: public exception{
    const char* what() const noexcept{
        //Noexcept means this cannot return an exception
        return "why!!";
    }
};


//int main(){
//    try{
//        vector<int> vec;
//        vec.push_back(28);
//        vec.at(17) = 42;
//    }catch(exception& exc){
//        cout << exc.what() << endl;
//    }
//    vector<int> vec;
//    vec.push_back(28);
//    vec.at(17) = 42;
    
//    try{
//
//        try{
//            try{
//                if(isOdd(2))
//                    throw exception();
//            }catch(...){
//                cout << "Hoy" << endl;
//            }
//        }catch(exception& exc){
//            cout << exc.what() << endl;
//        }
//
//        throw exception();
//    }catch(...){
//        cout << "Exception Found" << endl;
//    }
    
    
//    vector<int> list = {10,9,7,8,4,5,2};
//    sort(list.begin(), list.end());
//
//    vector<int>::iterator c = find_if(list.begin(), list.end(), isOdd);
//
//
//    for(int i: list){
//        cout << i << endl;
//    }
//
//    cout << *c << endl;
//}
