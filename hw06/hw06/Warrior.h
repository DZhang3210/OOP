//
//  WARRIOR.h
//  hw06
//
//  Created by David Zhang on 3/16/22.
//

#ifndef Warrior_h
#define Warrior_h
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
namespace WarriorCraft{
    class Noble;

    class Warrior {
        friend std::ostream& operator << (std::ostream&os, const Warrior& rhs);
        
    public:
        Warrior(const std::string& n, double str);
        //Reduces strength based on percentage
        void reduceStrength(double percentage);
        //Checks if can be hired otherwise change allegiance to true and confirm true
        //Modifier method for allegiance variable
        void hire (Noble* noble);
        void fire();
        //A couple getter methods
        const double getStrength () const;
        const std::string& getName () const;
        void runaway ();
        bool isHired () const;
    private:
        Noble* hiringNoble;
        double strength;
        std::string name;
    };
}

#endif /* Warrior_h */
