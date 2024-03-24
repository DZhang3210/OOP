////
////  Things.cpp
////  scope
////
////  Created by David Zhang on 4/17/22.
////
//
///*
//  testNobleWarrior.cpp
//  John Sterling
//  Association: Noble - Warrior
//  Test code for hw04
// */
//
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//// Your Noble and Warrior classes should go here.
//
//class Warrior {
//    friend ostream& operator << (ostream&os, const Warrior& rhs);
//    
//public:
//    Warrior(const string& n, double str): name(n), strength(str){allegiance = false;}
//    //Reduces strength based on percentage
//    void reduceStrength(double percentage){
//        strength -= percentage*strength;
//    }
//    //Checks if can be hired otherwise change allegiance to true and confirm true
//    bool hire (){
//        if(allegiance)
//            return false;
//        allegiance = true;
//        return true;
//    }
//    //Modifier method for allegiance variable
//    void fire(){allegiance = false;}
//    //A couple getter methods
//    double getStrength () const {return strength;}
//    const string& getName () const { return name;}
//    
//private:
//    double strength;
//    string name;
//    bool allegiance;
//};
//
//ostream& operator << (ostream& os, const Warrior& rhs){
//    os << rhs.name << ": " << rhs.strength;
//    return os;
//}
//
//class Noble {
//    friend ostream& operator << (ostream& os, const Noble& rhs);
//public:
//    Noble(const string& n): name(n){battlePower = 0; dead = false;}
//    //Hiring checks for other employer, otherwise updates battle strength and adds warrior to vector
//    void hire(Warrior& warrior){
//        if(warrior.hire() && !dead){
//            battlePower += warrior.getStrength();
//            fighters.push_back(&warrior);
//        }else{
//            cerr << "Warrior is unable to be contracted" << endl;
//        }
//    }
//    //Fires a warrior
//    void fire(Warrior& fighter){
//        //First checks for Warrior in vector
//        for(size_t i =0;i < fighters.size(); i++){
//            //if the warrior is found ... then break
//            if(fighters[i] == &fighter){
//                //Reduce battleStrength & remove allegiance
//                battlePower -= fighter.getStrength();
//                fighter.fire();
//                //Shifts all elements down by 1 and then pop last element
//                for(size_t k = i; k < fighters.size() -1; k++){
//                    fighters[k] = fighters[k + 1];
//                }
//                fighters.pop_back();
//                cout << "You don't work for me anymore " << fighter.getName() << "! -- " << name << endl;
//                break;
//            }
//        }
//    }
//    //helper method to streamline battle method
//    void death (){
//        dead = true;
//        battlePower = 0;
//        for(Warrior* warrior: fighters){
//            (*warrior).reduceStrength(1);
//        }
//    }
//    
//    void battle (Noble& noble){
//        cout << name << " battles " << noble.name << endl;
//        
//        //Test for edge cases of automatic win
//        if(noble.dead && dead)
//            cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
//        else if(noble.dead)
//            cout << "He's dead, " << name << endl;
//        else if(dead)
//            cout << "He's dead, " << noble.name << endl;
//        
//        else{
//            //Automatically calculate ratio for battle power
//            double ratio = min(battlePower, noble.battlePower)/max(battlePower, noble.battlePower);
//            
//            if(noble.battlePower > battlePower){
//                death();
//                cout << noble.name << " defeats " << name << endl;
//                noble.battlePower = noble.battlePower - noble.battlePower*ratio;
//                for(Warrior* warrior: noble.fighters){
//                    (*warrior).reduceStrength(ratio);
//                }
//            }else if (noble.battlePower < battlePower){
//                noble.death();
//                cout << name << " defeats " << noble.name << endl;
//                battlePower = battlePower - battlePower*ratio;
//                for(Warrior* warrior: fighters){
//                    (*warrior).reduceStrength(ratio);
//                }
//            }else{ //if they have equal battlePower
//                noble.death();
//                death();
//                cout << "Mutual Annihlation: " << name << " and " << noble.name << " die at each others hands " << endl;
//            }}
//
//    }
//private:
//    vector<Warrior*> fighters;
//    double battlePower;
//    string name;
//    bool dead;
//};
//ostream& operator << (ostream& os, const Noble& rhs){
//    //print out for all nobles
//    cout << rhs.name << " has an army of " << rhs.fighters.size() << endl;
//    for (const Warrior* warrior: rhs.fighters){
//        cout << "\t" <<  *warrior << endl;
//    }
//    return os;
//}
//
//int main() {
//    
//    Noble art("King Arthur");
//    Noble lance("Lancelot du Lac");
//    Noble jim("Jim");
//    Noble linus("Linus Torvalds");
//    Noble billie("Bill Gates");
//    
//    Warrior cheetah("Tarzan", 10);
//    Warrior wizard("Merlin", 15);
//    Warrior theGovernator("Conan", 12);
//    Warrior nimoy("Spock", 15);
//    Warrior lawless("Xena", 20);
//    Warrior mrGreen("Hulk", 8);
//    Warrior dylan("Hercules", 3);
//    
//    jim.hire(nimoy);
//    lance.hire(theGovernator);
//    art.hire(wizard);
//    lance.hire(dylan);
//    linus.hire(lawless);
//    billie.hire(mrGreen);
//    art.hire(cheetah);
//    
//    cout << "==========\n"
//         << "Status before all battles, etc.\n";
//    cout << jim << endl;
//    cout << lance << endl;
//    cout << art << endl;
//    cout << linus << endl;
//    cout << billie << endl;
//    cout << "==========\n";
//    
//    art.fire(cheetah);
//    cout << art << endl;
//    
//    art.battle(lance);
//    jim.battle(lance);
//    linus.battle(billie);
//    billie.battle(lance);
//
//    cout << "==========\n"
//         << "Status after all battles, etc.\n";
//    cout << jim << endl;
//    cout << lance << endl;
//    cout << art << endl;
//    cout << linus << endl;
//    cout << billie << endl;
//    cout << "==========\n";
//    
//}
