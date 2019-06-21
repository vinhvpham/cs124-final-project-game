#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include "Item.h"
#include "Unit.h"
#include "Itemlist.h"
#include "Skilllist.h"
#include "UnitList.h"
using namespace std;

void managePartyMember(UnitList&, UnitList&, ItemList&, int);
void manageReserveMember(UnitList&, UnitList&, ItemList&, int);
void itemShopping(ItemList&, ItemList&, int, string);
void recruitMember(UnitList&, UnitList&, int);
bool battle(UnitList&, UnitList&, ItemList&, int);
void fightAction(Unit*, UnitList&, UnitList&, UnitList&, ItemList&, int);

int main()
{
    srand (time(NULL));
    bool again = true;
    char choice;
    int numselect;
    int gold = 10000;
    ItemList inventory;
    SkillList skills;
    UnitList reserve;
    UnitList party;
    string mcName;
    cout << "Hello there traveler! What do they call you?" << endl
    << "(Enter name): ";
    cin >> mcName;
    system("cls");
    cout << "Good Luck on your journey, " << mcName << "!" << endl
    << "Fight monsters to get gold, and Recruit more members to become more powerful." << endl
    << "(Some features may be incomplete)";
    getch();
    system("cls");
    party.addUnit(new Character(mcName));
    Character* leader = (Character*)party.get(1);
    leader->toggleLeader();
    //party.addUnit(new Character("John"));
    UnitList mob2;
    UnitList mob1;
    UnitList mob3;
    UnitList recruits;
    recruits.addUnit(new Character("Pamela"));
    recruits.addUnit(new Character("David"));
    recruits.addUnit(new Character("Ron"));
    recruits.addUnit(new Character("Fang"));
    recruits.addUnit(new Character("Athena"));
    recruits.addUnit(new Character("Fargus"));
    recruits.addUnit(new Character("Sophitia"));
    int menu;
    ItemList shop;
    //inventory.addItem(new Usable("bomb", "deals 20 damage to all enemies", 200));
    //inventory.append(new Usable("bomb", "deals 20 damage to all enemies", 200));
    //inventory.addItem(new Weapon("Iron Sword", "A common sword", 3, 0, 300), 2);
    inventory.addItem(new Weapon("Iron Sword", "A common sword", 3, 0, 300), 1);
    inventory.addItem(new Usable("bomb", "deals 20 damage to all enemies", 200), 1);
    inventory.addItem(new Usable("bomb", "deals 20 damage to all enemies", 200), 1);
    shop.append(new Weapon("Iron Sword", "A common sword", 3, 0, 300));
    shop.append(new Weapon("Steel Sword", "A well made sword", 7, 0, 700));
    shop.append(new Weapon("Old Staff", "A wooden staff", 0, 3, 200));
    shop.append(new Weapon("Glass Rod", "A fancy rod", 1, 6, 800));
    shop.addItem(new Weapon("Ice Blade", "A magical sword", 4, 3, 2000), 1);
    shop.addItem(new Usable("Potion", "Recovers 15 hp to one ally", 150), -1);
    shop.addItem(new Usable("Elixir", "Recovers 10 mp to one ally", 150), -1);
    shop.addItem(new Usable("Bomb", "deals 20 damage to all enemies", 200), 3);

    while (again)
    {
        cout << "1. Manage party members" << endl
             << "2. List all Items" << endl
             << "3. Visit Item Shop" << endl
             << "4. Visit Skill Shop" << endl
             << "5. Visit Inn (recover hp and mp)" << endl
             << "6. Visit Pub (Hire Units)" << endl
             << "7. Practice at the training garden (1 enemy, very easy)" << endl
             << "8. Hunt in the forest (2 enemies, medium)" << endl
             << "9. Train in the mountains (4 enemies, hard)" << endl
             << "What to do? (1-6): ";
             cin >> menu;
             cout << endl;
             system("cls");
             switch (menu)
             {
             case 1:
                cout << "1. See Current Party" << endl
                     << "2. See Reserve members" << endl
                     << "Choose 1-2: ";
                cin >> menu;
                system("cls");
                switch (menu)
                {
                case 1:
                    party.displayUnits();
                    cout << endl << "Choose a unit to see their details and manage (0 to cancel): ";
                    cin >> numselect;
                    if (numselect == 0)
                        break;
                    system("cls");
                    managePartyMember(party, reserve, inventory, numselect);
                    break;
                case 2:
                    reserve.displayUnits();
                    if (!(reserve.getCount() == 0))
                    {
                        cout << endl << "Choose a unit to see their details and manage (0 to cancel): ";
                        cin >> numselect;
                    }

                    if (numselect == 0)
                        break;
                    system("cls");
                    manageReserveMember(party, reserve, inventory, numselect);
                    break;
                }
                break;
            case 2:
                inventory.displayItems();
                getch();
                break;
             case 3:
                itemShopping(shop, inventory, gold, "Welcome! Buy Items and Weapons here!");
                break;
             case 4:
                //skillShopping(skills, party, gold, "Trying to learn a new fighting skill?");
                cout << "Coming soon!";
                getch();
                break;
             case 5:
                cout << "Coming Soon!";
                getch();
                break;
                cout << "Resting at the inn will recover the HP and MP of the current party." << endl
                     << "Cost: 100 Gold. " << endl << "Rest at the Inn? (y or n): ";
                cin >> choice;
                while (choice != 'y' && choice != 'n')
                {
                    cout << "invalid choice, try again: ";
                    cin >> choice;
                }
                if (choice == 'y')
                {
                    //rest(party, gold);
                }
                break;
             case 6:
                recruitMember(reserve, recruits, gold);
                break;
             case 7:
                mob1.addUnit(new Enemy("Slime", 1));
                if (battle(party, mob1, inventory, gold))
                {
                    cout << "Game Over...";
                    exit(0);
                }
                cout << "debug out2" << endl;
                getch();
                break;
             case 8:
                mob2.addUnit(new Enemy("Slime", 1));
                mob2.addUnit(new Enemy("Wolf", 2));
                battle(party, mob2, inventory, gold);
                {
                    cout << "Game Over...";
                    return 0;
                }
                cout << "debug out2" << endl;
                break;
             case 9:
                mob3.addUnit(new Enemy("Slime", 1));
                mob3.addUnit(new Enemy("Wolf", 2));
                mob3.addUnit(new Enemy("Slime", 1));
                mob3.addUnit(new Enemy("Gargoyle",3));
                if (battle(party, mob3, inventory, gold))
                {
                    cout << "Game Over...";
                    exit(0);
                }
                break;
             case 0:
                exit(0);
                break;
             }
        system("cls");
    }

    return 0;
}

