/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project H2o Class Implementation file; H2o is a derived class of type Item
********************************************************************************************/

#include <iostream>
#include "h2o.hpp"

/**
Class constructor
**/
H2o::H2o(int waterSupply)
{
    h2oItem = waterSupply;
}

H2o::~H2o()
{
    //destructor left empty
}
