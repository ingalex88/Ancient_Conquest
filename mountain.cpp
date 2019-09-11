/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Mountain Implementation File - Mountain is a derived Class of Space Type
********************************************************************************************/


#include <iostream>
#include "mountain.hpp"
#include "userValidation.hpp"
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

/**
Class constructor
**/
Mountain::Mountain(int numFood, int numWood, std::string place)
{
    food = numFood;
    wood = numWood;
    name = place;
}

Mountain::~Mountain()
{
    //destructor left empty
}

/**
Prints a welcome message
**/
void Mountain::welcomeMessage()
{
    std::cout << "\n Welcome to " << name << std::endl;
    std::cout << " Food resources " << food << std::endl;
    std::cout << " Wood resources " << wood << std::endl;
}

/**
Special action is redefined in the Mountain Class;
Asks user for the type of action they want to take;
generates random number for the gather wood or gathered food
Adjusts action flag variable accordingly
**/
void Mountain::specialAction()
{
    cout << name << endl;
    cout << "-------------" << endl;
    cout << " Available wood to chop: " << wood << endl;
    cout << " Available food to gather: " << food << endl;
    cout << "\n 1. Chop wood" << endl;
    cout << " 2. Gather food" << endl;
    cout << " Action: ";

    string select;
    getline(std::cin, select);
    int selection = userValidation(select, 1, 2);

    if(selection == 1)
    {
        choppedWood = (rand() % 26 + 1);
        wood -= choppedWood;
        cout << "\n Your party chopped " << choppedWood << " tons of wood" << endl;
        actionFlag = 2;
    }
    else if(selection == 2)
    {
        gatheredFood = (rand() % 120 + 12);
        food -= gatheredFood;
        cout << " Your party gathered " << gatheredFood << " portions of food" << endl;
        actionFlag = 1;
    }
}
