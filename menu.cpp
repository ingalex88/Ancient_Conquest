/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project Menu implementation file
********************************************************************************************/

#include <iostream>
#include "menu.hpp"
#include "space.hpp"
#include "mountain.hpp"
#include "water.hpp"
#include "country.hpp"
#include "army.hpp"
#include "food.hpp"
#include "h2o.hpp"
#include "wood.hpp"
#include "gold.hpp"
#include "flag.hpp"
#include "userValidation.hpp"
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>

using std::cout;
using std::endl;

/**
Default constructor initializes most integers member variables to 0 (except daysRemaining);
Initializes the dir array to get the name of the directions;
Dynamically allocates memory for the Space pointers - assigns the different Space derived classes
and initializes these Objects by using their constructors;
Dynamically allocates memory for the Item pointers in the itemArray pointer; initializes these derived Item objects
**/
Menu::Menu()
{
    day = 1;
    daysRemaining = 105;
    introChoice = 0;
    direction = 0;
    userArmy = 0;
    userFood = 0;
    userH2o = 0;
    userWood = 0;
    userGold = 0;
    userFlag = 0;
    playSelect = 0;
    specialAction = 0;
    dir[0] = "null";
    dir[1] = "NORTH";
    dir[2] = "EAST";
    dir[3] = "WEST";
    dir[4] = "SOUTH";
    userName = "Bob";

    location = nullptr;

    wre = new Country(40000, 650000, "Western Roman Empire", "Caesar");
    ere = new Country(22000, 332000, "Eastern Roman Empire", "Constantine the Great");
    dacia = new Country(1200, 58000, "Dacia", "Rex Decebalus");
    francia = new Country(355, 119000, "Francia", "Charles Martel");
    norse = new Country(650, 17000, "The Norse Kingdom", "Ragnar Lodbrok");
    alps = new Mountain(1350, 85, "The Alps");
    blackMtn = new Mountain(410, 22, "The Black Mountains");
    danube = new Water(330, 600000, "The Danube");
    northSea = new Water(2210, 0, "The North Sea");

    itemArray = new Item*[6];
    itemArray[0] = new Army(12);
    itemArray[1] = new Food(980);
    itemArray[2] = new H2o(520);
    itemArray[3] = new Wood(48);
    itemArray[4] = new Gold(5000);
    itemArray[5] = new Flag;

    srand(time(0));//seeding time in order to use rand function later on
}

/**
Class destructor deallocates the memory that was allocated to the Space and Item pointers
**/
Menu::~Menu()
{
    delete wre;
    delete ere;
    delete dacia;
    delete francia;
    delete norse;
    delete alps;
    delete blackMtn;
    delete danube;
    delete northSea;

    for(int i = 0; i < 6; i++)
    {
        delete itemArray[i];
    }

    delete [] itemArray;
}

/**
Method activates the 4 different directional pointers from the Space class in order to connect the different
Spaces to each other; Border areas are set to nullptr;
Location pointer is set to wre (Western Roman Empire) - this is where the user starts the game
**/
void Menu::initializeMap()
{
    wre->south = nullptr;
    wre->west = nullptr;
    wre->east = ere;
    wre->north = alps;

    ere->south = nullptr;
    ere->west = wre;
    ere->east = nullptr;
    ere->north = danube;

    francia->south = nullptr;
    francia->west = nullptr;
    francia->east = alps;
    francia->north = nullptr;

    alps->south = wre;
    alps->west = francia;
    alps->east = danube;
    alps->north = blackMtn;

    danube->south = ere;
    danube->west = alps;
    danube->east = dacia;
    danube->north = northSea;

    dacia->south = nullptr;
    dacia->west = danube;
    dacia->east = nullptr;
    dacia->north = nullptr;

    northSea->south = danube;
    northSea->west = blackMtn;
    northSea->east = nullptr;
    northSea->north = norse;

    blackMtn->south = alps;
    blackMtn->west = nullptr;
    blackMtn->east = northSea;
    blackMtn->north = nullptr;

    norse->south = northSea;
    norse->west = nullptr;
    norse->east = nullptr;
    norse->north = nullptr;

    location = wre;
}

