//
//  main.cpp
//  hw05
//
//  Created by David Zhang on 2/23/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Warrior {
    friend ostream& operator << (ostream&os, const Warrior& rhs);
    
public:
    Warrior(const string& n, double str): name(n), strength(str), allegiance(false){}
    //Reduces strength based on percentage
    void reduceStrength(double percentage){
        strength -= percentage*strength;
    }
    //Checks if can be hired otherwise change allegiance to true and confirm true
    const bool getAllegiance() const {return allegiance;}
    //Modifier method for allegiance variable
    void hire (){allegiance  = true;}
    void fire(){allegiance = false;}
    //A couple getter methods
    const double getStrength () const {return strength;}
    const string& getName () const { return name;}
    
private:
    double strength;
    string name;
    bool allegiance;
};

ostream& operator << (ostream& os, const Warrior& rhs){
    os << rhs.name << ": " << rhs.strength;
    return os;
}

class Noble {
    friend ostream& operator << (ostream& os, const Noble& rhs);
public:
    Noble(const string& n): name(n), battlePower(0), dead(false){}
    //Hiring checks for other employer, otherwise updates battle strength and adds warrior to vector
    void hire(Warrior& warrior){
        if(!dead && warrior.getStrength() != 0 && warrior.getAllegiance() != true){
            warrior.hire();
            battlePower += warrior.getStrength();
            fighters.push_back(&warrior);
        }else{
            cerr << "Attempt to hire " << warrior.getName() << " by " << name << " failed" << endl;
        }
    }
    //Fires a warrior
    void fire(Warrior& fighter){
        //First checks for Warrior in vector
        for(size_t i =0;i < fighters.size(); i++){
            if(fighters[i]->getStrength() == 0)
                break;
            //if the warrior is found ... then break
            if(fighters[i] == &fighter){
                //Reduce battleStrength & remove allegiance
                battlePower -= fighter.getStrength();
                fighter.fire();
                //Shifts all elements down by 1 and then pop last element
                for(size_t k = i; k < fighters.size() -1; k++){
                    fighters[k] = fighters[k + 1];
                }
                fighters.pop_back();
                cout << "You don't work for me anymore " << fighter.getName() << "! -- " << name << endl;
                break;
            }
        }
    }
    //helper method to streamline battle method
    void death (){
        dead = true;
        battlePower = 0;
        for(Warrior* warrior: fighters){
            warrior->reduceStrength(1);
        }
    }
    const string& getName() const{return name;}
    
    void battle (Noble& noble){
        cout << name << " battles " << noble.name << endl;
        
        //Test for edge cases of automatic win
        if(noble.dead && dead)
            cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
        else if(noble.dead)
            cout << "He's dead, " << name << endl;
        else if(dead)
            cout << "He's dead, " << noble.name << endl;
        
        else{
            //Automatically calculate ratio for battle power
            double ratio;
            if(battlePower == 0 || noble.battlePower == 0)
                ratio = 0;
            else
                ratio = min(battlePower, noble.battlePower)/max(battlePower, noble.battlePower);
            
            if(noble.battlePower > battlePower){
                death();
                cout << noble.name << " defeats " << name << endl;
                noble.battlePower = noble.battlePower - noble.battlePower*ratio;
                for(Warrior* warrior: noble.fighters){
                    warrior->reduceStrength(ratio);
                }
            }else if (noble.battlePower < battlePower){
                noble.death();
                cout << name << " defeats " << noble.name << endl;
                battlePower = battlePower - battlePower*ratio;
                for(Warrior* warrior: fighters){
                    (*warrior).reduceStrength(ratio);
                }
            }else{ //if they have equal battlePower
                noble.death();
                death();
                cout << "Mutual Annihlation: " << name << " and " << noble.name << " die at each others hands " << endl;
            }}

    }
private:
    vector<Warrior*> fighters;
    double battlePower;
    string name;
    bool dead;
};
ostream& operator << (ostream& os, const Noble& rhs){
    //print out for all nobles
    cout << rhs.name << " has an army of " << rhs.fighters.size() << endl;
    for (const Warrior* warrior: rhs.fighters){
        cout << "\t" <<  *warrior << endl;
    }
    return os;
}
//Helper method for finding Warrior based on name
Warrior* findWarrior (const vector<Warrior*>& list,const string& name){
    for (Warrior* fighter : list){
        if((*fighter).getName() == name)
            return fighter;
    }
    return nullptr;
}
//Helper method for finding noble based on name
Noble* findNoble (const vector<Noble*>& list,const string& name){
    for (Noble* noble : list){
        if((*noble).getName() == name)
            return noble;
    }
    return nullptr;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    ifstream read("nobleWarriors.txt");
    if(!read){
        cerr << "ERROR: NO TEXT FILE FOUND" << endl;
        exit(0);
    }
    string str;
    string name1;
    string name2;
    int strength;
    vector<Noble*> nobles;
    vector<Warrior*> warriors;
    while(read >> str){
        if(str == "Hire"){
            read >> name1 >> name2;
            Noble* noble = findNoble(nobles, name1);
            if(noble == nullptr){
                cerr << "Attempting to hire using unknown Noble: " << name1 << endl;
                continue;}
            Warrior* fighter = findWarrior(warriors,name2);
            if(fighter == nullptr){
                cerr << "Attempting to hire using unknown Warrior: " << name2 << endl;
                continue;
            }
            noble->hire(*fighter);
        }
        else if (str == "Noble"){
            read >> name1;
            nobles.push_back(new Noble(name1));
        }
        else if(str == "Warrior"){
            read >> name1 >> strength;
            warriors.push_back(new Warrior(name1, strength));
        }
        else if(str == "Fire"){
            read >> name1 >> name2;
            Noble* noble = findNoble(nobles, name1);
            if(!noble){
                cerr << "Attempted to fire Unknown Noble" << endl;
                continue;
            }
            Warrior* fighter =findWarrior(warriors, name2);
            if(!fighter){
                cerr << "Attempted to Fire Unknown Warrior" << endl;
                continue;
            }
            noble->fire(*fighter);
        }
        else if(str == "Status"){
            cout << "Status: " << endl <<"===" << endl << "Nobles: "<< endl;
            if(nobles.size() == 0)
                cout << "NONE" << endl;
            else{
                for(const Noble* noble : nobles){
                    cout << *noble;
                }
            }
            cout << endl << "Unemployed Warriors: " << endl;
            //First check and display employed warriors
            //Set flag, and if flag == true then display none
            bool none = true;
            for (const Warrior* warrior: warriors){
                if(warrior->getAllegiance() == false){
                    cout << "\t" << *warrior << endl;
                    none = false;
                }
            }if(none) cout << "NONE" << endl;
        }
        else if(str == "Battle"){
            read >> name1 >> name2;
            
            Noble* noble1 = findNoble(nobles, name1);
            if(noble1 == nullptr){
                cerr << "No Noble Found" << endl;
                continue;
            }
            Noble* noble2 = findNoble(nobles, name2);
            if(noble2 == nullptr){
                cerr << "No Noble Found" << endl;
                continue;
            }
            noble1->battle(*noble2);
        }
        
        else if(str == "Clear"){
            for(const Noble* noble: nobles){
                cout << "deleting Noble " << noble->getName() << endl;
                delete noble;
            }nobles.clear();
            for(const Warrior* warrior: warriors){
                cout << "deleting Warrior " << warrior->getName() << endl;
                delete warrior;
            }warriors.clear();
        }
    }
    read.close();
    return 0;
}
