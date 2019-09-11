/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Wood Class implementation file; Wood is a derived class of type Item
********************************************************************************************/

#include <iostream>
#include "wood.hpp"

/**
Class constructor
**/
Wood::Wood(int woodAmount)
{
    woodItem = woodAmount;
}

Wood::~Wood()
{
    //destructor left empty
}