/**
Calls the previously defined initializeMap() method to set up the map;
Provides a basic game menu by calling methods defined below;
Uses loops to continue certain methods as long as conditions for game ending have not been met
**/
void Menu::startGame()
{
    initializeMap();

    while(introChoice != 3)
    {
        intro();

        if(introChoice == 1)
        {
            instructions();
        }
        else if(introChoice == 2)
        {
            firstPart();

            while(daysRemaining > 0 && introChoice != 3)
            {
                introChoice = play();
            }
            if(daysRemaining < 1)
            {
                cout << "\n\n You ran out of time! You failed your mission and disappointed Caesar" << endl;
                sleep(3);
                cout << " You will be stripped of your title, lands, and dignity!" << endl;
                sleep(2);
                cout << " ...." << userName << " is sent to the arena as food for the lions" << endl;
                cout << "\n\n\n Press ENTER to continue" << endl;
                std::cin.get();
            }
        }
    }
}

/**
Prints message for the user at the start of the game;
Gets user's name;
Uses Item Class member functions to get the values of the Objects inside the array and
places these values in local variables
**/
void Menu::firstPart()
{
    cout << "\n\n\n Greetings brave soul! Caesar has been waiting" << endl;
    sleep(2);
    cout <<  " What is your name? ";
    getline(std::cin, userName);
    sleep(1);
    cout << "\n Ave general " << userName << "!" << endl;
    sleep(2);
    cout << " Caesar has high hopes for you!" << endl;
    sleep(3);
    cout << " To get you started you will receive 12 brave roman praetorian guards" << endl;
    sleep(3);
    cout << " Those are some highly trained soldiers in case you didn't know..." << endl;
    sleep(3);
    cout << " You also receive:\n     - 980 portions of food for your troops" << endl;
    sleep(2);
    cout << "     - 520 liters of fresh drinking water" << endl;
    sleep(2);
    cout << "     - 48 carts of wood" << endl;
    sleep(2);
    cout << "     - 5,000 gold coins from the Empire's coffers" << endl;
    sleep(3);
    cout << " \n\n These should be enough to get you started" << endl;
    sleep(2);
    cout << " Now go! And DO NOT come back without the flag of the fallen Norseman" << endl;
    sleep(2);
    cout << "\n\n\n Press ENTER to continue" << endl;
    std::cin.get();

    userArmy = itemArray[0]->getArmy();
    userFood = itemArray[1]->getFood();
    userH2o = itemArray[2]->getH2o();
    userWood = itemArray[3]->getWood();
    userGold = itemArray[4]->getGold();
}

/**
Main game menu prints options and prompts user to make a selection;
Validates selection stores number in introChoice variable
**/
void Menu::intro()
{
    cout << "\n\n\tAncient Conquest" << endl;
    cout << "\t    by Alexandru Mocanu\n" << endl;
    cout << " 1. Game Instructions" << endl;
    cout << " 2. Start New Game" << endl;
    cout << " 3. Quit\n" << endl;

    cout << " Please make your selection by typing the corresponding number: ";

    std::string choice;
    getline(std::cin, choice);

    introChoice = userValidation(choice, 1, 3);
}

