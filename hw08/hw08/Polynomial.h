//
//  Polynomial.h
//  hw08
//
//  Created by David Zhang on 4/30/22.
//
#include <iostream>
#include<vector>

class Polynomial{
    
    struct Node{
        int val;
        Node* next;
        
        Node(int val = 0, Node* next = nullptr):val(val), next(next){}
    };
    
    friend std::ostream& operator<< (std::ostream& os, const Polynomial& rhs);
    friend bool operator == (const Polynomial& lhs, const Polynomial& rhs);
    friend bool operator != (const Polynomial& lhs, const Polynomial& rhs);
public:
    
    Polynomial();
    Polynomial(std::vector<int> list);
    Polynomial (const Polynomial& copy);
    ~Polynomial();
    Polynomial& operator= (const Polynomial& copy);
    
    int evaluate(const int input);
    
    //Helper Function
    void insertAhead();
    Polynomial& operator +=(const Polynomial& rhs);
    void clear();
    
private:
    Node* header;
    size_t degree;
};

Polynomial operator+ (const Polynomial& lhs, const Polynomial& rhs);

#ifndef Polynomial_h
#define Polynomial_h


#endif /* Polynomial_h */
