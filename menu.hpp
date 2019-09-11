/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Menu header file; Menu class brings the other classes together
                  to run the game
********************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "space.hpp"
#include "item.hpp"

class Menu
{
private:
    int day;//holds the current day
    int daysRemaining;//holds remaining days until user has to finish game
    int direction;//used to determine where the user will go on the map

    //the following hold numbers of items in the user inventory
    //this is for simplicity and display purposes as base Class Item
    //was created to represent and manipulate these objects
    int userArmy;
    int userFood;
    int userH2o;
    int userWood;
    int userGold;
    int userFlag;

    //holds direction names (NORTH< SOUTH, etc)
    std::string dir[5];
    //Pointer to Space object - keeps track of where the user is currently located
    Space* location;

    int introChoice;//holds one of the initial user choices
    int playSelect;//holds user selection early on in the game
    int specialAction;//will hold the type of special action (gather food, gather wood, etc)
    std::string userName;//holds the player's name

    //The following are Space base class pointers that will be initiated with the specific subclasses
    //(country, mountain, water)
    Space* wre;
    Space* ere;
    Space* dacia;
    Space* francia;
    Space* norse;
    Space* alps;
    Space* danube;
    Space* blackMtn;
    Space* northSea;

    Item** itemArray;//pointer will point to an array that will hold pointer to Item objects
                    //this will hold user's inventory of objects


public:
    Menu();
    ~Menu();
    void initializeMap();
    void startGame();
    void firstPart();
    void intro();
    void instructions();
    void sleep(int);
    int play();
    int playMenu();
    void passDay(int);
    void printStats();
    int travelSelect();
    void travel();
    void printMap();
};
#endif // MENU
