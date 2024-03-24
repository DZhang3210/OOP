//
//  main.cpp
//  4-13-22
//
//  Created by David Zhang on 4/13/22.
//

#include <iostream>

struct Node{
    Node(int data = 0, Node* next = nullptr): data(data), next(next){}
    int data;
    Node* next;
};

int listLength(const Node* headPtr){\
    int count = 0;
    while(headPtr != nullptr){
        ++ count;
        headPtr = headPtr->next;
    }
    return count;
}
void listAddHead(Node*& headPtr, int data){
    //Create Node for data
    Node* node = new Node(data, headPtr);   //make the new node point ot the old first node
    
    //make the headPtr point to the new node
    headPtr = node;
    
    //headptr = new Node(data, headPtr);
}

void listAddTail(Node*& headPtr, int data){
    if(headPtr == nullptr){
        headPtr = new Node(data);
    }else{
        Node* last = headPtr;
        while(last-> next != nullptr){
            last = last-> next;
        }
        last-> next = new Node(data);
    }
}
void listRemoveHead(Node*& headPtr){
    if(headPtr != nullptr){
    Node* old = headPtr;
    headPtr = headPtr-> next;
    delete old;
    }
}

int main() {
    Node* myList = nullptr;
    listAddHead(myList, 17);
}
