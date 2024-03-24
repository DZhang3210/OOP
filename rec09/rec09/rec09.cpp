//
//  main.cpp
//  rec09
//
//  Created by David Zhang on 4/1/22.
//

#include <iostream>
#include<vector>

using namespace std;


class PrintedMaterials{
    /*friend ostream& operator << (ostream& os, const PrintedMaterials& rhs){
        os << rhs.numberOfPages << endl;
        return os;
    }*/
public:
    PrintedMaterials(int i):numberOfPages(i){}
    virtual void displayNumPages ( ) const =0;
    /*virtual void displayNumPages() const { cout << numberOfPages << endl;};*/
private:
    unsigned numberOfPages;
};

void PrintedMaterials::displayNumPages() const{
    cout << numberOfPages << endl;
}

class Books : public PrintedMaterials{
public:
    Books(int i):PrintedMaterials::PrintedMaterials(i){}
    virtual void displayNumPages () const override{
        cout << "Books" << endl;
        PrintedMaterials::displayNumPages();}
private:
};

class Magazines: public PrintedMaterials{
public:
    Magazines(int i):PrintedMaterials::PrintedMaterials(i){}
    virtual void displayNumPages() const override{
        cout << "Magazines" << endl;
        PrintedMaterials::displayNumPages();
    }
private:
};

class TextBook : public PrintedMaterials{
public:
    TextBook(int i, int b): PrintedMaterials::PrintedMaterials(i), numOfIndexPages(b){};
    
    virtual void displayNumPages() const override{
        cout << "TextBook" << endl;
        PrintedMaterials::displayNumPages();
        cout << numOfIndexPages << endl;
    };
private:
    unsigned numOfIndexPages;
};

void displayNumberOfPages(PrintedMaterials& input){
    input.displayNumPages();
}



int main() {
    //PrintedMaterials p;
    Books b (2343);
    Magazines m (767);
    TextBook t(9764, 8933);
    
    //displayNumberOfPages(t);
    
    //t.displayNumPages();
    
    /*vector <PrintedMaterials> list;
    list.push_back(t);
    list[0].displayNumPages();*/
    
    
    vector <PrintedMaterials*> list;
    list.push_back(&t);
    list.push_back(&m);
    list.push_back(&b);
    for (const PrintedMaterials* p: list){
        p -> displayNumPages();
    }
    
    /*PrintedMaterials* y = &t;
    y->displayNumPages();*/

}
