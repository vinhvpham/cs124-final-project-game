#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>
#include <conio.h>

using namespace std;

//this is the .h file
//define node structure
template <class T>
struct ListNode
{
	T value;  //the "data"
	ListNode* next;  //pointer to the next node
};

template <class T>
class LinkedList
{
protected:
	//need to maintain the start of the list
	ListNode<T>* head;


public:
	LinkedList() { head = nullptr; }  //empty list
	~LinkedList();   //destructor
	void displayList();  //to print all values in the list
	void append(T);
	void insertNode(T);  //insert node in order
	void insertToLocation(int, T); //insert node to a specified location in the list
	bool deleteNode(int);   //delete node at the specified location
    int searchNode(T);  //search for a node that matches the object in the parameter, returns the position if found.
    T get(int); //returns the object at the specified position
};


//insert newValue in correct order
template <class T>
void LinkedList<T>::insertNode(T newValue)
{
	ListNode<T> *newNode;   //a new node
	ListNode<T> *nodePtr;   // to walk the list
	ListNode<T> *previousNode = nullptr; //previous node
	//allocate a new node and store newValue there
	newNode = new ListNode <T>;
	newNode->value = newValue;

	//have to figure out where to insert it
	//if no nodes in the list make newNode the first node
	if (head == nullptr)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else  //figure out where to insert newNode
	{
		//position nodePtr to walk the list
		nodePtr = head;

		//initialize previousNode to nullptr
		previousNode = nullptr;

		//skip all nodes whose value is less that newValue
		while (nodePtr != nullptr && nodePtr->value < newValue)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//if it goes at the beginning
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else //insert between previousNode and nodePtr
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}

	}


}
template <class T>
void LinkedList<T>::append(T num)
{
	//add num to the end of the list
	ListNode<T>* newNode;  //to hold the new node
	ListNode<T>* nodePtr;  //to "walk" the list

	//allocate the new node
	newNode = new ListNode<T>;
	//assign fields
	newNode->value = num;
	newNode->next = nullptr;  //it is the end of the list
	//figure out where to put it
	//if empty list it's easy
	if (head == nullptr) //empty list
		head = newNode;
	else //find the end of the list
	{
		//start at head
		nodePtr = head;
		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;  //move to next node
		}
		//when this loop ends, nodePtr is pointing to the last node
		//need to make newNode the last node
		nodePtr->next = newNode;
	}
}

template <class T>
void LinkedList<T>::insertToLocation(int pos, T obj)
{
	ListNode<T>* newNode;   //node to be inserted
	ListNode<T>* nodePtr;   //node to traverse
	newNode = new ListNode<T>;
	newNode->value = obj;
	newNode->next = nullptr;
	ListNode<T> *previousNode = nullptr;
	if (head == nullptr)    //if list is empty
        head = newNode;     //then insert node becomes the first,regardless of specified position.
    else
    {
        nodePtr = head; //list is not empty, so start at the head
        int counter = 1;//keeps track of current position in list. Head starts at 1.
        while (nodePtr->next  && counter < pos)//while a node exist after the current and the current position is not yet the specified position, traverse
        {
            previousNode = nodePtr; //keep track of the current node before moving it.
            nodePtr = nodePtr->next;
            counter++;
        }
        if (counter < pos) //if true, it implies that the user specified a position that was greater than the length of the list
        {
           nodePtr->next = newNode; //in that case, insert to the end of the list
        }
        else //for cases in which it did not reach the end of the list
        {
            if (previousNode) //if previous node points to something, that means it's somewhere in the middle of the list
                previousNode->next = newNode; //connect the previous node to the new node
            else
                head = newNode; //if there was no previous node, that implies inserting at the first position, head should be the newNode.

            newNode->next= nodePtr; //in either case, connect the new node to the current nodePtr
        }


    }
}

template <class T>
bool LinkedList<T>::deleteNode(int pos)
{
    if (pos > 0 && head) //only start if user specifies a position greater than zero and there is at least one element
    {
        int counter = 1;
        ListNode<T>* nodePtr;
        ListNode<T>* previousNode;
        nodePtr = head;
        while (nodePtr->next && counter < pos)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
            counter++;
        }
        if (counter < pos) //if true, it implies user specified a position greater than the length
            return false;   //signal failure because there is no node to delete.
        if (nodePtr == head)   //special case in which user specifies the first location
            head = head->next;  //it's original head is the node to be deleted, so make the new head the next node.
        else
            previousNode->next = nodePtr->next; //connect the nodes on each side of the node that will be deleted
        delete nodePtr;
        return true; //signals success in deleting.
    }
    return false; //signals failure if user specified an invalid position
}

template <class T>
int LinkedList<T>::searchNode(T obj)
{
    ListNode<T>* nodePtr;
    if (head == nullptr) //if user attempts to search a list that is empty
        return 0;
    nodePtr->next = head;
    int position = 1;
    while (nodePtr->next) //keep looping while there is more in the list
    {
        nodePtr = nodePtr->next;
        if (obj == nodePtr->value) //returns position if value at current node matches given object
            return position;
        position++;
    }
    return 0; //signals that it cannot be found
}

template <class T>
T LinkedList<T>::get(int pos)
{

    ListNode<T>* nodePtr;
    if (head == nullptr) //if user attempts to user get function on empty list
    {
        return T(); //return a default object
    }

    nodePtr = head;
    int current = 1;
    while (nodePtr->next && current < pos) //keep looping until reaching the given position or until the end of list
    {
        nodePtr = nodePtr->next;
        current++;
    }

    return nodePtr->value; //return the object at that position in the list.
}

template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode<T>* nodePtr;
	ListNode<T>* nextNode;
	//walk the list and delete memory
	nodePtr = head;
	//cout << "debug" << endl;
	while (nodePtr != nullptr)
	{
	    //cout << nodePtr << head;
	    getch();
		//hold on to where the next one is before I let this one go
		nextNode = nodePtr->next;
		//cout << "debug 2" << endl;
		//delete nextNode6
		delete nodePtr;
		nodePtr = nextNode;
	}
	//cout << "debug 3" << endl;
}

template <class T>
void LinkedList<T>::displayList()
{
	ListNode<T>* nodePtr;
	if (head == nullptr) ; //check if list is empty
		//cout << "Empty List" << endl;
	else //walk through and print the values
	{
		//start at beginning
		nodePtr = head;
		while (nodePtr != nullptr) //(nodePtr->next != nullptr)
		{
			//cout << nodePtr->value << endl;
			//move to next node
			nodePtr = nodePtr->next;
		}
	}
}

#endif
