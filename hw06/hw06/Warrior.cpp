//
//  Warrior.cpp
//  hw06
//
//  Created by David Zhang on 3/16/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Warrior.h"
#include "Noble.h"

using namespace std;
namespace WarriorCraft{
    Warrior::Warrior(const string& n, double str): name(n), strength(str), hiringNoble(nullptr){}
    void Warrior::reduceStrength(double percentage){
        strength -= percentage*strength;
    }
    void Warrior::hire (Noble* noble){hiringNoble = noble;}
    void Warrior::fire(){hiringNoble = nullptr;}
    const double Warrior::getStrength () const {return strength;}
    const string& Warrior::getName () const { return name;}


    void Warrior::runaway(){
        cout << name << " flees in terror, abandoning his lord, " << hiringNoble->getName() << endl;
        hiringNoble->removeWarrior(*this);
    }
    
    bool Warrior::isHired() const{
        if(hiringNoble == nullptr){return false;}
        return true;
    }

    Warrior* findWarrior (const vector<Warrior*>& list,const string& name){
        for (Warrior* fighter : list){
            if (fighter->getName() == name)
                return fighter;
        }
        return nullptr;
    }

    ostream& operator << (ostream& os, const Warrior& rhs){
        os << rhs.name << ": " << rhs.strength;
        return os;
    }
}