/**
Prints instructions/storyline for the user
**/
void Menu::instructions()
{
    cout << "\n\n" << endl;
    cout << " Welcome to Ancient Conquest!" << endl;
    sleep(1);
    cout << " The year is 231 AD..." << endl;
    sleep(3);
    cout << " Europe is a dangerous place troubled by war and diplomatic instability" << endl;
    sleep(2);
    cout << " Caesar, the ruler of the Western Roman Empire wants to commission you for an important mission" << endl;
    sleep(3);
    cout << " Our scouts have informed us that there is trouble at the northern end of the reach" << endl;
    sleep(3);
    cout << "\n The Norse Kingdom led by King Ragnar keeps raiding our trade routes" << endl;
    sleep(3);
    cout << " This has to stop at once!" << endl;
    sleep(3);
    cout << " Raise an army and head north!\n Defeat Ragnar!\n And bring Caesar the flag of the fallen Norseman" << endl;
    sleep(5);
    cout << "\n\n You will be given a small force and basic supplies to start the game" << endl;
    sleep(2);
    cout << " Your mission is to attack the Norse, destroy their army, and return to the Western Roman Empire with their fallen flag" << endl;
    sleep(5);
    cout << " You can hire soldiers from friendly countries" << endl;
    sleep(4);
    cout << "\n BEWARE! Hiring too many soldiers will prove to be expensive and ruin you" << endl;
    sleep(3);
    cout << " But an inappropriate army will be defeated by the mighty Norseman" << endl;
    sleep(3);
    cout << " They key is balance! Check your stats frequently!" << endl;
    sleep(6);
    cout << "\n Your soldiers need food and fresh water daily" << endl;
    sleep(3);
    cout << " They also need wood to build fires, ships, and shelters, and they require a daily salary" << endl;
    sleep(4);
    cout << " Keep an eye on these supplies and try to replenish as they decrease" << endl;
    sleep(3);
    cout << " If you fail to meet the basic needs of your army, mutiny will develop and the fighters will desert" << endl;
    sleep(5);
    cout << " You can get more gold by trading with different countries" << endl;
    sleep(4);
    cout << " Your party can gather food and water from appropriate places (mountains, bodies of water)" << endl;
    sleep(5);
    cout << "\n Many have tried and failed before you" << endl;
    sleep(4);
    cout << "\n DO YOU HAVE WHAT IT TAKES?" << endl;
    sleep(2);
    cout << "\n Press ENTER to continue" << endl;
    std::cin.get();
}

