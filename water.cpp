/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Water Implementation File - Water is a derived Class of Space Type
********************************************************************************************/

#include <iostream>
#include "water.hpp"

#include "space.hpp"
#include "userValidation.hpp"


using std::cout;
using std::endl;
using std::string;

/**
Class constructor
**/
Water::Water(int numFood, int numH20, std::string place)
{
    food = numFood;
    h2o = numH20;
    name = place;
}

Water::~Water()
{
    //destructor left empty
}

/**
Prints a welcome message
**/
void Water::welcomeMessage()
{
    std::cout << "\n Welcome to " << name << std::endl;
    std::cout << " Food resources " << food << std::endl;
    std::cout << " Fresh water: " << h2o << std::endl;
}

/**
Special action is redefined in the Water Class;
Asks user for the type of action they want to take;
generates random number for the gather water or gathered food
Adjusts action flag variable accordingly
**/
void Water::specialAction()
{
    cout << name << endl;
    cout << "-------------" << endl;
    cout << " Available food to gather: " << food << endl;
    cout << "\n 1. Fish" << endl;
    cout << " 2. Get drinking water" << endl;
    cout << " Action: " << endl;

    string select;
    getline(std::cin, select);
    int selection = userValidation(select, 1, 2);

    if(selection == 1)
    {
        gatheredFood = rand() % 250 + 15;
        food -= gatheredFood;
        cout << " Your party gathered " << gatheredFood << " portions of food" << endl;
        actionFlag = 1;
    }
    else if(selection == 2)
    {
        if(name != "The North Sea")
        {
            gatheredWater = rand() % 250 + 15;
            h2o -= gatheredWater;
            cout << " Your party gathered " << gatheredWater << " liters of fresh water" << endl;
        }
        else
        {
            cout << " You cannot drink salt water silly! Try a river instead (the Danube)" << endl;
        }
        actionFlag = 3;
    }
}
