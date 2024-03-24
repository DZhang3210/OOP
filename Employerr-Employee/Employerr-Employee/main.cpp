////
////  main.cpp
////  Employerr-Employee
////
////  Created by David Zhang on 4/15/22.
////
//
//#include <iostream>
//using namespace std;
//#include<string>
//#include<vector>
//class Employee;
//class Employer{
//friend ostream& operator << (ostream& os, const Employer& rhs){
//        cout << rhs.name << endl;
//        for (Employee* em: rhs.list){
//            cout << em;
//        }
//        return os;
//    }
//private:
//    string name;
//    vector<Employee*> list;
//public:
//    Employer(const string& n): name(n){}
//    Employer (const Employer& rhs):Employer(rhs.name){}
//    ~Employer();
//    void hire(Employee* em);
//    void fire(Employee* em);
//};
//
//class Employee {
//    friend ostream& operator << (ostream& os, const Employee& rhs){
//        cout << "Employee " << rhs.name << endl;
//        return os;
//    }
//private:
//    string name;
//    Employer* caretaker;
//public:
//    Employee (const string& n): name(n), caretaker(nullptr){ cout << "created" << endl;}
//    const Employer* getEmployer() const {return caretaker;}
//    void quit();
//    void changeEmployer(Employer* em) {caretaker = em;}
//    ~Employee(){
//        cout << "Automatic Out" << endl;
//    }
////    ~Employee(){
////        if(caretaker != nullptr){
////            delete this;
////        }
////    }
//};
//
//Employer::~Employer(){
//    for (Employee* worker: list){
//        cout << "Not ";
//        delete worker;
//    }list.clear();
//}
//
//void Employer::hire(Employee* em){
//    if(em->getEmployer() != nullptr) { cerr << "Couldn't hire" << endl; }
//    else{
//        list.push_back(em);
//        em->changeEmployer(this);
//    }
//}
//
//void Employer::fire(Employee* em){
//    for(size_t i = 0; i< list.size(); i++){
//        if(em == list[i]){
//            em -> changeEmployer(nullptr);
//            while(i < list.size()-1 ){
//                list[i]= list[i+1];
//                list.pop_back();
//            }
//            return true;
//        }
//    }
//    return false;
//}
//
//void Employee::quit(){
//    
//    if(caretaker != nullptr){
//        caretaker -> fire(this);
//    }
//}
//
//
//
//
//int main(int argc, const char * argv[]) {
//    Employee* em = new Employee("em");
//    Employee Tim("Tim");
//    Employee Had("Had");
//    Employer Jim ("Jim");
//    Jim.hire(em);
////    Jim.hire(em);
////    Jim.fire(Tim);
//    return 0;
//}
