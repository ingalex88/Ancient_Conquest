/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Army Class header file; Army is a derived class of type Item
********************************************************************************************/

#include <iostream>
#include "army.hpp"

/**
Class constructor
**/
Army::Army(int soldiers)
{
    armyItem = soldiers;
}

Army::~Army()
{
    //destructor left empty
}
