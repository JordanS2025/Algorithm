#include <iostream>
using namespace std;
struct node 
{            
  int data; 
  node* next;           
};
struct node* head = NULL;  
struct node* tail = NULL;                  
  
void insertFront(int newData) 
{          
   struct node* newNode = new node; 
if(head == NULL)
{ 
  tail = newNode;                                     
}
   newNode ->data = newData;        
  newNode->next = head;           
   head = newNode;                  
}
void insertEnd(int newData)
{  
struct node* newNode = new node;  
newNode -> data = newData;  
newNode -> next = NULL;  
tail -> next = newNode;  
tail = newNode;  
}
void display() 
{             
   struct node* temp;    
   temp = head;              
   while (temp != NULL) 
   {           
      cout <<  temp-> data  <<" ";    
      temp = temp -> next;               
   }
}
int main() 
{
 insertFront(10);          
   insertFront(20);       
   insertFront(30);
   insertFront(40);
   insertEnd(60);
   display();
   return 0;
}
