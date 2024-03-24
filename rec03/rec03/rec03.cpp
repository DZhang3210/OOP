/*
  rec03_start.cpp
 */

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task 1
// Define an Account struct

struct Account {
    int money;
    string name;
};

// Task 2
// Define an Account class (use a different name than in Task 1)
class BankAccount {
    friend ostream& operator << (ostream& os, const BankAccount& rhs);
public:
    BankAccount(int m, string n): money(m), name(n){}
    int getMoney() const { return money;}
    const string& getName() const{return name;}
private:
    int money;
    string name;
};
ostream& operator << (ostream& os, const BankAccount& rhs){
    //os << "Money: " << rhs.getMoney() << " Name: " << rhs.getName() << endl;
    os << "Money: " << rhs.money << " Name: " << rhs.name << endl;
    return os;
}

// Task 3
// Define an Account (use a different name than in Task 1&2) and
// Transaction classes

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
// Task 4
// Define an Account with a nested public Transaction class
// (use different names than in the previous Tasks)

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

// Task 5
// Define an Account with a nested private Transaction class
// (use different names than in the previous Tasks)

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

int main() {

    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n";
    ifstream read ("accounts.txt");
    vector<Account> list;
    string name;
    int money;
    
    while(read>> name >> money){
        Account account;
        account.name = name;
        account.money = money;
        list.push_back(account);
    }
    read.close();
    for(const Account& account: list){
        cout << "Name: " << account.name << " Money: " << account.money << endl;
    }
    
    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";
    
    list.clear();
    read.open("accounts.txt");
    while(read>> name >> money){
        Account account {money, name};
        list.push_back(account);
    }
    read.close();
    for(const Account& account: list){
        cout << "Name: " << account.name << " Money: " << account.money << endl;
    }
    //==================================
    // Task 2: account as class

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";
    
    vector<BankAccount> bankList;
    read.open("accounts.txt");
    while(read>> name >> money){
        ;
        BankAccount account (money, name);
        bankList.push_back(account);
    }
    read.close();

    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";
    
    for(const BankAccount& account: bankList){
        cout << account;
    }
    
    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";

    for(const BankAccount& account: bankList){
        cout << account;
    }
    
    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";
    bankList.clear();
    read.open("accounts.txt");
    while(read>> name >> money){
    bankList.push_back(
    BankAccount(money,name));
    }
    read.close();
    
    cout << "\nTask2e:\n";
    cout << "Filling vector of class objects, using emplace_back:\n";

    bankList.clear();
    read.open("accounts.txt");
    while(read>> name >> money){
        bankList.emplace_back(money,name);
    }
    read.close();
    for(const BankAccount& account: bankList){
        cout << account;
    }
    
    cout << "==============\n";
    cout << "\nTask 3:\nAccounts and Transaction:\n";
    

    ifstream reading ("transactions.txt");
    string type;
    int amount;
    int number;
    string readIn;
    vector<account> accounts;
    while (reading >> readIn){
        if(readIn == "Account"){
            reading >> name >> number;
            accounts.emplace_back(account(name, number));
        }
        else if(readIn == "Deposit"){
            reading >> number >> amount;
            for(account& single: accounts){
                if(single.getNumber() == number){
                  single.modifyBalance(amount);
                  single.addToList("Deposit", amount);
                    break;
                }
            }
        }
        else if(readIn == "Withdraw"){
            reading >> number >> amount;
            for(account& single: accounts){
                    if(single.getNumber() == number){
                        if((single.getBalance() - amount) < 0){
                            cerr << "Account #" << single.getNumber() << " has insufficient funds for withdrawl of " << amount << endl;
                            break;
                        }
                    single.modifyBalance(-1* amount);
                    single.addToList("Withdraw", amount);
                    break;
                }
            }
        }
    }
    for(const account& account: accounts){
        cout << account;
    }
    cout << "==============\n";
    cout << "\nTask 4:\nTransaction nested in public section of Account:\n";
    
    for(const account& account: accounts){
        cout << account;
    }
    cout << "==============\n";
    cout << "\nTask 5:\nTransaction nested in private section of Account:\n";

    for(const account& account: accounts){
        cout << account;
    }
}
