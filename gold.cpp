/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Gold Class implementation file; Gold is a derived class of type Item
********************************************************************************************/

#include <iostream>
#include "gold.hpp"

/**
Class constructor
**/
Gold::Gold(int goldAmount)
{
    goldItem = goldAmount;
}

Gold::~Gold()
{
    //destructor left empty
}