void itemShopping(ItemList& shop, ItemList& stock, int money, string description)
{
    int choice = 1;
    while (choice != 0)
    {
        cout << description << endl << endl;
        shop.displayShop();
        cout << endl << "Current gold: " << money << endl << endl
        << "Enter the number of the item you would like to view (0 to quit): ";
        cin >> choice;
        system("cls");
        if (choice != 0)
        {
            Item* selected = shop.get(choice);
            selected->displayDetails();
            cout << "Cost: " << selected->getPrice() << endl << endl
             << "Current gold: " << money << endl << endl;
            if (selected->getPrice() <= money)
            {
                char yOrN;
                cout << "Buy this Item? (y or n): ";
                cin >> yOrN;
                if  (yOrN == 'y')
                {
                    stock.addItem(selected, 1);
                    cout << selected->getName() << " bought.";
                    money -= selected->getPrice();
                    if (selected->getQty()>0)
                    {
                        selected->decrQty();
                        if (selected->getQty() == 0)
                        {
                            shop.deleteNode(choice);
                            delete selected;
                        }
                    }
                    getch();
                }

            }
            else
            {
                cout << "Not enough gold to buy this item." << endl;
                getch();
            }
            system("cls");

        }
    }

}

void managePartyMember(UnitList& inList, UnitList& outList, ItemList& items, int index)
{
    int menu = 0;
    int num;
    Character* unit = (Character*)inList.get(index);
    while (menu != 4)
    {
        unit->displayStats();
        cout << endl;
        ItemList listWeapons;
        cout << "1. Bench party member" << endl
             << "2. Choose a Weapon to Equip" << endl
             << "3. Remove Equipped Weapon" << endl
             << "4. quit" << endl
             << "Choose an option (1-4): ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            if (unit->isLeader())
                cout << "The leader cannot be benched.";
            else
            {
                outList.addUnit(unit);
                inList.deleteUnitFromList(index);
                cout << unit->getName() << " has been sent to reserves. " << endl;
                menu = 4;
            }
            break;
        case 2:
            items.createWeaponsList(listWeapons);
            system("cls");
            if (listWeapons.isEmpty())
            {
                cout << "No Weapons to equip." << endl;
            }
            else
            {
                listWeapons.displayItems();
                cout << endl << "Choose a weapon (0 to cancel): ";
                cin >> num;
                if (num == 0)
                {
                    cout << "Canceled." << endl;
                    break;
                }
                Weapon* newWeapon = (Weapon*)listWeapons.get(num);
                newWeapon->decrQty();
                if (unit->hasEquip())
                {
                    Weapon* oldWeapon = unit->getEquip();
                    oldWeapon->incrQty();
                    cout << oldWeapon->getName() << " was placed back in inventory." << endl;
                }
                unit->setEquip(newWeapon);
                cout << unit->getName() << " Equipped " << unit->getWeaponName() << "." << endl;
            }
            break;
        case 3:
            if (unit->hasEquip())
            {
                Weapon* oldWeapon = unit->getEquip();
                oldWeapon->incrQty();
                cout << oldWeapon->getName() << " was placed back in inventory." << endl;
                unit->setEquip(nullptr);
            }
            else
            {
                cout << "nothing is equipped already." << endl;
            }
            break;
        case 4:
            return;
            break;
        }
        getch();
        system("cls");
    }

}

