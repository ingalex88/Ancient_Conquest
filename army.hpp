/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Army Class header file; Army is a derived class of type Item
********************************************************************************************/

#ifndef ARMY_HPP
#define ARMY_HPP

#include "item.hpp"

class Army : public Item
{
public:
    Army(int);
    ~Army();
};
#endif // ARMY_HPP
