/*
  rec12-test.cpp

  starter code for developing and testing a doubly linked list class
*/

#include <cstdlib>
#include <iostream>
using namespace std;

class List{
    friend ostream& operator << (ostream& os, const List& rhs){
        os << "Linked List of size " << rhs.s << endl;
        if(rhs.s == 0) {
            return os;
        }
        Node* cursor = rhs.header -> next;
        while (cursor != rhs.trailer){
            //cout << cursor << endl;
            cout << cursor -> val <<  " ";;
            cursor = cursor -> next;
        }
        
        return os;
    }
    struct Node{
        Node* before;
        Node* next;
        int val;
        
        Node(Node* m = nullptr, Node* b = nullptr, int v = 0): before(m), next(b), val(v){}
        
    };
public:
    List(const List& copy):s(0){
        trailer = new Node();
        header = new Node(nullptr, trailer);
        trailer->before = header;
        
        Node* cursor = copy.header->next;
        while(cursor != copy.trailer){
            cout << cursor-> val << endl;
            push_back(cursor->val);
            cursor = cursor->next;
        }
    }
    List& operator=(const List& copy){
        if(this != &copy){
            s = 0;
            clear();
            
            Node* cursor = copy.header->next;
            while(cursor != copy.trailer){
                push_back(cursor->val);
                cursor = cursor-> next;
            }
        }
        return *this;
    }
    
    ~ List(){
        clear();
        delete header;
        delete trailer;
    }
    
    
    class iterator{
        friend class List;
        friend bool operator != (const iterator& lhs, const iterator& rhs){
            return lhs.where != rhs.where;
        }
        friend bool operator == (const iterator& lhs, const iterator& rhs){
            return lhs.where == rhs.where;
        }
        
    private:
        Node* where;
    public:
        iterator(Node* where): where(where){}
        
        iterator& operator ++(){
            where = where -> next;
            return *this;
        }
        iterator& operator --(){
            where = where -> before;
            return *this;
        }
        
        int& operator*() const{
            return where->val;
        }
    };
    
//    for (iterator i = begin(); i != end(); i++){
//        int& val = *i;
//    }
//~~~
//    for (int i: list)   // vector <int>
//                        //List <Nodes>
                          //i your refering to is *i IMPLICITLY
        
    
    List():s(0){
        trailer = new Node();
        header = new Node(nullptr, trailer);
        trailer->before = header;
    }
    
    iterator begin(){
        return iterator(header->next);
    }
    iterator end(){
        return iterator(trailer);
    }
    
    void push_back(int data){
        Node* node = new Node(trailer->before, trailer, data);
        trailer->before->next = node;
        trailer->before = node;
        s++;
    }
    void pop_back(){
        if(s == 0){
            cerr << "Empty List" << endl;
            return;
        }
        
        Node* node  =trailer->before->before;
        delete trailer->before;
        node -> next = trailer;
        trailer -> before = node;
        s--;
    }
    void push_front(int val){
        s++;
        Node* node = new Node(header, header->next,val);
        header ->next -> before = node;
        header -> next = node;
        //node->before = header;
    }
    void pop_front(){
        if(s == 0){
            cerr << "Empty list error" << endl;
            return;
        }
        s--;
        Node* node = header->next;
        header->next = header->next -> next;
        header->next->before = header;
        delete node;
    }
    
    int& front(){
        if(s == 0){
            cerr << "No availible front" << endl;
        }
        return header->next->val;
    }
    const int front() const{
        if(s == 0){
            cerr << "No availible front" << endl;
            return -7;
        }
        return header->next->val;
    }
    int& back(){
        if(s == 0){
            cerr << "No availible front" << endl;
        }
        return trailer->before->val;
    }
    const int back() const{
        if(s == 0){
            cerr << "No availible front" << endl;
            return -7;
        }
        return trailer->before->val;
    }
    
    size_t size() const {return s;}
    
    void clear(){
        Node* cursor = header -> next -> next;
        s = 0;
        while (cursor != nullptr){
            delete cursor->before;
            cursor = cursor->next;
        }
        header->next = trailer;
        trailer->before = header;
    }
    
    const int operator[] (size_t index)const{
        if(index >= s){
            cerr << "index larger than array" << endl;
            return -9;
        }
        Node* cursor = header -> next;
        for (size_t i = 0; i < index; i++){
            cursor = cursor-> next;
        }
        return cursor->val;
    }
    int& operator[] (size_t index){
        if(index >= s){
            cerr << "index larger than array" << endl;
        }
        Node* cursor = header -> next;
        for (size_t i = 0; i < index; i++){
            cursor = cursor-> next;
        }
        return cursor->val;
    }
    
    iterator insert (const iterator& iter, int insert){
        Node* data = new Node(nullptr, nullptr, insert);
        s++;
        Node* insertBefore = iter.where;
        data->before = insertBefore->before;
        insertBefore -> before->next = data;
        insertBefore -> before = data;
        data->next = insertBefore;
        
        return iterator(data);
        //iter.where ->before -> next = data
    }
    iterator erase(iterator iter){
        Node* data = iter.where;
        Node* after = data -> next;
        s--;
        data-> before -> next = data -> next;
        data-> next -> before = data-> before;
        delete data;
        
        return iterator(after);
    }
    
private:

    
    size_t s;
    Node* header;
    Node* trailer;
};

// Task 1
void printListInfo(const List& myList) {
        cout << "size: " << myList.size()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList){
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList){
    theList.front() = 17;
    theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}

int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    
    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    printListInfo(myList);
    cout << "===================\n";
//
//    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";
//
//    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
         << "the data in the third item in the list\n"
         << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);
//
//
//    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";
//
//    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";
//
//    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";
//
//    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
}
