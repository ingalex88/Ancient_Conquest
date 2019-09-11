/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Water Header File - Water is a derived Class of Space Type
********************************************************************************************/

#ifndef WATER_HPP
#define WATER_HPP

#include "space.hpp"

class Water : public Space
{
public:
    Water(int, int, std::string);
    ~Water();
    void welcomeMessage();
    void specialAction();
};
#endif // WATER_HPP
