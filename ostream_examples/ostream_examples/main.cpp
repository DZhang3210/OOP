//
//  main.cpp
//  ostream_examples
//
//  Created by David Zhang on 2/11/22.
//

#include <iostream>

int main(int argc, const char * argv[]) {
//Most basic scenario with seperate subclasses
/*
         class Transaction{
             friend ostream& operator << (ostream& os, const Transaction& rhs);
             //True = deposit
             //False = withdrawl
         public:
             Transaction(const string& type, int change): type(type), accountChange(change){}
         private:
             string type;
             int accountChange;
         };
         ostream& operator << (ostream& os, const Transaction& rhs){
             os << rhs.type << " " << rhs.accountChange << endl;
             return os;
         }
         class account {
             friend ostream& operator << (ostream& os, const account& rhs);
         public:
             account (const string& name, int number): name(name), accountNumber(number){balance = 0;}
             int getNumber() const {return accountNumber;}
             void modifyBalance(int change){balance+=change;}
             int getBalance() const {return balance;}
             void addToList (const string& type, int amount){ transactionList.emplace_back(type, amount);
             }
         private:
             vector<Transaction> transactionList;
             string name;
             int balance;
             int accountNumber;
         };
         ostream& operator << (ostream& os, const account& rhs){
             os << rhs.name << " "  << rhs.accountNumber << ": " << endl;
             for (const Transaction& transaction: rhs.transactionList)
             os <<  transaction;
             return os;
         }
*/

    //Class with subclass within the public domain
/*
         class PublicAccount{
         friend ostream& operator << (ostream& os, const PublicAccount& rhs);
         public:
             PublicAccount(const string& name, int number): name(name), accountNumber(number){balance = 0;}
             
             class transaction{
             friend ostream& operator << (ostream& os, const transaction& rhs);
             public:
                 transaction(const string& type, int change): type(type), accountChange(change){}
             private:
                 string type;
                 int accountChange;
             };
         private:
             vector<transaction> transactionList;
             string name;
             int balance;
             int accountNumber;
         };
         ostream& operator << (ostream& os, const PublicAccount& rhs){
             for (const PublicAccount::transaction& transaction: rhs.transactionList){
             os <<  transaction;
             }
             return os;
         }
         ostream& operator << (ostream& os, const PublicAccount::transaction& rhs){
             os << "Type: "<<rhs.type << " accountChange: " << rhs.accountChange << endl;
             return os;
             
         }
 */
    //ostream with subclass witihn the private variable
/*
         class PrivateAccount{
             friend ostream& operator << (ostream& os, const PrivateAccount& rhs);
         public:
             PrivateAccount(const string& name, int number): name(name), accountNumber(number){balance = 0;}
         private:
             //Transaction uppercase
             class transaction{
             friend ostream& operator << (ostream& os, const transaction& rhs);
             public:
                 transaction(const string& type, int change): type(type), accountChange(change){}
             private:
                 string type;
                 int accountChange;
             };
             vector<transaction> transactionList;
             string name;
             int balance;
             int accountNumber;
             
             friend ostream& operator << (ostream& os, const PrivateAccount::transaction& rhs);
         };
         ostream& operator << (ostream& os, const PrivateAccount::transaction& rhs){
             cout << rhs.type << " " << rhs.accountChange << endl;
             return os;
         }
         ostream& operator << (ostream& os, const PrivateAccount& rhs){
             cout << rhs.name << " " << rhs.accountNumber<< endl;
             for (const PrivateAccount::transaction& transaction: rhs.transactionList){
                 cout << transaction;
         }
             return os;
         }
 */
    return 0;
}
