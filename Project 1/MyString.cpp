// Jordan Scott 
// CST_201 
// MyString Project 
// 
#include <iostream> 
#include <fstream>
#include "MyString.h"
using namespace std;

int main ()
{
    MyString bob1(" Hello World ");
    MyString bob2 (" Ninja World");
    cout << bob1.Length(2)<< endl;
    cout << bob1.Length(2)<< endl;
    bob1.toString();
    bob2.toString();
    cout<< bob1.compareTo(bob2)<< endl;
   cout<<  bob1.equals(bob2)<< endl;
   cout<< bob1.get(2)<< endl;
   cout<< bob2.get(2)<< endl;
   //cout<< bob1.toUpper()<< endl;
   //cout<< bob1.toLower()<< endl;
   //cout<< bob2.toUpper()<< endl;
   //cout<< bob2.toLower()<< endl;
   bob1.substring(1);
   int indexOfBob = bob1.indexOf(bob1);
    if (indexOfBob != -1)
    {
        cout << "Their is a character was found at index: "<<indexOfBob;
    }
    else 
    {
        cout << "Nothing is there ";
    }
     bob1.concat(bob2);

    return 0;
}