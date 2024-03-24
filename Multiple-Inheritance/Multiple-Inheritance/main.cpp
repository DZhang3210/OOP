//
//  main.cpp
//  Multiple-Inheritance
//
//  Created by David Zhang on 5/6/22.
//

#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

class megaBase{
public:
    void function2(){
        cout << "megaBase" << endl;
    }
};
class base1:virtual public megaBase{
public:
    void function1(){
        cout << "base1" << endl;
    }
};
class base2:virtual public megaBase{
public:
    void function1() const{
        cout << "base1" << endl;
    }
};
class derived:public base1, public base2{
public:
    void function1(){
        base1::function1();
    }
};

template<typename T>
struct clist{
    T data;
    clist(T x):data(x){}
};

int main(int argc, const char * argv[]) {
    
    clist<char> l ('a');
    //l.data= 4;
    cout << l.data << "\n";
    
    derived der;
    der.function1();
    der.function2();
    
    int a = 1;
    int b = 2;
    int c = 3;
    c = (a, b = b, b);
    
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    
    vector<int> gh {6,5,4,3,2,1};
    sort(gh.begin(), gh.end());
    for(auto c: gh){
        cout << c << " ";
    }cout << "\n";
    
    char lh [] = "Bjarne Stroustrup";
    
    const list<int> lc(gh.begin(), gh.end());
    
    for(int i: lc){
        cout << i << " ";
    }cout << "\n";
    
    list<int>::const_iterator y = find(lc.begin(), lc.end(),5);
    cout << *y << endl;
    
    list<int>::const_iterator p = find_if(lc.begin(), lc.end(), [](int n){return n%2 == 0;});
    cout << *p << endl;
    
    bool result = [](int n){return n%2 == 0;} (4);
    cout << result << endl;
    
    char* e = find(lh, lh + 17, 'j');
    cout << *e << endl;
    
    pair<string, int> product("Hello", 4);
    product = make_pair("Not", 18);
    cout << product.first << endl;
    cout << product.second<< endl;
    
    map<int, string> mappa;
    mappa.insert(pair<int, string> (3, "Yes"));
    mappa.insert(pair<int, string> (4, "No"));
    //cout << *(mappa.find(4)) <<" " << endl;
    
    set<int> val = {6,8,7,10,12};
    
    vector<int> li = {1,2,3,4,5,6,7,8};
    return 0;
}
