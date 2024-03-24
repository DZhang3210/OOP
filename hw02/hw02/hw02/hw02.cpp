//
//  main.cpp
//  hw02
//
//  Created by David Zhang on 2/3/22.
//

#include <iostream>
#include <fstream>
#include<string>
#include<vector>
using namespace std;

struct Warrior{
    string name;
    int strength;
};

void decideFight(vector<Warrior>& list, const string& warrior1, const string& warrior2);
void printWarriors(const vector<Warrior>& list);
void insertWarrior(vector<Warrior>& list, const Warrior& warrior);

int main(int argc, const char * argv[]) {
    
    //Find Files
    ifstream readFile ("warriors.txt");
    if(!readFile){
        cerr << "No File Found" << endl;
        exit(1);
    }
    
    //Couple initalized variables
    string word;
    vector<Warrior> list;
   
    //Read through entire text file
    while (readFile >> word)
        //Case if Warrior keyword
        if(word == "Warrior"){
            Warrior warrior;
            readFile >> warrior.name >> warrior.strength;
            insertWarrior(list, warrior);
        }
        //Case if Status keyword
        else if(word == "Status")
            printWarriors(list);
        //Case if Battle keyword
        else{
            string warrior1;
            string warrior2;
            readFile >> warrior1 >> warrior2;
            decideFight(list, warrior1, warrior2);
        }
    return 0;
}

//Insert a Warrior while making sure no duplicate
void insertWarrior(vector<Warrior>& list, const Warrior& warrior){
    //Check for a duplicate
    int i = 0;
    while (i < list.size()){
        if(list[i].name == warrior.name)
        {
            cerr << "DUPLICATE WARRIOR ERROR" << endl;
            return;
        } i++;
    }
    //If no duplicate than insert another warrior
    if(i == list.size())
        list.push_back(warrior);
}

//Decide a fight between warrior1 and warrior2
void decideFight(vector<Warrior>& list, const string& warrior1, const string& warrior2){
    size_t index1 = list.size();
    size_t index2 = list.size();
    
    //Find the index given the name or if not return error and terminate method
    for (size_t i = 0; i < list.size(); i++){
        if(list[i].name == warrior1)
            index1 = i;
        if(list[i].name == warrior2)
            index2 = i;
    }
    //If either warrior is not found with index then terminate
    if(index1 == list.size() || index2 == list.size()){
        cerr << "UNDEFINED WARRIOR ERROR" << endl;
        return;
    }
    
    //Declare the battle and contestants
    cout << list[index1].name << " battles " << list[index2].name << endl;
    
    //If both are dead...
    if(list[index1].strength == 0 && list[index2].strength == 0)
        cout << "OH, NO! They're both dead! Yuck!" << endl;
    //If either warrior is dead
    else if(list[index1].strength == 0)
        cout << "He's dead " << list[index2].name << endl;
    else if (list[index2].strength == 0)
        cout << "He's dead " << list[index1].name << endl;
    //If Warrior1 & Warrior 2 are equal in strength...
    else if(list[index1].strength == list[index2].strength){
        cout << "Mutual Annihlation: " << list[index1].name << " and " << list[index2].name << " die at each other's hands" << endl;
        list[index1].strength = 0;
        list[index2].strength = 0;
    }//If warrior1 or Warrior2 is stronger than...
    else {
        if(list[index1].strength < list[index2].strength){
            cout << list[index2].name << " defeats " << list[index1].name << endl;
            list[index2].strength -= list[index1].strength;
            list[index1].strength = 0;
        }else{
            cout << list[index1].name << " defeats " << list[index2].name << endl;
            list[index1].strength -= list[index2].strength;
            list[index2].strength = 0;
        }
    }
}

//Prints # of Warriors and their stats
void printWarriors(const vector<Warrior>& list){
    cout << "There are: " << list.size() << " warriors" << endl;
    for (const Warrior& warrior: list){
        cout << "Warrior: " << warrior.name << ", strength: " << warrior.strength << endl;
    }
}
