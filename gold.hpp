/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Gold Class header file; Gold is a derived class of type Item
********************************************************************************************/

#ifndef GOLD_HPP
#define GOLD_HPP

#include "item.hpp"

class Gold : public Item
{
public:
    Gold(int);
    ~Gold();
};
#endif // GOLD_HPP
