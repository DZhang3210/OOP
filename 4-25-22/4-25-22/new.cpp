//
//  new.cpp
//  4-25-22
//
//  Created by David Zhang on 4/25/22.
//

#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

char* myfind(char* start, char* stop, char target){
    for(char* p = start; p!= stop; ++p){
        if(*p == target)
            return p;
    }
    return stop;
}

list<char>::iterator myfind(list<char>::iterator start, list<char>::iterator stop, char target){
    for(list<char>::iterator p = start; p!= stop; ++p){
        if(*p == target)    //*p is already overloaded for the function of iterator
            return p;
    }
    return stop;
}

//template<typename T>
//T myfind(T start, T stop, char target){
template<typename T, typename U>
T myfind(T start, T stop, U target){
    for(T p = start; p!= stop; ++p){
        if(*p == target)        //why is this *p, or maybe since T is a typename so you can't really dereference
            return p;           //only get's error message when it tries to work through the template, and it happens                   to be incompatible, but also not sure which of the templates failed
    }
    return stop;
}
template<typename T, typename U>
T myfind_if(T start, T stop, U pred){
    for(T p = start; p!= stop; ++p){
        if(pred(*p))
            return p;
    }
    return stop;
}

bool isEven(int n){return n%2 == 0;}

struct IsEven{
    //operator call
    bool operator() (int n) const {return n%2 == 0;}
};

struct isMultiple{
    isMultiple(int divisor): divisor(divisor){}
    bool operator() (int n) const {return n%divisor == 0;}
    int divisor;
};

int main(){
    char arr [] = "Bjarne Stroustrup";
    int len = 17;
    sort(arr, arr+len);
    
    list<char> lc(arr, arr+len);    //underlying operation
                                    //Half open range using adresses
    
    vector<char> vc(lc.begin(), lc.end());  //half open range using iterators of begin and end
    //list<char>::iterator
        //since iterator is a subclass of list, and meant to stop outside from modifying/touching node class at all
    
    //Random access means they can access indexes of data structures in constant time?
    //When we access items we'll always access iterators over Nodes, since we don't want to overload Node with
    //methods, but we're completely fine with adding extra operators to shell (Iterator) method
    
    //No +operator for list since index isn't a constant but rather a linear operation
    
    list<char>::iterator where = find(lc.begin(), lc.end(), 'j');   //if not found will return second argument
    where = find(lc.begin(), lc.end(), 'Q');    //If none they will return iterator at location of size [lc.end()]
    if(where ==lc.end()){
        cout << "We failed /n" << endl;
    }
    
    
    char* where2 = find(arr, arr+len, 'j');     //instead of iterator since it's just contiguous array we return a pointer of location
    where2 = find(arr, arr + len, 'Q'); //If none they will index return where string stops [arr + len]
    
    
    vector<int> vi{1,3,5,7,4,5,6};
    
    //lambda function
    vector<int>::iterator where3 = find_if(vi.begin(), vi.end(), isEven);
    where3 =find_if(vi.begin(), vi.end(), [](int n){return n%2 == 0;} );
    where3 = myfind_if(vi.begin(), vi.end(), [](int n){return n%2 == 0;});
    
    IsEven testEven;    //functor
    if (testEven(42)) cout << "42 is even \n";
    where3 = myfind_if(vi.begin(), vi.end(), testEven);
    where3 = myfind_if(vi.begin(), vi.end(), IsEven());
    where3 = myfind_if(vi.begin(), vi.end(), isMultiple(17));
    //function is only looking for a function with one element
}
