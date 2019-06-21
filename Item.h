#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Item
{
protected:
    string name;
    string type;
    string description;
    int price;
    int qty;
public:
    string getName(){return name;}
    string getType(){return type;}
    string getDescription(){return description;}
    int getQty(){return qty;}
    int getPrice(){return price;}
    void setQty(int inQty){qty = inQty;}
    void incrQty(){qty++;}
    void decrQty(){qty--;}
    Item();
    Item(string, string, string, int);
    Item(string, string, string, int, int);
    //friend ostream& operator << (ostream&, Item);
    virtual void displayDetails() = 0;

};



class Weapon:public Item
{
protected:
    int atk;
    int mag;
public:
    Weapon(string, string, int, int, int);
    Weapon();
    Weapon(Weapon, int);
    int getAtk(){return atk;}
    int getMag(){return mag;}
    void displayDetails();
};

class Usable:public Item
{
protected:

public:
    Usable(string, string, int);
    Usable(){}
    Usable(Usable, int);
    void use();
    void displayDetails();
};

#endif //ITEM_H