void manageReserveMember(UnitList& inList, UnitList& outList, ItemList& items, int index)
{
    int menu = 0;
    int num;
    Character* unit = (Character*)outList.get(index);
    while (menu != 4)
    {
        unit->displayStats();
        cout << endl;
        ItemList listWeapons;
        cout << "1. Assign member to party" << endl
             << "2. Choose a Weapon to Equip" << endl
             << "3. Remove Equipped Weapon" << endl
             << "4. quit" << endl
             << "Choose an option (1-4): ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            if (inList.getCount() == 4)
                cout << "Party already has a maximum of 4 members." << endl;
            else
            {
                inList.addUnit(unit);
                outList.deleteUnitFromList(index);
                cout << unit->getName() << " Joined the party. " << endl;
                menu = 4;
            }
            break;
        case 2:
            items.createWeaponsList(listWeapons);
            system("cls");
            if (listWeapons.isEmpty())
            {
                cout << "No Weapons to equip." << endl;
            }
            else
            {
                listWeapons.displayItems();
                cout << endl << "Choose a weapon (0 to cancel): ";
                cin >> num;
                if (num == 0)
                    break;
                Weapon* newWeapon = (Weapon*)listWeapons.get(num);
                newWeapon->decrQty();
                if (unit->hasEquip())
                {
                    Weapon* oldWeapon = unit->getEquip();
                    oldWeapon->incrQty();
                    cout << oldWeapon->getName() << " was placed back in inventory." << endl;
                }
                unit->setEquip(newWeapon);
                cout << unit->getName() << " Equipped " << unit->getWeaponName() << "." << endl;
            }
            break;
        case 3:
            if (unit->hasEquip())
            {
                Weapon* oldWeapon = unit->getEquip();
                oldWeapon->incrQty();
                cout << oldWeapon->getName() << " was placed back in inventory." << endl;
                unit->setEquip(nullptr);
            }
            else
            {
                cout << "nothing is equipped already." << endl;
            }
            break;
        case 4:
            return;
            break;
        }
        getch();
        system("cls");
    }

}


