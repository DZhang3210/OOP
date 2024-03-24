/*
  rec05-start.cpp
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Section{
friend ostream& operator << (ostream& os, const Section& rhs);
public:
    Section(const string& title, const string& day, int time ):name(title), timeSlot(day, time){}
    Section(const Section& section):name(section.name), timeSlot(section.timeSlot){
        for (const StudentRecord* reco: section.list){
            list.push_back(new StudentRecord(*reco));
        }
    }
    ~Section(){
        cout << "Section " << name << " is being deleted" << endl;
        for (StudentRecord* reco: list){
            cout << "Deleting " << reco->getName() << endl;
            delete reco;
        }
    }
    void addStudent(const string& name){
        list.push_back(new StudentRecord(name));
    }
    void addGrade(const string& name, int value, int index){
        for (StudentRecord* reco: list){
            if(reco->getName() == name){
                reco->modifyGrade(value, index);
                break;
            }
        }
    }
private:
    class TimeSlot{
    friend ostream& operator << (ostream& os, const TimeSlot& rhs);
    public:
        TimeSlot(const string& day, int hour):day(day), hour(hour){}
    private:
        string day;
        int hour;
    };
    friend ostream& operator << (ostream& os, const Section::TimeSlot& rhs);

    
class StudentRecord{
    friend ostream& operator << (ostream& os, const StudentRecord& rhs);
    public:
        StudentRecord(const string& name):name(name), grades (14, -1){}
        /*StudentRecord(const StudentRecord& copy):name(copy.name),grades(copy.grades){
            for(int i: copy.grades){
                grades.push_back(i);
            }
        }*/
        const string& getName() const {return name;}
        void modifyGrade(int value, int index){
            grades[index - 1] = value;
        }
    private:
        string name;
        vector<int> grades;
    };
    friend ostream& operator << (ostream& os, const Section::StudentRecord& rhs);
    
    
    string name;
    vector<StudentRecord*> list;
    TimeSlot timeSlot;
};
ostream& operator << (ostream& os, const Section::TimeSlot& rhs){
    os << "Time slot: [Day: " << rhs.day << ", Start time: " << rhs.hour << "] ";
    return os;
}

ostream& operator << (ostream& os, const Section::StudentRecord& rhs){
    os << "Name: " << rhs.name <<", Grades: ";
    for (int i: rhs.grades){
        cout << i << " ";
    }cout << endl;
    return os;
}

ostream& operator << (ostream& os, const Section& rhs){
    os << "Section: " << rhs.name << ", " << rhs.timeSlot;
    cout<< endl;
    for (const Section::StudentRecord* record: rhs.list){
        cout << (*record);
    }if(rhs.list.size() == 0)
        cout <<"NONE"<< endl;
    return os;
}

class LabWorker {
    friend ostream& operator << (ostream& os, const LabWorker& rhs);
public:
    LabWorker(const string& title):name(title), section(nullptr){}
    void addSection(Section& sec){
        section = &sec;
    }void addGrade(const string& name, int value, int index){
        section->addGrade(name, value, index);
    }
    
private:
    Section* section;
    string name;
};
ostream& operator << (ostream& os, const LabWorker& rhs){
    if(rhs.section)
        os << rhs.name << " has Section: "  << *(rhs.section) << endl;
    else
        os << rhs.name << " doesn't have a section" << endl;
    return os;
}


// Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {

    cout << "Test 1: Defining a section\n";

    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;
    //FINISHED
    
    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;
    //Finished
    
    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe << endl;
    //FINISHED
    
    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe << endl;

    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    cout << jane << endl;

    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    cout << moe << endl;

    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    cout << moe << endl;

    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";

    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works:\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";

} // main
