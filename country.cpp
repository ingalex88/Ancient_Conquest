/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Country Implementation file - Country is a derived Class of Space type
********************************************************************************************/

#include <iostream>
#include "country.hpp"
#include "userValidation.hpp"

using std::cout;
using std::endl;

/**
Class constructor
**/
Country::Country(int numArmy, int numGold, std::string place, std::string boss)
{
    army = numArmy;
    gold = numGold;
    name = place;
    ruler = boss;
}

Country::~Country()
{
    //destructor
}

/**
Prints a welcome message
**/
void Country::welcomeMessage()
{
    std::cout << "\n Welcome to " << name << std::endl;
    std::cout << " Ruller: " << ruler << std::endl;
    std::cout << " Army count: " << army << std::endl;
    std::cout << " Gold coins in treasury: " << gold << std::endl;
}

/**
SpecialAction offers user action options - Different countries offer different actions;
Adjusts action flag variable accordingly
**/
void Country::specialAction()
{
    cout << name << endl;
    cout << "-------------" << endl;
    cout << " Army: " << army << endl;
    cout << " Gold: " << gold << endl;
    cout << "\n 1. Attack" << endl;
    cout << " 2. Trade" << endl;
    if(name == "Western Roman Empire")
    {
        cout << " 3. Present Great Caesar with the flag of the fallen might Norse for the Glory of the Empire!" << endl;
    }
    else
    {
        cout << " 3. Get a tip" << endl;
    }
    cout << " 4. Hire mercenaries" << endl;
    cout << " Action: ";

    std::string select;
    getline(std::cin, select);
    int selection = userValidation(select, 1, 4);

    if(selection == 1)
    {
        int multiplier = rand() % 16 + 1;
        int enemiesKilled = multiplier * 3;

        cout << " Your multiplier for this battle is " << multiplier << endl;
        cout << " May the gods of War be in your favor!" << endl;

        army -= enemiesKilled;//decreasing the country army size
        casualties = (enemiesKilled / 2) - 3;
        if(casualties < 1)
        {
            casualties = 0;
        }

        cout << " Your brave soldiers killed " << enemiesKilled << " enemies" << endl;
        cout << " You lost " << casualties << " soldiers in this battle" << endl;

        if(name == "The Norse Kingdom")
        {
            if(army < 10)
            {
                norseFlag = 1;
            }
        }
        actionFlag = 5;
    }
    else if(selection == 2)
    {
        tradedGold += (rand() % 189 + 1);//generating a random trading profit
        gold -= tradedGold;//updating the amount of gold left in the country
        cout << " Your merchants managed to earn a profit of " << tradedGold << " gold coins during trading" << endl;
        actionFlag = 4;
    }
    else if(selection == 3)
    {
        if(name == "Western Roman Empire")
        {
            cout << " Did you bring the flag to Caesar?" << endl;
            actionFlag = 6;

        }
        else
        {
            cout << " Out of ice? ...Just freeze some water" << endl;
        }
    }
    else if(selection == 4)
    {
        actionFlag = 7;
    }
}
