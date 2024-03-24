// rec13_test.cpp

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

void printList(const list<int>& b){
    list<int>::const_iterator start = b.begin();
    while(start != b.end()){
        cout << *start << endl;
        start ++;
    }
}
void printListFor(const list<int>& b){
    for(int val: b){
        cout << val << endl;
    }
}
void printAuto(const list<int>& b){
    auto start = b.begin();
    while(start != b.end()){
        cout <<*start<< endl;
        start++;
        start++;
    }
}
list<int>::const_iterator findItem(const list<int>& c, int j){
    for (list<int>::const_iterator b = c.begin(); b != c.end(); b++){
        if(*b == j)
            return b;
    }
    return c.end();
}
auto findItemAuto(const list<int>& c, int j){
    auto b = c.begin();
    while(b!= c.end() && *b != j){
        b++;
    }return b;
}
bool isEven(int n){return n%2 ==0;}

struct evenNumber{
    bool operator() (int n) const {return n%2 == 0;}
};

list<int>::iterator ourFind(list<int>::iterator start, list<int>::iterator stop, int val){
    cout << "This is my function" << endl;
    while(start != stop){
        if(*start == val)
            return start;
        start++;
    }
    return stop;
}
template<typename T,typename U>
T ourFind(T start, T stop, U val){
    cout << "In the template" << endl;
    while(start != stop){
        if(*start == val)
            return start;
        start++;
    }
    return stop;
}

int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> lc {4,3,2,1};
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> fl(lc.begin(), lc.end());
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(lc.begin(), lc.end());
    for (int i: lc){cout << i << " ";}
    cout << "\n=======\n";

    // 4. print every other element of the vector. ASSUMING the length is odd.
    cout << "Task 4:\n";
    for (size_t i = 0; i < lc.size(); i+=2)
    {cout << lc[i] << " ";}

    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    //    for (size_t i = 0; i < fl.size(); i+=2)
    //    {cout << fl[i] << " ";}
    //    cout << endl;
    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator b = lc.begin(); b != lc.end(); b+=2){
        cout << *b << " ";
    }
    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for(list<int>::iterator b = fl.begin(); b != fl.end(); ++++b){
        cout << *b << " ";
    }
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    fl.sort();
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    printList(fl);
    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    printListFor(fl);
    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    printAuto(fl);
    cout << "=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    auto where1 = findItem(fl, 1);
    auto where2 = findItem(fl, 17);
    if(where1 == fl.end()){
        cout << "not Found";
    }else{cout << "Found" << *where1;}
    if(where2 == fl.end()){
        cout << "not Found";
    }else{cout << "Found" << *where2;}
    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    auto where3 = findItemAuto(fl, 1);
    auto where4 = findItemAuto(fl, 17);
    if(where3 == fl.end()){
        cout << "not Found";
    }else{cout << "Found" << *where3;}
    if(where4 == fl.end()){
        cout << "not Found";
    }else{cout << "Found" << *where4;}
    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    list<int>::iterator where5 = find(fl.begin(), fl.end(), 1);
    list<int>::iterator where6 = find(fl.begin(), fl.end(), 17);
    if(where5 == fl.end()){
        cout << "not Found";
    }else{cout << "Found" << *where5;}
    if(where6 == fl.end()){
        cout << "not Found";
    }else{cout << "Found" << *where6;}
    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    list<int>::iterator j= find_if(fl.begin(), fl.end(), isEven);
    if(j == fl.end()){
        cout << "not Found";
    }else{cout << "Found" << *j;}
    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";
    list<int>::iterator k= find_if(fl.begin(), fl.end(), evenNumber());
    if(k == fl.end()){
        cout << "not Found";
    }else{cout << "Found" << *k;}
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    list<int>::iterator l= find_if(fl.begin(), fl.end(), [](int n) {return n%2 == 0;});
    if(l == fl.end()){
        cout << "not Found";
    }else{cout << "Found" << *l;}
    
    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int* b = new int [fl.size()];
    copy(fl.begin(), fl.end(), b);
    for(size_t i = 0; i < fl.size(); i++){
        cout << *(b +i) << endl;
    }
    delete [] b;
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    list<int>::iterator where7 = ourFind(fl.begin(), fl.end(), 1);
    list<int>::iterator where8 = ourFind(fl.begin(),fl.end(), 9);
    if(where7 == fl.end()){
        cout << "Not Found" << endl;
    }else{
        cout << "Found at " << *where7 << endl;
    }
    if(where8 == fl.end()){
        cout << "Not Found" << endl;
    }else{
        cout << "Found at " << *where8 << endl;
    }
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    vector<int>::iterator where9 = ourFind(lc.begin(), lc.end(), 1);
    vector<int>::iterator where10 = ourFind(lc.begin(),lc.end(), 9);
    if(where9 == lc.end()){
        cout << "Not Found" << endl;
    }else{
        cout << "Found at " << *where9 << endl;
    }
    if(where10 == lc.end()){
        cout << "Not Found" << endl;
    }else{
        cout << "Found at " << *where10 << endl;
    }
    
    list<int>::iterator where11 = ourFind(fl.begin(), fl.end(), 1);
    list<int>::iterator where12 = ourFind(fl.begin(),fl.end(), 9);
    if(where11 == fl.end()){
        cout << "Not Found" << endl;
    }else{
        cout << "Found at " << *where11 << endl;
    }
    if(where12 == fl.end()){
        cout << "Not Found" << endl;
    }else{
        cout << "Found at " << *where12 << endl;
    }
    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    ifstream read("pooh-nopunc.txt");
    if(!read){
        cout << "Not availible"<< endl;
    }
    vector<string> uniqueWords;
    string filler;
    
    while(read >> filler){
        //cout << "Element" << endl;
        if(find(uniqueWords.begin(), uniqueWords.end(), filler) == uniqueWords.end()){
            uniqueWords.push_back(filler);
        }
    }
    read.close();
    cout << uniqueWords.size() << endl;
    
    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    set<string> uq;
    ifstream read1("pooh-nopunc.txt");
    while(read1 >> filler){
        //cout << "Element" << endl;
        if(find(uq.begin(), uq.end(), filler) == uq.end()){
            uq.insert(filler);
        }
    }
    
    read1.close();
    cout << uq.size() << endl;
    
    cout << "=======\n";

    // 23. Word co-occurence using 
    cout << "Task 23:\n";
    map<string, vector<int>> wordMap;
    ifstream read2("pooh-nopunc.txt");
    int i = 0;
    while(read2 >> filler){
        //cout << "Element" << endl;
        wordMap[filler].push_back(i);
    i++;
    }read2.close();
    for(auto& c: wordMap){
        cout << c.first << ": ";
        for(int b: c.second){
            cout << b << " ";
        }
    }
    cout << endl;
    
    cout << "=======\n";
}
