/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Flag Class header file; Flag is a derived class of type Item
********************************************************************************************/

#ifndef FLAG_HPP
#define FLAG_HPP

#include "item.hpp"

class Flag : public Item
{
public:
    Flag();
    ~Flag();
    void captureFlag();
};
#endif // FLAG_HPP
