/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Mountain Header File - Mountain is a derived Class of Space Type
********************************************************************************************/

#ifndef MOUNTAIN_HPP
#define MOUNTAIN_HPP

#include "space.hpp"

class Mountain : public Space
{
public:
    Mountain(int, int, std::string);
    ~Mountain();
    void welcomeMessage();
    void specialAction();
};
#endif // MOUNTAIN_HPP