/**
Calls playMenu method (which asks user for next steps/actions)
Performs actions depending on user's choice;
Returns gameOver variable as 1 if game is won or lost
**/
int Menu::play()
{
    int gameOver = 0;

    printStats();//prints the game stats
    playSelect = playMenu();//gets the user's choice of action

    if(playSelect == 1)//first choice will print the map
    {
        printMap();//method prints the map
        cout << "\n Press ENTER to continue" << endl;
        std::cin.get();
    }
    else if(playSelect == 2)//second choice will open the local options - these are unique to the different Space Classes
    {
        location->specialAction();//calling the Space method specialAction
        specialAction = location->getSpecialActionFlag();//specialAction holds a 'flag' value that will help the program decide what to do based
                                    //on what happened within the special action at the user's location

        if(specialAction == 1)//user wants to gather food
        {
            //adding the gathered food to the item array
            itemArray[1]->foodItem += location->getGatheredFood();
        }
        else if(specialAction == 2)//user wants to gather wood
        {
            //adding the chopped wood to the item array
            itemArray[3]->woodItem += location->getChoppedW();
        }
        else if(specialAction == 3)//user wants to gather drinking water
        {
            //adding the gathered fresh water
            itemArray[2]->h2oItem += location->getGatheredWater();
        }
        else if(specialAction == 4)//user wants to engage in trading
        {
            //adding gold to the item array
            itemArray[4]->goldItem += location->getTradedGold();
        }
        else if(specialAction == 5)//user wants to attack a country
        {
            //adjusting the soldiers that died
            itemArray[0]->armyItem -= location->getCasualties();

            itemArray[5]->flagItem = location->getNorseFlag();//checking the value of Norse Flag after each battle

            if((itemArray[0]->armyItem) < 1)//checking if all of the user's army was defeated
            {
                itemArray[0]->armyItem = 0;
                cout << "\n All your soldiers have been defeated!" << endl;
                sleep(3);
                cout << " The enemy captures you!" << endl;
                cout << " You have lost the game" << endl;
                gameOver = 3;
                return gameOver;
            }
            if(itemArray[5]->flagItem == 1)//lets user know that he has the key to winning the game
            {
                cout << " You have captured the Norse flag! Return to the Western Roman Empire at once" << endl;
            }
        }
        else if(specialAction == 6)//this triggers if the user brings the flag back to the Western Roman Empire
        {
            if(itemArray[5]->flagItem == 1)
            {
                cout << "\n Caesar accepts your offering!" << endl;
                cout << " Congratulations " << userName << endl;
                cout << " You are victorious\n" << endl;
                for(int i = 0; i < 3; i++)
                {
                    cout << " AVE " << userName << endl;
                }
                sleep(5);
                gameOver = 3;
                return gameOver;

            }
            else//if user claims that he has the flag but he does not have it, this message will print
            {
                cout << "\n You fool! Do not come back without the flag of the Norseman!" << endl;
            }
        }
        else if(specialAction == 7)//if user wants to get more soldiers in his army
        {
            int availForHire = (location->army) / 4;
            int canAfford = (availForHire / 2);//making sure there are enough soldiers for hire and that user can afford them

            cout << "\n Cost = 2 gold coin per soldier" << endl;
            cout << " Available for hire: " << availForHire << endl;
            cout << " Your gold coins: " << itemArray[4]->goldItem << endl;
            cout << " You may hire up to " << canAfford << endl;
            sleep(5);
            cout << " Remember to save some gold for salaries" << endl;
            cout << " Enter amount of soldiers to hire: ";

            std::string hire;
            getline(std::cin, hire);
            int hireInt = userValidation(hire, 1, canAfford);
            int totalPrice = hireInt * 2;

            cout << "\n You hired " << hireInt << " soldiers for a total of " << totalPrice << " gold coins" << endl;

            itemArray[0]->armyItem += hireInt; //adjusting the total soldiers
            itemArray[4]->goldItem -= totalPrice;//adjusting the bank
        }

        passDay(1);//calling the pass day function - this originally had a parameter since I originally wanted for different
        //events to take different amount of days but for lack of time and simplicity purposes, all events take 1 day
        cout << "\n\n\n Press ENTER to continue" << endl;
        std::cin.get();
    }
    else if(playSelect == 3)//third major choice (after printing map, and checking the local options)
                    //this will cause the user to travel to a different location
    {
        passDay(1);//traveling will take 1 day
        travelSelect();//calling this method that gets and validates user's travel direction
        travel();//performing the move - this method has a built in code to verify that the user is not trying to
            //travel out of bounds; if that is the case, the method will prompt the user for a different direction of travel
    }
    else if(playSelect == 4)//fourth option entered as a joke - there is no escaping Caesar's demands!
    {
        cout << "\nSurrendering is not an option!!" << endl;
        cout << "\n\n\n Press ENTER to continue" << endl;
        std::cin.get();
    }
}

