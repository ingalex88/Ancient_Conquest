/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Space class implementation file
********************************************************************************************/

#include <iostream>
#include "space.hpp"

/**
Default constructor initializes pointer to nullptr;
int variables to 0;
strings to blank;
**/
Space::Space()
{
    north = nullptr;
    east = nullptr;
    west = nullptr;
    south = nullptr;

    army = 0;
    food = 0;
    h2o = 0;
    wood = 0;
    gold = 0;

    choppedWood = 0;
    gatheredFood = 0;
    gatheredWater = 0;
    tradedGold = 0;
    casualties = 0;
    actionFlag = 0;
    norseFlag = 0;

    name = " ";
    ruler = " ";
}

Space::~Space()
{
    //destructor left empty
}

/**
Prints a message containing the name of the location
**/
void Space::printLocation()
{
    std::cout << " You are located in " << name << std::endl;
}

int Space::getSpecialActionFlag()
{
    return actionFlag;
}

int Space::getChoppedW()
{
    return choppedWood;
}

int Space::getGatheredFood()
{
    return gatheredFood;
}

int Space::getGatheredWater()
{
    return gatheredWater;
}

int Space::getTradedGold()
{
    return tradedGold;
}

int Space::getCasualties()
{
    return casualties;
}

int Space::getNorseFlag()
{
    return norseFlag;
}
