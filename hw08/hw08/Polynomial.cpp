//
//  Polynomial.cpp
//  hw08
//
//  Created by David Zhang on 4/23/22.
//
using namespace std;
#include "Polynomial.h"

//Default Constructor creates one element of 0
Polynomial::Polynomial():header(new Node(0, new Node(0))), degree(0){}

//Constructor for Vector
Polynomial::Polynomial(vector<int> list):header(new Node(0, new Node(0))){
//Check for zeroes ahead in vector and start where first non-zero, otherwise go to last element
    int start = 0;
    while(start < list.size() - 1 && list[start] == 0){
        start++;
    }
    degree = list.size()-start - 1;
//Insert Elements ahead for degree discreptancy
    for(size_t i = 0; i < degree; i++){
        insertAhead();
    }
    
    Node* cursor = header->next;
    while(cursor != nullptr){
        cursor->val = list[start];
        cursor = cursor->next;
        start++;
    }
}
Polynomial::Polynomial(const Polynomial& copy):header(new Node(0, new Node(0))), degree(copy.degree){
//Create Empty Polynomial of same degree
    for(size_t i = 0; i < degree; i++){
        insertAhead();
    }

//Iterate through copy list and copy all values
    Node* leftCursor = header->next;
    Node* rightCursor = copy.header->next;
    while(rightCursor != nullptr){
        leftCursor->val = rightCursor->val;
        leftCursor = leftCursor->next;
        rightCursor = rightCursor->next;
    }
}

//Helper method to remove all elements
void Polynomial::clear(){
    Node* cursor = header->next -> next;
    Node* hold = cursor;
    while(cursor != nullptr){
        cursor = cursor->next;
        delete hold;
        hold = cursor;
    }
    //Reset header->next to null and degree
    header->next = nullptr;
    degree = 0;
}

//
Polynomial::~Polynomial(){
    //Remove all elements and header
    clear();
    delete header;
}

Polynomial& Polynomial::operator=(const Polynomial& copy){
    if(this != &copy){
        //Remove any excess and reset
        clear();
        degree = copy.degree;
        
        //Create Empty Polynomial of same degree
        for(Node* i = copy.header->next; i != nullptr; i = i->next){
            insertAhead();
        }
        
        //Iterate for copy until end
        Node* leftCursor = header->next;
        Node* rightCursor = copy.header->next;
        while(leftCursor != nullptr){
            leftCursor->val = rightCursor->val;
            leftCursor = leftCursor->next;
            rightCursor = rightCursor->next;
        }
    }
    return *this;
}

//Output operator
std::ostream& operator << (std::ostream& os, const Polynomial& rhs){
    
    //Create cursor variable and degree for displaying
    Polynomial::Node* cursor = rhs.header->next;
    size_t degree = rhs.degree;
    
    //Loop until everything finished
    while(cursor != nullptr){
        //cursor val is not 0 except if first element which indicates it's a zero polynomial
        if(cursor->val != 0 || cursor == rhs.header->next){
            //Placing +/- dependent on value except at beginning
            if(cursor != rhs.header->next)
                os <<((cursor->val > 0) ? " + ": " - ");
            //If at beginning then check for negative
            else if (cursor->val < 0){
                os << "-";
                //If negative is also < -1 add value
            }
            //Val is 1 then ignore this, or if degree 0 then display regardless
            if(abs(cursor->val) != 1 || degree == 0)
                os << abs(cursor->val);
            //If degree is not 0 then display x
            if(degree > 0){
                os<< "x";
                //If degree > 1 then show sign
                if(degree > 1)
                    os<<"^"<<degree;
                }
        }
        cursor = cursor->next;
        degree--;
    }
    return os;
}

//== operator
bool operator ==(const Polynomial& lhs, const Polynomial& rhs){
    //Test for simple edge case
    if(lhs.degree != rhs.degree)
        return false;
    
    //Iterate across both, check for nonequality, else return true
    
    Polynomial::Node* leftCursor = lhs.header -> next;
    Polynomial::Node* rightCursor = rhs.header->next;
    
    while(leftCursor != nullptr){
        if(leftCursor->val != rightCursor-> val)
            return false;
        leftCursor = leftCursor->next;
        rightCursor = rightCursor->next;
    }
    return true;
}

bool operator != (const Polynomial& lhs, const Polynomial& rhs){
    return !(lhs == rhs);
}



//Helper Method for +
void Polynomial::insertAhead(){
    Node* node = new Node(0, header->next);
    //reset header to place node as next first element
    header->next = node;
}


Polynomial& Polynomial::operator +=(const Polynomial& rhs){
    
    //Establish Points
    Node* leftCursor = header->next;
    Node* rightCursor = rhs.header->next;
    
    //Adjust Linked List Size
    //Compare is Bigger
    if(rhs.degree > degree){
        while(rhs.degree > degree){
            insertAhead();
            degree++;
            leftCursor = header->next;
        }
    }
    //Compare is Smaller
    else if(rhs.degree < degree){
        size_t leftDegree = degree;
        while(leftDegree > rhs.degree){
            leftDegree--;
            leftCursor = leftCursor->next;
        }
    }
    //Now that both pointers are placed equally, iterate over both and add rhs to former
    while(leftCursor != nullptr){
        leftCursor->val += rightCursor->val;
        //Check to see if greatest degree is 0 and thus must be deleted
        if(leftCursor == header->next && degree != 0 && leftCursor-> val == 0){
            Node* cursor = leftCursor;
            header->next = leftCursor->next;
            leftCursor = leftCursor->next;
            rightCursor = rightCursor->next;
            degree--;
            delete cursor;
        }else{
            leftCursor = leftCursor->next;
            rightCursor = rightCursor->next;
        }
    }
    return *this;
}

//+operator using copy and overloaded +=operator
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs){
    Polynomial copy(lhs);
    copy += rhs;
    return copy;
}

//Returns Sum using Horner Method
int Polynomial::evaluate(const int input){
    Node* cursor = header->next;
    int sum = cursor -> val;
    while(cursor -> next != nullptr){
        sum*= input;
        cursor = cursor->next;
        sum += cursor->val;
    }
    return sum;
}
