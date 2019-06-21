#ifndef SKILLLIST_H
#define SKILLLIST_H

#include <iostream>
#include "linkedlist.h"
#include "Skill.h"

using namespace std;

class SkillList:public LinkedList <Skill*>
{
public:
    void displaySkills()
    {
        if (head == nullptr)
            cout << "No Skills";
        else
            displayList();
    }
};


#endif
