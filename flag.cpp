/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Flag Class implementation file; Flag is a derived class of type Item
********************************************************************************************/

#include <iostream>
#include "flag.hpp"

/**
Class constructor
**/
Flag::Flag()
{
    flagItem = 0;
}

Flag::~Flag()
{
    //destructor left empty
}

/**
Method sets the flagItem variable to 1
**/
void Flag::captureFlag()
{
    flagItem = 1;
}

