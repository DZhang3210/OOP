//
//  main.cpp
//  Linked_List
//
//  Created by David Zhang on 5/6/22.
//

#include <iostream>
#include<vector>
using namespace std;


struct Node{
    int data;
    Node* next;
    
    Node(int val, Node* next = nullptr):data(val), next(next){}
};

class LinkedList{
    friend ostream& operator<< (ostream& os, const LinkedList& rhs){
        os << "Vector: ";
        for(Node* cursor = rhs.header->next; cursor != nullptr; cursor = cursor->next){
            os << cursor -> data << ", ";
        }
        return os;
    }
public:
    class Iterator{
    private:
        Node* node;
        friend bool operator == (const Iterator& lhs, const Iterator& rhs){
            return lhs.node == rhs.node;
        }
        friend bool operator != (const Iterator& lhs, const Iterator& rhs){
            return !(lhs == rhs);
        }
    
    public:
        Iterator(Node* input): node(input){}
        
        Iterator& operator ++(){
            node= node->next;
            return *this;
        }
        Node& operator* (){
            return *node;
        }
    };
    class Const_Iterator{
    private:
        const Node* node;
        friend bool operator == (const Const_Iterator& lhs, const Const_Iterator& rhs){
            return lhs.node == rhs.node;
        }
        friend bool operator != (const Const_Iterator& lhs, const Const_Iterator& rhs){
            return !(lhs == rhs);
        }
    
    public:
        Const_Iterator(Node* input):node(input) {}
        
        Const_Iterator& operator ++(){
            node= node->next;
            return *this;
        }
        const Node& operator* () const{
            return *node;
        }
    };
    LinkedList(vector<int>& list):header(new Node(0)){
        int cursor = 0;
        Node* nodes = header;
        while(cursor < list.size()){
            nodes->next = new Node(list[cursor]);
            nodes = nodes-> next;
            cursor += 1;
        }
    }
    Iterator begin(){
        return Iterator(header);
    }
    Iterator end(){
        return Iterator(nullptr);
    }
    Const_Iterator begin() const{
        return Const_Iterator(header);
    }
    Const_Iterator end() const{
        return Const_Iterator(nullptr);
    }
    
    
private:
    Node* header;
    
};

int main() {
    vector<int> list{1,2,3,4,5,6,7,8,9};
    
    const LinkedList l(list);
    
    for (const Node& node: l){
        cout << node.data << " ";
    }
    
    return 0;
}
