// Jordan Scott 
// CST-201
// Project 2 : Single Link list 
#include <iostream> 
#include "SinglyLinkedList.h"
using namespace std;

int main ()
{
    SinglyLinkedList<int> nola;
    SinglyLinkedList<int> nola2;
    nola.insert(2);
    nola.insert(9);
    nola.insert(1);
    nola.insert(6);
    nola.insert(55);
    nola.display();
    cout<<endl;
     nola.front();
     nola.back();
    cout<<endl;
    cout << nola.size()<< endl;
    nola.empty();
     nola.reverse();
    nola.display();
     cout<<endl;
    nola.pop_front();
    nola.pop_back();
    nola.display();
    cout<<endl;
     nola2.insert(2);
     nola2.insert(7);
    nola2.insert(8);
    nola2.insert(10);
    nola2.display();
    cout<<endl;
    nola.merge(nola2);
    nola.display();
    cout<< endl;
    return 0;
}