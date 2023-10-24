// Jordan Scott
// CST-201
// Project 7
// Hash Table 
#ifndef Hashing_H
#define Hashing_H
#include <iostream>
using namespace std;
template<class T>

class Hashing
{
    private:
    int index = 0;
    public:

    struct node 
    {
        T data;
       node* next;
    };
    struct node* gumbo = NULL; 
    Hashing ()
    {
        // 

    }
    void insert (T val) // O(1)
    {
        // use inset front >> Working 
        struct node* newNode = new node;
        newNode->data = val;
        newNode->next = gumbo;
        gumbo = newNode;


    }
    void search (T val) // O(n)
    {
        // find the index of the given value 
        struct node* temp = gumbo;
        if ( temp == NULL)
        {
            cout<< " Not Found Here"<< endl;
        }
        else if (temp->data == val)
        {
            cout<< " We Found Here:"<<" It took : " << index<< " iteration" <<endl; // need to include the index where it was found at. 
        }
        else 
        {
            // this would be a not null and value not found 
            // checking for data in that index 
            while (temp!=NULL)
            {
                if (temp->data == val)
                {
                    cout<< " Found Here "<<" It took : "<< index << " iteration"<< endl;
                    return;
                }
                   
                    temp=temp->next;
                    index++;
            }
             cout<< " Not Found"<< endl;
        }
        
        
    }
    void display() // O(n)
    {
        // time to display 
        struct node* temp;
        temp = gumbo;
        while (temp != NULL)
        {
            cout<< temp->data <<" ";
            temp = temp -> next;
        }
    }

};
#endif