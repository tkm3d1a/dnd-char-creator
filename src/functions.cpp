/*************
functions.cpp
functions implementation file

by: Tim Klimpel
version Date: 07.29.2015
version num: 0.5
**************/

#include "Functions.h"


// createNewCharacter()
// inputs: none
// outputs: New, filled in character class
//
// use: Creating a brand spanking new, shiny character
Character createNewCharacter()
{
    Character *newChar = NULL;
    string choiceN, choiceJ, choiceR;

    cin.ignore();
    cout << "\nChar name: ";
    getline(cin, choiceN);
    cout << endl;
    system("cls");
    //Display race options//
    newChar->printAllRaceMod();
    cout << "Race selection: ";
    getline(cin, choiceR);
    cout << endl;
    system("cls");
    //Display job options//
    newChar->printAllJobMods();
    cout << "Job selection: ";
    getline(cin, choiceJ);
    cout << endl;
    system("cls");

    newChar = new (nothrow) Character(choiceN,choiceJ,choiceR);
    if(newChar == NULL) // Memory check
    {
        cout << "Error allocating memory" << endl;
    }

    *newChar = diceRollForStats(newChar);

    return *newChar;
}

// diceRollForStats()
// inputs: Previously created/to be modified character object
// outputs: a character object that is used to update the original input character
//
// use: This function is used to roll the dice for stat points, and then allows the user to choose what roll
//  to apply to each stat.  If the user selects a previously used dice roll, they are prompted to make another choice
Character diceRollForStats(Character *charPtr)
{
    Character *inFuncChar = NULL;
    DiceRoll testRoller[NUM_ATTS];
    string stats[] = {"Constitution","Strength","Dexterity","Intelligence","Wisdom","Perception"};
    int rollSelect = 0,i;
    int con = 10,str = 10,dex = 10,intel = 10,wis = 10,per = 10;
    bool previousRoll[] = {false,false,false,false,false,false};
    bool goodChoice = true;

    // Use input character object to make a dummy object for modifying in the function
    inFuncChar = new (nothrow) Character(charPtr->getCharName(),charPtr->getJob(),charPtr->getRace());
    if(inFuncChar == NULL) // Memory check
    {
        cout << "Error allocating memory" << endl;
    }


    cout << endl;


    // Using for loop to conduct rolls for specified number of attributes
    for(i = 0; i < NUM_ATTS; i++) // Complete NUM_ATTS dice rolls
    {
        //cout << "Press Enter to roll...";
        //cin.ignore();
        testRoller[i].setAttRollMinusLow();
        cout << "Att. Points for Roll# " << i+1 << ": " << testRoller[i].getAttributePoints() << endl;
        sleep(1);
    }
    cout << "\n\n";

    // Constitution selection
    cout << "What roll would you like to apply to your " << stats[0] << "? ";
    cin >> rollSelect;
    do{
        if(rollSelect <= 6 || rollSelect >=1)
        {
            if(previousRoll[rollSelect-1])
            {
                rollSelect = -1;
                goodChoice = false;
            } else {
                previousRoll[rollSelect-1] = true;
                goodChoice = true;
            }
        }

        switch(rollSelect)
        {
            case 1:
                con = testRoller[0].getAttributePoints();
                break;
            case 2:
                con = testRoller[1].getAttributePoints();
                break;
            case 3:
                con = testRoller[2].getAttributePoints();
                break;
            case 4:
                con = testRoller[3].getAttributePoints();
                break;
            case 5:
                con = testRoller[4].getAttributePoints();
                break;
            case 6:
                con = testRoller[5].getAttributePoints();
                break;
            default:
                cout << "That roll does not exist or has already been used. Please enter a new roll: ";
                cin >> rollSelect;
                goodChoice = false;
                break;

        }
    }while(!goodChoice);

    // Strength selection
    cout << "What roll would you like to apply to your " << stats[1] << "? ";
    cin >> rollSelect;
    do{
        if(rollSelect <= 6 || rollSelect >=1)
        {
            if(previousRoll[rollSelect-1])
            {
                rollSelect = -1;
                goodChoice = false;
            } else {
                previousRoll[rollSelect-1] = true;
                goodChoice = true;
            }
        }

        switch(rollSelect)
        {
            case 1:
                str = testRoller[0].getAttributePoints();
                break;
            case 2:
                str = testRoller[1].getAttributePoints();
                break;
            case 3:
                str = testRoller[2].getAttributePoints();
                break;
            case 4:
                str = testRoller[3].getAttributePoints();
                break;
            case 5:
                str = testRoller[4].getAttributePoints();
                break;
            case 6:
                str = testRoller[5].getAttributePoints();
                break;
            default:
                cout << "That roll does not exist or has already been used.\n Please enter a new roll: ";
                cin >> rollSelect;
                goodChoice = false;
                break;

        }
    }while(!goodChoice);

    // Dexterity selection
    cout << "What roll would you like to apply to your " << stats[2] << "? ";
    cin >> rollSelect;
    do{
        if(rollSelect <= 6 || rollSelect >=1)
            {
                if(previousRoll[rollSelect-1])
                {
                    rollSelect = -1;
                    goodChoice = false;
                } else {
                    previousRoll[rollSelect-1] = true;
                    goodChoice = true;
                }
            }
        switch(rollSelect)
        {
            case 1:
                dex = testRoller[0].getAttributePoints();
                break;
            case 2:
                dex = testRoller[1].getAttributePoints();
                break;
            case 3:
                dex = testRoller[2].getAttributePoints();
                break;
            case 4:
                dex = testRoller[3].getAttributePoints();
                break;
            case 5:
                dex = testRoller[4].getAttributePoints();
                break;
            case 6:
                dex = testRoller[5].getAttributePoints();
                break;
            default:
                cout << "That roll does not exist or has already been used.\n Please enter a new roll: ";
                cin >> rollSelect;
                goodChoice = false;
                break;
        }
    }while(!goodChoice);

    // Intelligence selection
    cout << "What roll would you like to apply to your " << stats[3] << "? ";
    cin >> rollSelect;
    do{
        if(rollSelect <= 6 || rollSelect >=1)
            {
                if(previousRoll[rollSelect-1])
                {
                    rollSelect = -1;
                    goodChoice = false;
                } else {
                    previousRoll[rollSelect-1] = true;
                    goodChoice = true;
                }
            }
        switch(rollSelect)
        {
            case 1:
                intel = testRoller[0].getAttributePoints();
                break;
            case 2:
                intel = testRoller[1].getAttributePoints();
                break;
            case 3:
                intel = testRoller[2].getAttributePoints();
                break;
            case 4:
                intel = testRoller[3].getAttributePoints();
                break;
            case 5:
                intel = testRoller[4].getAttributePoints();
                break;
            case 6:
                intel = testRoller[5].getAttributePoints();
                break;
            default:
                cout << "That roll does not exist or has already been used.\n Please enter a new roll: ";
                cin >> rollSelect;
                goodChoice = false;
                break;

        }
    }while(!goodChoice);

    // Wisdom selection
    cout << "What roll would you like to apply to your " << stats[4] << "? ";
    cin >> rollSelect;
    do{
        if(rollSelect <= 6 || rollSelect >=1)
            {
                if(previousRoll[rollSelect-1])
                {
                    rollSelect = -1;
                    goodChoice = false;
                } else {
                    previousRoll[rollSelect-1] = true;
                    goodChoice = true;
                }
            }
        switch(rollSelect)
        {
            case 1:
                wis = testRoller[0].getAttributePoints();
                break;
            case 2:
                wis = testRoller[1].getAttributePoints();
                break;
            case 3:
                wis = testRoller[2].getAttributePoints();
                break;
            case 4:
                wis = testRoller[3].getAttributePoints();
                break;
            case 5:
                wis = testRoller[4].getAttributePoints();
                break;
            case 6:
                wis = testRoller[5].getAttributePoints();
                break;
            default:
                cout << "That roll does not exist or has already been used.\n Please enter a new roll: ";
                cin >> rollSelect;
                goodChoice = false;
                break;
        }
    }while(!goodChoice);

    // Perception selection
    cout << "What roll would you like to apply to your " << stats[5] << "? ";
    cin >> rollSelect;
    do{
        if(rollSelect <= 6 || rollSelect >=1)
            {
                if(previousRoll[rollSelect-1])
                {
                    rollSelect = -1;
                    goodChoice = false;
                } else {
                    previousRoll[rollSelect-1] = true;
                    goodChoice = true;
                }
            }
        switch(rollSelect)
        {
            case 1:
                per = testRoller[0].getAttributePoints();
                break;
            case 2:
                per = testRoller[1].getAttributePoints();
                break;
            case 3:
                per = testRoller[2].getAttributePoints();
                break;
            case 4:
                per = testRoller[3].getAttributePoints();
                break;
            case 5:
                per = testRoller[4].getAttributePoints();
                break;
            case 6:
                per = testRoller[5].getAttributePoints();
                break;
            default:
                cout << "That roll does not exist or has already been used.\n Please enter a new roll: ";
                cin >> rollSelect;
                goodChoice = false;
                break;
        }
    }while(!goodChoice);

    //Assign chosen points to the stats for dummy character
    inFuncChar->assignAttPoints(con,str,dex,intel,wis,per);

    return *inFuncChar; //Return pointer to update out of function object
}
