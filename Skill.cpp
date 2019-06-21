#include <iostream>
#include "Skill.h"
using namespace std;

ostream& operator << (ostream& out, Skill obj)
{
    out << obj.name;
    return out;
}
