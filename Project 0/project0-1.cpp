// Jordan scott 
#include <iostream> 
#include <fstream>
using namespace std;

int main ()
{
    // simple print statemnt 
    cout<< " hello world ";
    fstream myfile;
    string myArray[100];
    int m = 0;
    myfile.open("Text.txt");
    while(!myfile.eof())
    {
        myfile>>myArray[m];
        m++;
    }
    myfile.close();
    for (int i=0; i<100; i++)
    {
        cout<< " "<<myArray[i]<< " ";
    }
    return 0;
}