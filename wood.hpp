/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Wood Class header file; Wood is a derived class of type Item
********************************************************************************************/

#ifndef WOOD_HPP
#define WOOD_HPP

#include "item.hpp"

class Wood : public Item
{
public:
    Wood(int);
    ~Wood();
};
#endif // WOOD_HPP
