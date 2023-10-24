// Jordan Scott 
// CST-201
// Double link list
#pragma once
#ifndef DLINKLIST_H
#define DLINKLIST_H
#include <iostream>
using namespace std;

template <class T>
class DLinkedList {

	//PROVIDED
	friend ostream & operator<<(ostream & out, const DLinkedList<T> & rhs) {
		DNode * curr = rhs.header->next;
		while (curr != rhs.header) {
			out << curr->data << " ";
			curr = curr->next;
		}
		return out;
	}

public:

	//inner class DNode PROVIDED
	class DNode {
	public:
		DNode * next;
		DNode * prev;
		T data;

		DNode(T val = T()) {
			data = val;
			next = prev = this;
		}
		
	};

	//create an empty list:  PROVIDED
	DLinkedList() {
		//create the header
		header = new DNode();		
	}

	//add method  PROVIDED
	DNode * add(T item) // O(1)
	{
		//add a new node and return a 
		//pointer to this node
		DNode * newNode = new DNode(item);
		newNode->prev = header;
		newNode->next = header->next;
		header->next->prev = newNode;
		header->next = newNode;
		return newNode;
	}

	/**
	* ASSIGNED
	* remove val from the list
	*
	* @param val
	* @return true if successful, false otherwise
	*/
void remove(T val) //O(n)
	{ //we are removing by data
		struct DNode* temp = header;            //a temp node is cloning the head
		while(temp->next != NULL)
		{                   					 //start looping
		if(temp -> data == val)
		{    										 //if node data matches passed data
			if(temp -> prev == NULL)
			{        									//we check if it is the head
			header = temp -> next;              	 //removes the head, and sets new pointer
			header -> prev = NULL;
			}
			else if(temp -> next == NULL)
			{        //check if it is the tail
				temp -> prev -> next = NULL;        //if so move pointer to NULL
			}
		else
			{                                            //if data is found in the list
			cout << "Removing " << temp -> data << endl;  
			temp -> next -> prev = temp -> prev;         //reassign pointers
			temp -> prev -> next = temp -> next;         //reassign pointers
			}
			//delete(temp);                                                //DELETE (TEMP)
			return;                                          //Java has garbage collection
		}
		temp = temp -> next;              //iterates the list
		}
		cout << val << " not here" << endl;        //not in the list

	}
	

	/**
	* ASSIGNED
	*
	* @param item
	*/
	void insertOrder(T item) // O(n)
    {
        DNode* newDNode = new DNode(item);                              // new node containing the new data
	DNode* temp = header->next;                                     // temp header node

	while (temp->data <= newDNode->data && temp != header) { temp = temp->next; }    // loop to know where to insert the new data

	if (temp->next == header && temp->data <= newDNode->data) {      // checks if the data is less than the final node
		newDNode->next = temp->next;                                // inserts node before the last value
		newDNode->prev = temp;

		temp->next->prev = newDNode;
		temp->next = newDNode;
	}
	else if (temp == header && temp->data >= newDNode->data) {     // checks if the data is greater than the final node
		newDNode->next = temp;                                      // inserts node after the last value
		newDNode->prev = temp->prev;

		temp->prev->next = newDNode;
		temp->prev = newDNode;
		header = newDNode;                                          // reassign header node
	}
	else {                                                        // inserts node for all other cases
		newDNode->next = temp;
		newDNode->prev = temp->prev;

		temp->prev->next = newDNode;
		temp->prev = newDNode;
	}

	}

	/**
	* ASSIGNED
	*
	* @param item
	*/
	void insertOrderUnique(T item) // O(n)
	{
		
		DNode* temp = header->next;
    while (temp != header) 
	{
        if (temp->data == item) 
		{
            return;
        }
        temp = temp->next;
    }
    insertOrder(item);
	}

	/**
	* ASSIGNED
	* PRE:  this and rhs are sorted lists
	* @param rhs
	* @return list that contains this and rhs merged into a sorted list
	* POST:  returned list will not contain duplicates, both rhs and this
	* will have no elements
	*/
	DLinkedList merge(DLinkedList rhs) // O(m*n)
	{
   		 DLinkedList result;
		DNode * curr = rhs.header->next;
		DNode * curr2 = this->header->next;
		while (curr != rhs.header) 
		{
			result.insertOrderUnique(curr->data); 
			rhs.remove(curr->data);
			curr = curr->next;
			
		}
		while(curr2!= this->header)
		{
			result.insertOrderUnique(curr2->data);
			this->remove(curr2->data);
			curr2 = curr2-> next;
			
		}

    	return(result);  
	}

	
private:
	//DLinkedList fields:  PROVIDED
	DNode * header;	

};
#endif