/**
Method increments the day variable; decrements daysRemaining;
adjusts the food, water, wood, and gold use - this is dependent to the army size;
Checks levels of said items and prints out a message if items are low;
Also eliminates 1/10 of soldiers with every day that supplies are low
**/
void Menu::passDay(int days)
{
    //adjusting the current days and days remaining
    day += days;
    daysRemaining -= days;

    itemArray[1]->foodItem -= (((itemArray[0]->armyItem) / 8) * days);//daily food consumption
    itemArray[2]->h2oItem -=  (((itemArray[0]->armyItem) / 5) * days);//daily water consumption
    itemArray[4]->goldItem -= (((itemArray[0]->armyItem) / 3) * days);//daily gold salary
    itemArray[3]->woodItem -= 1;//daily wood consumption

    if(itemArray[1]->foodItem < 5)
    {
        cout << " Your food supplies are dangerously low" << endl;
        sleep(3);
        cout << " A tenth of your soldiers have deserted you" << endl;

        itemArray[0]->armyItem = (itemArray[0]->armyItem) - ((itemArray[0]->armyItem) / 10);
    }
    if(itemArray[2]->h2oItem < 5)
    {
        cout << " Your water supplies are dangerously low" << endl;
        sleep(3);
        cout << " A tenth of your soldiers have deserted you" << endl;

        itemArray[0]->armyItem = (itemArray[0]->armyItem) - ((itemArray[0]->armyItem) / 10);
    }
    if(itemArray[3]->woodItem < 2)
    {
        cout << " Your wood supplies are dangerously low" << endl;
        sleep(3);
        cout << " A tenth of your soldiers have deserted you" << endl;

        itemArray[0]->armyItem = (itemArray[0]->armyItem) - ((itemArray[0]->armyItem) / 10);
    }
    if(itemArray[4]->goldItem < 100)
    {
        cout << " Your gold supplies are dangerously low" << endl;
        sleep(3);
        cout << " A tenth of your soldiers have deserted you" << endl;

        itemArray[4]->armyItem = (itemArray[4]->armyItem) - ((itemArray[4]->armyItem) / 10);
    }

    //updating the local variables for printing purposes only
    userArmy = itemArray[0]->getArmy();
    userFood = itemArray[1]->getFood();
    userH2o = itemArray[2]->getH2o();
    userWood = itemArray[3]->getWood();
    userGold = itemArray[4]->getGold();

    //adjusting the quantities so we do not display negative numbers
    if(itemArray[0]->armyItem < 1)
    {
        itemArray[0]->armyItem = 0;
    }
    if(itemArray[1]->foodItem < 1)
    {
        itemArray[1]->foodItem = 0;
    }
    if(itemArray[2]->h2oItem < 1)
    {
        itemArray[2]->h2oItem = 0;
    }
    if(itemArray[3]->woodItem < 1)
    {
        itemArray[3]->woodItem = 0;
    }
    if(itemArray[4]->goldItem < 1)
    {
        itemArray[4]->goldItem = 0;
    }

    userArmy = itemArray[0]->getArmy();
    userFood = itemArray[1]->getFood();
    userH2o = itemArray[2]->getH2o();
    userWood = itemArray[3]->getWood();
    userGold = itemArray[4]->getGold();
}

/**
Method prints a menu with a list of available actions after each day
Validates user selection;
Returns selection;
**/
int Menu::playMenu()
{
    cout << "\n General " << userName << ", what are your orders?\n" << endl;
    cout << " 1. Print Map" << endl;
    cout << " 2. Check local options" << endl;
    cout << " 3. Travel" << endl;
    cout << " 4. Surrender and beg Caesar for forgiveness" << endl;
    cout << " \nYour order: ";

    std::string playStr;
    getline(std::cin, playStr);

    int select1 = userValidation(playStr, 1, 4);

    return select1;
}

/**
Prints the stats
**/
void Menu::printStats()
{
    cout << "\n" << endl;
    cout << " ************************ " << endl;
    cout << " Current Day: " << day << endl;
    cout << " Current Location: ";
    location->printLocation();
    cout << " Remaining days to complete the mission : " << daysRemaining << endl;
    cout << " Army: " << userArmy << " soldiers" << endl;
    cout << " Food: "  << userFood << " portions of food" << endl;
    cout << " Water: " << userH2o << " liters of drinking water" << endl;
    cout << " Wood: " << userWood << " tons of wood" << endl;
    cout << " Gold: " << userGold << " coins" << endl;

    if(userFlag == 1)
    {
        cout << " Flag: Banner of the fallen Norseman" << endl;
    }
    else if(userFlag == 0)
    {
        cout << " Flag: ______" << endl;
    }
}

/**
Method sleeps/waits for a designated number of seconds
referenced from http://www.cplusplus.com/reference/thread/this_thread/sleep_for/
**/
void Menu::sleep(int numSeconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(numSeconds));
}