void recruitMember(UnitList& myMembers, UnitList& recruits, int money)
{
    int numselect = 1;
    while (numselect != 0)
    {
        recruits.displayRecruits();
        cout << endl << "Choose a unit to see their details (0 to quit): ";
        cin >> numselect;
        if (numselect != 0)
        {
            system("cls");
            Character* unit = (Character*)recruits.get(numselect);
            unit->displayStats();
            cout << endl;
            cout << "Current gold: " << money << endl;
            char choice;
            if (unit->getRecruitCost() > money)
            {
                cout << "You do not have enough money to hire this person." << endl;
                getch();
            }
            else
            {
                cout << "Hire this person for " << unit->getRecruitCost() << "? (y or n): ";
                cin >> choice;
                if (choice == 'y')
                {
                    myMembers.addUnit(unit);
                    recruits.deleteNode(numselect);
                    cout << unit->getName() << " is now waiting in your reserves." << endl;
                    money -= unit->getRecruitCost();
                    getch();
                }
            }
            system("cls");
        }

    }

}


void fightAction(Unit* current, UnitList& party, UnitList& mob, UnitList& order, ItemList& items, int money)
{
    if (current->isAlly())
    {
        int menu;
        int choice;
        bool again = true;
        Unit* opponent;
        while (again)
        {
            mob.fightDisplay();
            cout << endl << endl << endl;
            party.fightDisplay();
            cout << endl << endl;
            cout << current->getName() << "'s Turn" << endl;
            cout << "1. Attack" << endl
                 << "2. Skill" << endl
                 << "3. Item" << endl
                 << "4. Wait" << endl
                 << "Choose an option 1-4: ";
            cin >> menu;
            cout << endl;
            switch (menu)
            {
            case 1:
                mob.displayUnits();
                cout << endl << "Choose a target: ";
                cin >> choice;
                opponent = mob.get(choice);
                current->attack(opponent);
                if (opponent->getHp() == 0)
                {
                    cout << opponent->getName() << " defeated!" << endl;
                    mob.deleteUnitFromList(choice);
                    if (order.searchNode(opponent))
                    {
                        int temp = order.searchNode(opponent);
                        order.deleteUnitFromList(temp);
                    }
                    delete opponent;
                    cout << "You got 300 gold." << endl;
                    money += 300;
                }
                again = false;
                break;
            case 2:
                cout << "Coming soon...";
                break;
            case 3:
                cout << "Coming soon...";
                break;
            case 4:
                again = false;
                cout << current->getName() << " waits." << endl;
                break;
            default:
                cout << "Invalid, try again: ";
                break;
            }

            getch();
            system("cls");
        }
    }
    else
    {
        Unit* opponent;
        mob.fightDisplay();
        cout << endl << endl << endl;
        party.fightDisplay();
        cout << endl << endl;
        int target = rand() % party.getCount() + 1;
        opponent = party.get(target);
        current->attack(opponent);
        if (opponent->getHp() == 0)
        {
            cout << opponent->getName() << " defeated!" << endl;
            mob.deleteUnitFromList(target);
            if (order.searchNode(opponent))
            {
                int temp = order.searchNode(opponent);
                order.deleteUnitFromList(temp);
            }
            Character* deadUnit = (Character*)opponent;
            if (deadUnit->hasEquip())
            {
                Weapon* weapon = deadUnit->getEquip();
                weapon->incrQty();
            }
            delete opponent;
        }
        getch();
        system("cls");
    }

}





bool battle(UnitList& party, UnitList& mob, ItemList& items, int money)
{
    UnitList order;
    Unit* current;
    int i = 0;
    bool endbattle = false;
    while (mob.isEmpty() == false)
    {
        //cout << "debug";

        if (order.isEmpty())
        {
            order.moveListBySpeed(party);
            order.moveListBySpeed(mob);
            //cout << "debug2";
        }
        current = order.get(1);
        order.deleteUnitFromList(1);
        //order.displayUnits();
        fightAction(current, party, mob, order, items, money);
        if (party.noLeader())
        {
            system("cls");
            return true;
        }
        //cout << mob.isEmpty() << endl;
    }
    //cout << "debug out" << endl;
    //cout << "debug out 2" << endl;
    //cout << mob.isEmpty() << endl;
    //mob.~UnitList();
    getch();
    //cout << "debug 3" << en
    return false;
}
