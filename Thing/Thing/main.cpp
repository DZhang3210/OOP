//
//  main.cpp
//  Thing
//
//  Created by David Zhang on 4/26/22.
//

#include <iostream>
using namespace std;

const int NUM = 5;

const int INIT_BALANCE = 200;
class Account{
public:
    Account():balance(INIT_BALANCE){}
    
    virtual void display_balance(){
        cout << "Balance is " << balance;
    }
    
protected:
    int get_balance() const {return balance;}
private:
    int balance;
};

class CheckingAccount: public Account{
    
public:
    virtual void display_balance() const override{
        cout << "Checking balance is " << get_balance();
    }
};

int main() {
    Account acct;
    CheckingAccount ca;
    acct = ca;
    acct.display_balance();
    
//    int val = 7;
//    int* arr = new int[NUM];
//    for(int i = 0; i < NUM; ++i){
//        arr[i] = val + i;
//    }
//
//    int* ptr_p = arr + NUM - 2;
//    int* ptr_q = ptr_p + 1;
//    cout << "X: " << *ptr_q << endl;
//    *ptr_p = val;
//    ++ptr_p;
//    cout << "Y: " << *ptr_p << endl;
    
}
