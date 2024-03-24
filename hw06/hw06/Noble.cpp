//
//  Noble.cpp
//  hw06
//
//  Created by David Zhang on 3/16/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Noble.h"
#include "Warrior.h"

using namespace std;
namespace WarriorCraft{
    void Noble::hire(Warrior& warrior){
        if(!dead && warrior.getStrength() != 0 && warrior.isHired() == false){
            warrior.hire(this);
            battlePower += warrior.getStrength();
            fighters.push_back(&warrior);
        }else{
            cerr << "Attempt to hire " << warrior.getName() << " by " << name << " failed" << endl;
        }
    }
    Noble::Noble(const string& n): name(n), battlePower(0), dead(false){}

    void Noble::fire(Warrior& fighter){
        fighter.fire();
        cout << "You don't work for me anymore " << fighter.getName() << "! -- " << name << endl;
        removeWarrior(fighter);
    }
    void Noble::removeWarrior (Warrior& fighter){
        if(battlePower == 0)
            return;
        for(size_t i =0;i < fighters.size(); i++){
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
                break;
            }
        }
    }
    void Noble::death (){
        dead = true;
        battlePower = 0;
        for(Warrior* warrior: fighters){
            warrior->reduceStrength(1);
        }
    }
    const string& Noble::getName() const{return name;}

    void Noble::battle (Noble& noble){
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

    Noble* findNoble (const vector<Noble*>& list,const string& name){
        for (Noble* noble : list){
            if(noble->getName() == name)
                return noble;
        }
        return nullptr;
    }
    ostream& operator << (ostream& os, const Noble& rhs){
        //print out for all nobles
        cout << rhs.name << " has an army of " << rhs.fighters.size() << endl;
        for (const Warrior* warrior: rhs.fighters){
            cout << "\t" <<  *warrior << endl;
        }
        return os;
    }
}
