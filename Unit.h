#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>
#include "Item.h"
#include "Skilllist.h"
using namespace std;

class Unit
{
protected:
    SkillList skills;
    string name;
    bool ally;
    int hp;
    int maxHp;
    int mp;
    int maxMp;
    int str;
    int mag;
    int def;
    int res;
    int spd;
    int tch;
public:
    string getName(){return name;}
    int getHp(){return hp;}
    //virtual void fightAction(UnitList&, UnitList&, UnitList&, ItemList&, int) = 0;
    void decreaseHp(int);
    void setHp(int n){hp = n;}
    bool isAlly(){return ally;}
    int getMaxHp(){return maxHp;}
    int getStr(){return str;}
    int getMp(){return mp;}
    int getMaxMp(){return maxMp;}
    int getMag(){return mag;}
    int getDef(){return def;}
    int getRes(){return res;}
    int getSpd(){return spd;}
    int getTch(){return tch;}
    //friend ostream& operator << (ostream&, Unit);
    virtual void attack(Unit*) = 0;
};

class Character:public Unit
{
protected:
    //string job;

    int lvl;
    int recruitCost;
    bool leader;
    Weapon* equip;
public:
    Character();
    Character(string);
    void displayStats();
    void incrHp(int n){hp += n;}
    void incrStr(int n){str += n;}
    void incrMag(int n){mag += n;}
    void incrDef(int n){def += n;}
    void toggleLeader(){leader = 'y';}
    void setEquip(Weapon* inEquip){equip = inEquip;}
    string getWeaponName();

    int getLvl(){return lvl;}
    int getRecruitCost(){return recruitCost;}
    bool isLeader(){return leader;}
    bool hasEquip(){return equip;}
    Weapon* getEquip(){return equip;}
    //void fightAction(UnitList&, UnitList&, UnitList&, ItemList&, int);
    void attack(Unit*);

    //string getJob(){return job;}
};

class Enemy:public Unit
{
protected:

    public:
        Enemy(){}
        Enemy(string, int);
        void attack(Unit*);
        //void fightAction(UnitList&, UnitList&, UnitList&, ItemList&, int);
};

#endif
