#ifndef UNITLIST_H
#define UNITLIST_H

#include <iostream>
#include "Unit.h"
using namespace std;

class UnitList:public LinkedList <Unit*>
{
protected:
    int listCount;
public:
    void displayUnits();
    void displayRecruits();
    void addUnit(Unit*);
    void insertBySpeed(Unit*);
    int getCount(){return listCount;}
    void deleteUnitFromList(int);
    void fightDisplay();
    bool isEmpty();
    void moveListBySpeed(UnitList&);
    bool noLeader();
    UnitList(){LinkedList(); listCount = 0;}
    ~UnitList();
};

bool UnitList::isEmpty()
{
    //cout << head <<  listCount << endl;
    //cout << "debug Check" << endl;
    if (listCount==0)
    {
        //cout << "isempty" << endl;
        return true;
    }

    return false;
}
UnitList::~UnitList()
{
}
bool UnitList::noLeader()
{
    Character* unit = (Character*)get(1);
    if (!(unit->isLeader()))
        return true;
    return false;
}

void UnitList::deleteUnitFromList(int index)
{
    deleteNode(index);
    listCount --;
}

void UnitList::moveListBySpeed(UnitList& thelist)
{
    for (int i=1; i<= thelist.getCount(); i++)
    {
        insertBySpeed(thelist.get(i));
    }
}

void UnitList::insertBySpeed(Unit* unit)
{
	ListNode<Unit*> *newNode;   //a new node
	ListNode<Unit*> *nodePtr;   // to walk the list
	ListNode<Unit*> *previousNode = nullptr; //previous node
	//allocate a new node and store newValue there
	newNode = new ListNode <Unit*>;
	newNode->value = unit;

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
		while (nodePtr != nullptr && nodePtr->value->getSpd() > unit->getSpd())
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

    listCount++;
}
void UnitList::fightDisplay()
{
    ListNode<Unit*>* nodePtr;
    nodePtr = head;
    while (nodePtr)
    {
        cout << setw(19) << left << nodePtr->value->getName();
        nodePtr = nodePtr->next;
    }
    nodePtr = head;
    cout << endl;
    while (nodePtr)
    {
        cout << "HP: " << nodePtr->value->getHp() << "/" << setw(12) << left << nodePtr->value->getMaxHp() ;
        nodePtr = nodePtr->next;
    }

    cout << endl;
    nodePtr = head;
    Unit* test = head->value;
    if (!(test->isAlly()))
        return;
    while (nodePtr)
    {
        cout  << "MP: " << nodePtr->value->getMp() << "/" << setw(12) << left << nodePtr->value->getMaxMp() ;
        nodePtr = nodePtr->next;

    }
}

void UnitList::displayUnits()
{
    ListNode<Unit*>* nodePtr;
	if (head == nullptr)  //check if list is empty
		cout << "No units to show." << endl;
	else //walk through and print the values
	{
		//start at beginning
		nodePtr = head;
		//cout << "   " << setw(16) << left << "Name" << endl;
		int i = 1;
		while (nodePtr != nullptr) //(nodePtr->next != nullptr)
		{
			cout << i << ". " << nodePtr->value->getName() << endl;
			//move to next node
			nodePtr = nodePtr->next;
			i++;
		}
	}
}

void UnitList::displayRecruits()
{
    ListNode<Unit*>* nodePtr;
    Character* temp;
    Unit* current;
	if (head == nullptr)  //check if list is empty
		cout << "No units to show." << endl;
	else //walk through and print the values
	{
		//start at beginning
		nodePtr = head;
		//cout << "   " << setw(16) << left << "Name" << endl;
		int i = 1;
		cout << "   " << setw(20) << right << "Cost" << endl << endl;
		while (nodePtr != nullptr) //(nodePtr->next != nullptr)
		{
		    current = nodePtr->value;
		    temp = (Character*)current;
			cout << i << ". " << setw(16) << left << nodePtr->value->getName() << temp->getRecruitCost() << endl;
			//move to next node
			nodePtr = nodePtr->next;
			i++;
		}
	}
}

 void UnitList::addUnit(Unit* newUnit)
 {
     append(newUnit);
     listCount++;
 }



#endif
