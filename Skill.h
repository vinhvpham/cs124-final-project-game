#ifndef SKILL_H
#define SKILL_H

#include <iostream>

using namespace std;

class Skill
{
protected:
    string name;
public:
    friend ostream& operator << (ostream&, Skill);
};

#endif
