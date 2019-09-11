/*******************************************************************************************
** Program name:  Final Project
** Author:        Alexandru Mocanu
** Date:          08/13/2019
** Description:   Final Project userValidation header file; Method accepts a string and two
                  integers as parameters; converts string to integer and makes sure it is
                  within the range of the other two integers; prompts user for new entry if
                  conditions are not met; once an acceptable entry is made, the number is
                  returned to the program
********************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int userValidation(std::string line, int lower, int upper)
{
    std::stringstream ss(line);
    int select = 0;
    if(ss >> select)
        {//cited from https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
            if(ss.eof())
            {
                if(select >= lower && select <= upper)
                {
                    return select;
                }
            }
        }
        cout << "\tNot a valid entry. Please try again" << endl;

    while(std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        if(ss >> select)
        {//cited from https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
            if(ss.eof())
            {
                if(select >= lower && select <= upper)
                {
                    return select;
                }
            }
        }
        cout << "\tNot a valid entry. Please try again" << endl;
    }
}
