/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Item Class implementation file; Item is a base class
********************************************************************************************/

#include <iostream>
#include "item.hpp"

/**
Class constructor
**/
Item::Item()
{
    armyItem = 0;
    foodItem = 0;
    h2oItem = 0;
    woodItem = 0;
    goldItem = 0;
    flagItem = 0;
}

Item::~Item()
{
    //destructor left empty
}

int Item::getArmy()
{
    return armyItem;
}

int Item::getFood()
{
    return foodItem;
}

int Item::getH2o()
{
    return h2oItem;
}

int Item::getWood()
{
    return woodItem;
}

int Item::getGold()
{
    return goldItem;
}

int Item::getFlag()
{
    return flagItem;
}
