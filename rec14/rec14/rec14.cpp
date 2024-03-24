#include <iostream>
using namespace std;

struct TNode {
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};


//Node* newList(Node* left, Node* right);

int findMax(TNode* root){
    if(root ->left == nullptr && root-> right == nullptr){
        return root->data;
    }
    else if(root -> left == nullptr){
        return max(root->data, findMax(root->right));
    }
    else if(root->right == nullptr){
        return max(root->data, findMax(root->left));
    }
    else{
        return max(root->data, max(findMax(root->left), findMax(root->right)));
    }
}
int Max(TNode* root) {
    if(root == nullptr){
        throw bad_function_call();
    }
    return findMax(root);
}


bool evenOnes(int n){
    if(n == 0)
        return true;
    if(n == 1)
        return false;
    if(n%2 == 0)
        return evenOnes(n/2);
    else
        return !evenOnes(n/2);
}

bool palindrome(char* s, int len){
    if(len == 0 || len == 1)
        return true;
    
    if(*s == *(s+len-1))
        return palindrome(s+1, len-2);
    return false;
}

int towers(int n, char start, char middle, char target){
    if(n == 0){
        return 0;
    }
    return 1 + towers (n-1, start, target, middle)
    + towers(n-1, start, target, middle);
}

//0:c
//1:c
//2:acbcc
//3:acbcc
//4:aacbccbacbccc
//5:aacbccbacbccc
//6:aacbccbacbccc
//7:aacbccbacbccc
//8:aaacbccbacbcccbaacbccbacbcccc
//9:aaacbccbacbcccbaacbccbacbcccc
//10:aaacbccbacbcccbaacbccbacbcccc


void mystery(int n) {
   if (n > 1) {
      cout << 'a';
      mystery(n/2);
      cout << 'b';
      mystery(n/2);
   }
   cout << 'c';
}

struct node{
    int data;
    node* next;
    node(int data, node* next = nullptr):data(data), next(next){}
};

node* newList(node* left, node* right){
    if(left == nullptr && right == nullptr){
        return nullptr;
    }if(right == nullptr){
        return new node(left->data, newList(left->next, right));
    }if(left == nullptr){
        return new node(right->data, newList(left, right->next));
    }else{
        return new node(left->data + right->data, newList(left->next, right->next));
    }
    
//    return Node()
}

int main() {
    
    node a2(1), b2(2,&a2), c2(3,&b2), d2(4,&c2);
    node a1(8), b1(3,&a1), c1(7, &b1);
    node* a3 = newList(&d2, &c1);
    node* cursor = a3;
    while(cursor != nullptr){
        cout << cursor->data << endl;
        cursor = cursor->next;
    }
    
    
    mystery(0);
    cout << endl;
    mystery(1);
    cout << endl;
    mystery(2);
    cout << endl;
    mystery(3);
    cout << endl;
    mystery(4);
    cout << endl;
    mystery(5);
    cout << endl;
    mystery(6);
    cout << endl;
    mystery(7);
    cout << endl;
    mystery(8);
    cout << endl;
    mystery(9);
    cout << endl;
    mystery(10);
    cout << endl;
    
    cout << evenOnes(4) << endl;
    cout << evenOnes(7) << endl;
    cout << evenOnes(2) << endl;
    cout << evenOnes(3) << endl;
    cout << evenOnes(5) << endl;
    
    char s[] = "raceca";
    if (palindrome(s, 7)) {cout << "Yes \n";}
    else{cout << "No \n";}
    
    
  TNode a(1), b(2), c(4), d(8, &a, &b), e(64, &c), f(32, &d, &e);
    try{
        cout << Max(nullptr) << endl;
    }catch(const exception& c){
        cout << c.what() << endl;
    }

    

    cout << towers(1, 'a', 'b', 'c') << endl;
    cout <<towers(2, 'a', 'b', 'c') << endl;
    cout <<towers(3, 'a', 'b', 'c') << endl;
    cout <<towers(4, 'a', 'b', 'c') << endl;
    cout <<towers(5, 'a', 'b', 'c') << endl;
    cout <<towers(6, 'a', 'b', 'c') << endl;
    cout <<towers(7, 'a', 'b', 'c') << endl;
    cout <<towers(8, 'a', 'b', 'c') << endl;
    cout <<towers(9, 'a', 'b', 'c') << endl;
    cout <<towers(10, 'a', 'b', 'c') << endl;
}

  
  
