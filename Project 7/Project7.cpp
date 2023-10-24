// Jordan Scott
// CST-201
// Project 7
// Hash Table 
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Hashing.h"
using namespace std;

int hashing (string val)
{
    int total =0;
    for(int i=0; i < val.size(); i++)
    {
       total += val[i];
    }
    int redbeans = total;
    int rice = redbeans%23;
    return rice;
}

int main ()
{
    // Creating hash table
    string french;
    Hashing<string>nola[23]; 
    int index;
    ifstream file("/Users/bignola/Downloads/AOT2.txt"); 
    while (file>> french)
    {
        index = hashing(french);
        nola[index].insert(french);
       
        
    } 
    // display 
    for (int i = 0; i < 23; i++) 
    {
        cout << i << ": ";
        nola[i].display();
        cout<<endl;
    }
    // Search 
    string Mardi; 
    int gras;
    cout << "What word would you like to find?  " ;
    cin >> Mardi;
    gras = hashing(Mardi);
    nola[gras].search(Mardi);


}