#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <iostream>
#include <iomanip>
#include "linkedlist.h"

using namespace std;

class ItemList:public LinkedList <Item*>
{
private:
    int total = 0;
public:
    void displayItems();
    void displayShop();
    void addItem(Item*, int);
    void createWeaponsList(ItemList&);
    bool isEmpty(){return (!(head));}
    friend class ItemList;

};

void ItemList::displayItems()
{
	ListNode<Item*>* nodePtr;
	if (head == nullptr || total == 0)  //check if list is empty
		cout << "No items to show." << endl;
	else //walk through and print the values
	{
		//start at beginning
		nodePtr = head;
		cout << setw(16) << left << "Name" << setw(12) << left << "Quantity" << endl << endl;
		int i = 1;
		while (nodePtr != nullptr) //(nodePtr->next != nullptr)
		{
		    if (nodePtr->value->getQty() > 0)
            {
                cout << i << ". " << setw(16) << left << nodePtr->value->getName() << nodePtr->value->getQty() << endl;
			//move to next node
                i++;
            }
			nodePtr = nodePtr->next;

		}
	}
}

void ItemList::displayShop()
{
	ListNode<Item*>* nodePtr;
	if (head == nullptr) ; //check if list is empty
		//cout << "Empty List" << endl;
	else //walk through and print the values
	{
		//start at beginning
		nodePtr = head;
		int i = 1;
        cout << setw(19) << left << "Name" << setw(12) << left << "Stock" << "Price" << endl << endl;
		while (nodePtr != nullptr) //(nodePtr->next != nullptr)
		{
			cout << i << ". ";
            cout << setw(16) << left << nodePtr->value->getName() << setw(12) << left;
            if (nodePtr->value->getQty() == -1)
            {
                 cout << "Unlimited";
            }
            else
                cout << nodePtr->value->getQty();
            cout << setw(12) << left << nodePtr->value->getPrice() << endl;
			//move to next node
			nodePtr = nodePtr->next;
			i++;
		}
	}
}

void ItemList::addItem(Item* newItem, int qty)
{

    ListNode<Item*>* nodePtr;

    Item* temp;
    if (newItem->getType() == "Weapon")
        temp = new Weapon(*(Weapon*)newItem , qty);
    else if (newItem->getType() == "Usable")
    {
        temp = new Usable(*(Usable*)newItem , qty);
    }

    ListNode<Item*>* newNode = new ListNode<Item*>;
    newNode->value = temp;
    newNode->next = nullptr;
    if (head == nullptr) //if user attempts to search a list that is empty
    {
        head = newNode;
        return;
    }
    nodePtr = head;
    if (newItem->getName() == nodePtr->value->getName()) //returns position if value at current node matches given object
    {
        nodePtr->value->incrQty();
        return;
    }
    int position = 1;
    while (nodePtr->next) //keep looping while there is more in the list
    {

        nodePtr = nodePtr->next;
        if (newItem->getName() == nodePtr->value->getName()) //returns position if value at current node matches given object
        {
            nodePtr->value->incrQty();
            return;
        }
        position++;
    }
    nodePtr->next = newNode;
    total++;
}

void ItemList::createWeaponsList(ItemList& weapons)
{
    ListNode <Item*>* nodePtr;
    nodePtr = head;
    while (nodePtr)
    {
        if (nodePtr->value->getType() == "Weapon")
        {
            if (nodePtr->value->getQty() > 0)
            {
                weapons.append(nodePtr->value);
                weapons.total++;
            }
        }
        nodePtr = nodePtr->next;
    }
}

#endif
