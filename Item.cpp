#include <iostream>
#include <string>
#include "Item.h"

using namespace std;




Item::Item()
{

}

Item::Item(string inName, string inType, string inDescr, int inPrice)
{
    name = inName;
    type = inType;
    price = inPrice;
    qty = -1; //quantities less than zero represent infinite amount of that item in a list.
}


Item::Item(string inName, string inType, string inDescr, int inPrice, int inQty)
{
    name = inName;
    type = inType;
    description = inDescr;
    price = inPrice;
    if (inQty == 0)
        qty = 1;
    else
        qty = inQty;
}

Weapon::Weapon(string inName, string inDescr, int inAtk, int inMag, int inPrice)
{
    name = inName;
    type = "Weapon";
    price = inPrice;
    description = inDescr;
    atk = inAtk;
    mag = inMag;
    qty = -1; //quantities less than zero represent infinite amount of that item in a list.
}

Weapon::Weapon()
{

}

Weapon::Weapon( Weapon toCopy, int n)
{
    name = toCopy.getName();
    type = "Weapon";
    price = toCopy.getPrice();
    description = toCopy.getDescription();
    atk = toCopy.getAtk();
    mag = toCopy.getMag();
    qty = n;
}

void Weapon::displayDetails()
{
    cout << getName() << endl
         << getDescription() << endl
         << "Attack: " << getAtk() << endl
         << "Magic: " << getMag() << endl;
}

Usable::Usable(string inName, string inDescr, int inPrice)
{
    name = inName;
    type = "Usable";
    price = inPrice;
    description = inDescr;
    qty = -1; //quantities less than zero represent infinite amount of that item in a list.
}

Usable::Usable(Usable toCopy, int n)
{
    name = toCopy.getName();
    type = "Usable";
    price = toCopy.getPrice();
    description = toCopy.getDescription();
    qty = n;
}

void Usable::displayDetails()
{
        cout << getName() << endl
         << getDescription() << endl;
}
