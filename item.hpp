/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Item Class header file; Item is a base class
********************************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
public:
    int armyItem;
    int foodItem;
    int h2oItem;
    int woodItem;
    int goldItem;
    int flagItem;

    Item();
    ~Item();
    int getArmy();
    int getFood();
    int getH2o();
    int getWood();
    int getGold();
    int getFlag();
};
#endif // ITEM_HPP
