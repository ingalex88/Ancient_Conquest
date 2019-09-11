/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Food Class implementation file; Food is a derived class of type Item
********************************************************************************************/

#include <iostream>
#include "food.hpp"

/**
Class constructor
**/
Food::Food(int foodAmmount)
{
    foodItem = foodAmmount;
}

Food::~Food()
{
    //constructor left empty
}
