//
//  heapsnstacks.cpp
//  Exam1_Review
//
//  Created by David Zhang on 2/27/22.
//

#include "heapsnstacks.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void addToVector(vector<int*>& list, int times){
    int i = 0;
    while (i < times){
        int k = i;
        list.push_back(&k); //will normally create a copy to store in vector but with pointers will only push adress and keep repeating on stack
        i++;
    }
}
void addToVectorDiff(vector<int*>& list, int times)
{
    int i = 0;
    while (i < times){
        list.push_back(new int(i)); //This should now create a bunch of different items on the heap
        i++;
    }
}
void addToVectorPrimative(vector<int*>& list)
{
    int i = 13;
    list.push_back(&i); //normally creates copy
    //Leaves scope and open up spot then
    //We want this to exist outside of scope so we need to put this on the heap
}

/*int main(){
    vector<int*> list;

    addToVector(list, 4);
    addToVectorDiff(list, 4);
    addToVectorPrimative(list);
    addToVectorPrimative(list);
    addToVectorPrimative(list);
    
    for(const int* i: list){
        cout << i << endl;
    }
}*/
