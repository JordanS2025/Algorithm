// Jordan Scott 
// CST-201 
// ----------------------------------------------------------------
#ifndef SinglyLinkedList_H
#define SinglyLinkedList_H
#include <iostream>
using namespace std;
template<class T>

class SinglyLinkedList
{
    private: 
    int count = 0;

    public: 
    struct node 
  {            
    T data; 
    node* next;           
  };
  struct node* head = NULL;  
  struct node* tail = NULL;     

     SinglyLinkedList()
    {
      
    }

    void display() // O(n)
    {
      struct node* temp;
      temp = head;
      while (temp != NULL)
      {
        cout<< temp->data <<" ";
        temp = temp -> next;
      }
    }
   void front() // O(n)
    {
      if (head == NULL)
      {
        cout<< " NULL"<<endl;
      }
      else
      {
        cout<< head -> data<< endl;
      }

    }
   void  back()// O(n) 
    {
      if (tail == NULL)
      {
        cout<< " NULL"<<endl;
      }
      else
      {
        cout<< tail->data << endl;
      }
      
    }
 void insert(int val) // O(n) because we have to go thru the whole list 
{
  count++;
    // create new node
    node* newNode = new node;
    newNode->data = val;
    newNode->next = NULL;

    // check if list is empty
    if (head == NULL)
    {
      head = newNode;
    }
    else if (head->data > val)
    {
      newNode ->next = head;
      head = newNode;
    }

    else 
    {
        // insert at correct position, sorted in ascending order
        // need to track the tail pointer!!!!
        node* current = head;
        node* previous = NULL;
        while (current != NULL )
        {
          if(current->data > val)
          {
            break;
          }
          // insert middle 
            previous = current;
            current = current->next;
        }

         previous -> next = newNode;
         newNode -> next = current;
         if (current == NULL )
         {
            tail = newNode;
         }
        
    }
}

    void pop_front()// O(1)
    { 
      node* temp = head;
      head = head->next;
      delete temp;
    }
   void pop_back()// O(n) since we have to loop through entire list 
   // need to go through the whole list 
   // when at the end of the list delete current->next and set the preivous as new
    {
        node *temp = head;
        while (temp->next->next != nullptr) 
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
   
    int size() // O(1)
    {
      return count;
    }
    void empty() // O(n)
    {
      if (head == NULL)
      {
        cout<< "Empty"<< endl;
      }
      else
      {
        cout<< "not empty " << endl;
      }

    }
    void reverse() // O(n) since i have to traverse the entire list
    {
      node* current = head;
        node* previous = NULL;
        node* next = NULL;
        while (current != NULL) 
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;

    }
   void  merge(SinglyLinkedList aList) 
   // O(m*n) since the number of nodes in the linked list passed as argument (aList), 
   //  the number of nodes in called in usind the inser method 
   // merging two lists
    {
      node* temp = aList.head;
      while(temp !=NULL) 
      {
        this->insert(temp->data);
        temp= temp->next;
      }
    }
};
#endif