/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Space Class; Space is an abstract base class;
********************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

class Space
{
protected:
    int food;
    int h2o;
    int wood;
    int gold;
    int actionFlag;
    int choppedWood;
    int gatheredFood;
    int gatheredWater;
    int tradedGold;
    int casualties;
    int norseFlag;

    std::string name;//holds name of the space
    std::string ruler;

public:
    Space();
    ~Space();
    virtual void welcomeMessage() = 0;//pure virtual function
    void printLocation();
    virtual void specialAction() = 0;//pure virtual function
    int getSpecialActionFlag();
    int getChoppedW();
    int getGatheredFood();
    int getGatheredWater();
    int getTradedGold();
    int getCasualties();
    int getNorseFlag();
    int army;

    //space pointers to represent up, down, left, right
    Space* north;
    Space* east;
    Space* west;
    Space* south;
};
#endif // SPACE_HPP
