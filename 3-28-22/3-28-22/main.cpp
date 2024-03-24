
/*
  1.inheritance.cpp
  Section Base

  Code reuse, principle of substitutability, polymorphism
  Constructors, "inheriting" constructors.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pet {
public:
    
    Pet(const string& name): name(name){}
    //virtual = polymorphism
    //virtual essentially permits this method to be overloaded by methods within other subclasses
    //virtual does not effect inheritence, inheritence is per the subclass, but overloading/polymorphism must be specifically brought in
    virtual void eat() { cout << "eating" << endl; }
    
    virtual ~Pet(){}// ignore for now
private:
    string name;
};

class Cat : public Pet {
public:
    
    //Cat(const string& name): name(name){}
    //Cat(const string& name) : Pet(name){}
    using Pet::Pet;     //uses all methods form Pet called Pet, a.k.a all constructors
    
    //void eat() {cout << "Cat eating" << endl;}
    void eat(){
        cout << "Cat ";
        Pet::eat();
    }
    void purr () {cout << "purrrrr";}
    
private:
    string name;
};

class Slug : public Pet {
public:
    //Slug(): Pet() {}    //implicit constructor
    //Calls default constructor for pet implicitly but we don't have any default constructor or a constructor which takes no arguments
    Slug() : Pet("slugname"){}
};

class Roach : public Pet { };

//void someFunc(Pet aPet)
//Prepared to figure out if we use the method of Pet or subclass of Cat, Slug, Roach a.k.a inputted classes, so we need to prepare the compiler for that


void someFunc(Pet& aPet) {
    cout << "someFunc: ";
    aPet.eat();
}

//der = base    FAILS, since reassigning a new base will make everything go wonky, the subclass is built on top of the base, and so we can't go swapping the base
//base = der    WORKS,although this will work the der class will get cut off due to limited space
//derPtr = &base    WORKS, principle of substituability, derived can do anything that base does
//basePtr = &derived    FAILS, opposite principle of substitutability, base cannot do anyhing that derived does
//derPtr = basePtr  FAILS, expecting derived but getting base NOT ALL FUNCTIONALITY MAINTAINED
//basePtr = derPtr  WORKS, expecting base and getting derived ALL FUNCTIONALITY MAINTAINED

int main() {
    Pet peeve("Peeve");
    peeve.eat();
    someFunc(peeve);

    Cat felix("Felix");
    felix.eat();      // code reuse
    someFunc(felix);  // principle of substitutability. Barbara Liskov
    
    Slug sluggo("sluggo");
    Roach archie("archie");
    
    //vector<Pet> menagerie;
    vector<Pet*> menagerie;
    //push_back is only making a copy of the size pet, resulting in the slicing error yet again
    //This is the unique problem which comes with substitutability
    //menagerie.push_back(sluggo);
    menagerie.push_back(&sluggo);
    //menagerie.push_back(archie);
    menagerie.push_back(&archie);
    //menagerie.push_back(felix);
    menagerie.push_back(&felix);
    //menagerie.push_back(peeve);
    menagerie.push_back(&peeve);

    for (size_t i =0; i< menagerie.size(); i++){
        menagerie[i]->eat();
    }
    
    
    //Example of the principle of substitutability
    /*Cat* derivedPtr = &peeve;
    derivedPtr -> purr();*/
    
    //slugs can purr??
/*  Pet* basePtr = &sluggo;         //substitutability
    Cat* derivedPtr = basePtr;      //violates substitutability, NOT ALL FUNCTIONS MAINTAINED
    derivedPtr -> purr();*/
}