/**
Provides the directions of travel and gets the user's choice
Validates entry; sores entry in direction
**/
int Menu::travelSelect()
{
    printMap();
    cout << " \n\n\t North = 1    East = 2\n\t West = 3    South = 4\n" << endl;
    cout << " Enter the direction in which you would like to travel: ";

    std::string dirStr;
    getline(std::cin, dirStr);

    direction = userValidation(dirStr, 1, 4);

    cout << "\n You entered " << dir[direction] << endl;
}

/**
Method adjusts the location according to the user's choice from the travelSelect() method;
Checks if user is trying to go to an invalid spot and prompts user again if that is the case
**/
void Menu::travel()
{
    if(direction == 1)
    {
        if(location->north == nullptr)
        {
            cout << "\n That is uncharted territory" << endl;
            cout << " Please chose a different location: ";
            travelSelect();
            travel();
        }
        else
        {
            location = location->north;
            location->welcomeMessage();
            sleep(4);
        }
    }
    else if(direction == 2)
    {
        if(location->east == nullptr)
        {
            cout << "\n That is uncharted territory" << endl;
            cout << " Please chose a different location: ";
            travelSelect();
            travel();
        }
        else
        {
            location = location->east;
            location->welcomeMessage();
            sleep(4);
        }
    }
    else if(direction == 3)
    {
        if(location->west == nullptr)
        {
            cout << "\n That is uncharted territory" << endl;
            cout << " Please chose a different location: ";
            travelSelect();
            travel();
        }
        else
        {
            location = location->west;
            location->welcomeMessage();
            sleep(4);
        }
    }
    else if(direction == 4)
    {
        if(location->south == nullptr)
        {
            cout << "\n That is uncharted territory" << endl;
            cout << " Please chose a different location: ";
            travelSelect();
            travel();
        }
        else
        {
            location = location->south;
            location->welcomeMessage();
            sleep(4);
        }
    }
    cout << "\n\n\n Press ENTER to continue" << endl;
    std::cin.get();
}
/**
Prints the map
**/
void Menu::printMap()
{
    cout << "\n" << endl;
    cout << "    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   |    *     *    *    *     NORTH  *  *   *    *  *   *     |" << endl;
    cout << "   | *       *       *                   *                *   |" << endl;
    cout << "   |     *   *   *         *    *   *  *    *  *  *           |" << endl;
    cout << "   |      uncharted territory  * *  *  *    *  *   *    *     |" << endl;
    cout << "   |   *      *    *      *    * *  * THE NORSE KINGDOM * * * |" << endl;
    cout << "   |    *    *     *      *    *            |   *    *    *  *|" << endl;
    cout << "   |   *    *     *      *    *      *      |   *    *    *  *|" << endl;
    cout << "   |  *    *    *     *       *     *   *   |    *  *  *  *   |" << endl;
    cout << "   |     *   * THE BLACK MTN's -----  THE NORTH SEA *  *   * *|" << endl;
    cout << "   |*  *   *     * | *     *     *      *   |  *       *     *|" << endl;
    cout << "   | *    *  *     |    *     *     *       |    *   *   *  * |" << endl;
    cout << "   | FRANCIA --- THE ALPS -----------  THE DANUBE ---- DACIA *|" << endl;
    cout << "   |*   *    *   * |   * *    *     *   *   |  *    *    *  * |" << endl;
    cout << "   |  *   *    *   |  *     *     *    *    |     *    *   *  |" << endl;
    cout << "   |*   *   *    * |    *    *    *    *    |  *     *    *  *|" << endl;
    cout << "   |  *   * THE WESTERN ROMAN   *  *  THE EASTERN ROMAN *  *  |" << endl;
    cout << "   | *  *     * EMPIRE   *   *   *    *   EMPIRE  *    *   *  |" << endl;
    cout << "   |  *    *      *     *    *      *       *      *    *    *|" << endl;
    cout << "   |*    *      *      *      *    *     *     *     *    *   |" << endl;
    cout << "   |   *     *     *      *   SOUTH   *     *    *      *     |" << endl;
    cout << "    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << endl;
    cout << "             ";
    location->printLocation();
}
