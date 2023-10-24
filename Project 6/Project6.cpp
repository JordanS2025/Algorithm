// Jordan Scott 
// CST-201 
// Project 6 
// Binary Search Tree 
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "BST.h"
using namespace std;

int main ()
{
    // Binat search tree 

    BST<string> nola;
    string nolaS;
    string poboy;
    string beans;
    ifstream file("/Users/bignola/Library/Mobile Documents/com~apple~TextEdit/Documents/AOT.txt"); 
   cout<<endl;

    while (file>> nolaS)
    {
        nola.Newinsert(nolaS); 
    }
   nola.inOrder();
   cout<<endl;
  cout<< nolaS<<endl;
  while (poboy != "-1")
  {
    cout<< "Enter string, enter -1 to quit:"<< endl;
    cin >>poboy;
    cout << nola.searchHelp(poboy)<<endl;
  }
  cout<< "Enter string to remove:"<<endl;
  cin >> beans;
  nola.deleteVal2(beans);
cout<<endl;
  nola.inOrder();
  cout<<endl;
  return 0;


}