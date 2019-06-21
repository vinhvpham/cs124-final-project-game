#include <iostream>
#include <iomanip>
#include <string>
#include "Unit.h"
#include "Item.h"
#include "Skilllist.h"
#include <cstdlib>
using namespace std;


void Unit::decreaseHp(int n)
{
    hp -= n;
    if (hp < 0)
        hp = 0;
}

Character::Character()
{

}

Character::Character(string inName)
{
    name = inName;
    leader = false;
    equip = nullptr;
    ally = true;
    // Characters are created with base stats of 2,
    //hp 50, mp 15, and 10 randomly distributed points
    //to all stats, and then 5 randomly distributed points
    //to mag and/or str.
    int num;
    hp = maxHp = 50;
    mp = maxMp = 15;
    str = mag = def = res = spd = tch = 2;
    recruitCost = 1500;
    for (int i=0; i<10; i++)
    {
        num = rand()% 6+1;
        if (num == 1)
            str++;
        else if(num == 2)
            mag++;
        else if(num == 3)
            def++;
        else if(num == 4)
            res++;
        else if (num == 5)
            spd++;
        else
            tch++;
    }
    for (int i=0; i<5; i++)
    {
        num = rand()% 2+1;
        if (num == 2)
            str++;
        else if(num == 1)
            mag++;
    }
}


string Character::getWeaponName()
{
    if (equip == nullptr)
        return "None";
    return equip->getName();
}

void Character::displayStats()
{
    cout << getName() << endl << endl
         << "Hp: " << getHp() << "/" << getMaxHp() << endl
         << "Mp: " << getMp() << "/" << getMaxMp() << endl << endl
         << setw(12) << left << "Strength: " << getStr() << endl
         << setw(12) << left << "Magic: " << getMag() << endl
         << setw(12) << left << "Defense: " << getDef() << endl
         << setw(12) << left << "Resistance " << getRes() << endl
         << setw(12) << left << "Speed: " << getSpd() << endl
         << setw(12) << left << "Technique: " << getTch() << endl
         << endl << "Skills: " << endl;
         skills.displaySkills();
    cout << endl << endl << "Weapon: " << getWeaponName() << endl;

}

void Character::attack(Unit* opp)
{
    int dmg;
    if (equip)
        dmg = getStr()+equip->getAtk();
    else
        dmg = getStr();
    cout << getName() << " attacks!" << endl
    << opp->getName() << " takes " << dmg << " damage." << endl;

    opp->decreaseHp(dmg);
}

void Enemy::attack(Unit* opp)
{
    int dmg = getStr();
    cout << getName() << " attacks!" << endl
    << opp->getName() << " takes " << dmg << " damage." << endl;

    opp->decreaseHp(dmg);
}


Enemy::Enemy(string inName, int level)
{
    name = inName;
    ally = false;
    int num;
    hp = maxHp = 15*level;
    mp = maxMp = 0;
    str = mag = def = res = spd = tch = 1;
    for (int i=0; i<5*level; i++)
    {
        num = rand()% 6+1;
        if (num == 1)
            str++;
        else if(num == 2)
            mag++;
        else if(num == 3)
            def++;
        else if(num == 4)
            res++;
        else if (num == 5)
            spd++;
        else
            tch++;
    }
    for (int i=0; i<5; i++)
    {
        num = rand()% 2+1;
        if (num == 2)
            str++;
        else if(num == 1)
            mag++;
    }
}
