#ifndef MYSTACK_H
#define MYSTACK_H
#include <string>
#include <iostream>
using namespace std;
template<class T>

class myStack 
{
    private: 
    int size=0;

    public : 
    struct node 
    {            
        T data; 
        node* next;           
    };
  struct node* topStack = NULL;  
    myStack ()
    { 
    }
    void push (T v)
    {
        size++;
        struct node* newNode = new node;
        newNode -> data = v;
        newNode -> next = topStack;
        topStack = newNode;
    }
    int size1() const
    {
        return size;
    }
    bool empty () const
    {
        if (size == -1)
        {
            return true;
        }
        else 
        {
            return false;
        }

    }
    T top () const
    {
        return topStack-> data;
    }
    void pop ()
    {
        if (empty()) return;
       struct node* temp = topStack;
        topStack = temp ->next== nullptr;
        size--; 
    }


};
#endif