/************************
main.cpp
"Character Creation"

by: Tim Klimpel
version Date: 07.29.2015
version num: 0.5
*************************/

/*
 *     Welcome to character creation!  This program allows for the creation of characters, including
 *  the race, job and name of the character.  The race and job of the created character both contribute
 *  up to 80% of modifications across the 6 attributes.  Once the base character is made, the program rolls
 *  4, 6 sided dice, 6 times (once for each stat) and then the user picks which stat gets which dice roll.
 *  This completes the character creation.  The user is then prompted to either save the character to an easy
 *  to read file (simple save option) or to save the character as an easy to parse file (export option).
 *  After that the user can exit, or even create a new character.
 *     This is a prototype style of program with no true application yet, but I plan to integrate it into use
 *  for another style of text based RPG game.  The idea isnt fully fleshed out yet though.
 *
 */

#include "Functions.h"

int main()
{
    // Initial setup of new character for use by user
    Character *testCharPtr = NULL;
    testCharPtr = new (nothrow) Character;
    if(testCharPtr == NULL)
    {
        cout << "Error allocating memory" << endl;
    }

    // Menu operation
    int menuChoice;
    cout << "Welcome to the character Creation Program!" << endl << endl;

    do
    {
        cout << "1: New Char\n2: Save Char\n3: Export Char\n4: Exit" << endl;
        cout << "Enter menu choice: ";
        cin >> menuChoice;

        // Switch statement using the menuChoice as input
        switch(menuChoice)
        {
        case 1: // Creating a new character (overwrites current character in memory)
            system("cls");
            *testCharPtr = createNewCharacter();
            system("cls");
            cout << setfill('-') << setw(28) << "-" << endl;
            cout << " Char with name/job/race... \n" << setw(28) << "-" << endl;
            cout << testCharPtr->printCharInfo() << endl;
            break;
        case 2: // Save Character
            cout << "\nSaving character...\n";
            cout << "File Name: " << testCharPtr->printCharInfo(testCharPtr->getCharName());
            cout << "\nCharacter saved!\n";
            break;
        case 3: // Export character to file
            cout << "\nExporting character...\n";
            cout << "File Name: " << testCharPtr->exportCharInfo();
            cout << "\nExport Complete!\n";
            break;
        case 4: // Exit
            cout << "Exiting program...\n";
            break;
        default:
            break;
        }

        cout << endl;

    }while(menuChoice != 4);



    // memory cleanup
    delete testCharPtr;
    return 0;
}
