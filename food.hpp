/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Food Class header file; Food is a derived class of type Item
********************************************************************************************/

#ifndef FOOD_HPP
#define FOOD_HPP

#include "item.hpp"

class Food : public Item
{
public:
    Food(int);
    ~Food();
};
#endif // FOOD
