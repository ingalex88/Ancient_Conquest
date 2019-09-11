/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Country Header file - Country is a derived Class of Space type
********************************************************************************************/

#ifndef COUNTRY_HPP
#define COUNTRY_HPP

#include "space.hpp"
#include "item.hpp"

class Country : public Space
{
public:
    Country(int, int, std::string, std::string);
    ~Country();
    void welcomeMessage();
    void specialAction();
};
#endif // COUNTRY_HPP
