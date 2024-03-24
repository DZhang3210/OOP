//
//  NOBLE.h
//  hw06
//
//  Created by David Zhang on 3/16/22.
//

#ifndef Noble_h
#define Noble_h
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
namespace WarriorCraft{
    class Warrior;

    class Noble {
        
        friend std::ostream& operator << (std::ostream& os, const Noble& rhs);
    public:
        Noble(const std::string& n);
        //Hiring checks for other employer, otherwise updates battle strength and adds warrior to vector
        void hire(Warrior& warrior);
        //Fires a warrior
        void fire(Warrior& fighter);
        //helper method to streamline battle method
        void death ();
        const std::string& getName() const;
        void battle (Noble& noble);
        void removeWarrior (Warrior& fighter);
    private:
        std::vector<Warrior*> fighters;
        double battlePower;
        std::string name;
        bool dead;
    };
}
#endif /* Noble_h */
