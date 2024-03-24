//
//  main.cpp
//  rec02
//
//  Created by David Zhang on 2/4/22.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


struct Chemical{
    vector<string> names;
    int C = 0;
    int H = 0;
};
void sortChemicals(vector<Chemical>& list);
void printChemical(const Chemical& chemical);
void printAllChemicals(const vector<Chemical>& list);
void readFile (ifstream& jab);
void insertInfo (const string& name,int C, int H, vector<Chemical>& list);
size_t findDuplicate (int C, int H, const vector<Chemical>& list);
void insertChemical(ifstream& jab, vector<Chemical>& list);



int main() {

    //Declare Variables
    vector <Chemical> list;
    ifstream jab;
    readFile(jab);  // Read file until valid is presented
    insertChemical(jab, list);  //Inserts all chemicals in text file into vector
    sortChemicals(list);    //Sorts all chemicals in Vectors by C then H
    printAllChemicals(list);    //Prints all availible Chemicals
    
    return 0;
}


//BubbleSort to sort the chemicals vector
void sortChemicals (vector<Chemical>& list){
    for(size_t i = 0; i < list.size(); i++){
        for(size_t j = 0; j < list.size() -1 ; j++){

            if (list[j].C > list[j+1].C){
                Chemical temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }else if (list[j].C == list[j+1].C && list[j].H > list[j+1].H){
                Chemical temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

//Print a single chemical object
void printChemical (const Chemical& chemical){
    cout << "C" << chemical.C <<"H" << chemical.H << " ";
    for (const string& name: chemical.names){
        cout << name << " ";
    }cout << endl;
}
 
//Print all chemical objects in vector<Chemical>
void printAllChemicals(const vector<Chemical>& list){
    for (const Chemical& chemical: list){
        printChemical(chemical);
    }
}

//ReadFile unitl valid fileName presented
void readFile(ifstream& jab){
    string fileName;
    do{
        cout << "Type a valid fileName" << endl;
        cin >> fileName;
        jab.open(fileName);
    }while(!jab);
}

//Finds Duplicate in vector for same C & H
size_t findDuplicate (int C, int H, vector<Chemical>& list){
    size_t i = 0;
    while(i < list.size()){
        if(list[i].C == C && list[i].H == H){
            return i;
        }
        i++;
    }return list.size();
}

//Check if chemical is in list of availible
void insertInfo (const string& name, int C, int H, vector<Chemical>& list){
    size_t i = findDuplicate(C, H, list);
    if(i != list.size())
        list[i].names.push_back(name);
    else
    {
        Chemical chemical;
        chemical.names.push_back(name);
        chemical.C = C;
        chemical.H = H;
        list.push_back(chemical);
    }
}

//Inserts all chemicals from text file to vector
void insertChemical(ifstream& jab, vector<Chemical>& list){
    string word;
    char character;
    int C;
    int H;
 while (jab >> word >> character >> C >> character >> H){
     //Read data for chemical
     insertInfo(word, C, H, list);
}
}
