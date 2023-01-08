/*************
Race.cpp
Race Class

by: Tim Klimpel
version Date: 07.28.2015
version num: 0.3
**************/

#include "Race.h"

/*******************
/// Constructors ///
*******************/
Race::Race() // Base "no race" with 0% total modifiers
{
    raceName = "BASE_RACE_MODIFIERS";
    constitutionModR = 1;
    strengthModR = 1;
    dexterityModR = 1;
    intelligenceModR = 1;
    wisdomModR = 1;
    perceptionModR = 1;
}

Race::Race(string choice) // Race with a selection made, 80% total modifiers
{
    int raceNum = raceCheck(choice);
    int i;
    int length = choice.length();

    // Format race name to come out with the first letter capitalized
    for(i = 0; i < length ; i++)
    {
        choice[i] = tolower(choice[i]);
    }
    choice[0] = toupper(choice[0]);
    raceName = choice;

    // Use switch to assign modifiers.  All races have a total
    // of 80% bonus between all modifiers.  If an invalid race
    // is selected, the user will receive no modifiers
    switch(raceNum)
    {
        case 1: //Human Modifiers
            constitutionModR = 1.13;
            strengthModR = 1.12;
            dexterityModR = 1.15;
            intelligenceModR = 1.13;
            wisdomModR = 1.15;
            perceptionModR = 1.12;
            break;
        case 2: //Elf Modifiers
            constitutionModR = 1.05;
            strengthModR = 1.05;
            dexterityModR = 1.2;
            intelligenceModR = 1.1;
            wisdomModR = 1.25;
            perceptionModR = 1.15;
            break;
        case 3: //Orc Modifiers
            constitutionModR = 1.3;
            strengthModR = 1.3;
            dexterityModR = 1.05;
            intelligenceModR = 1.05;
            wisdomModR = 1.05;
            perceptionModR = 1.05;
            break;
        case 4: //Dragonborn Modifiers
            constitutionModR = 1.1;
            strengthModR = 1.2;
            dexterityModR = 1.1;
            intelligenceModR = 1.25;
            wisdomModR = 1.1;
            perceptionModR = 1.05;
            break;
        default: //Default race if an invalid race is selected
            constitutionModR = 1;
            strengthModR = 1;
            dexterityModR = 1;
            intelligenceModR = 1;
            wisdomModR = 1;
            perceptionModR = 1;
            cout << "ERROR: Invalid race selection.  All mods set to 0" << endl;
            break;
    }
}

/*********************************************
// Mutators of stat modifiers and race name //
*********************************************/
void Race::setRaceName(string enterName)
{
    raceName = enterName;
}

bool Race::setConstModR(double cMod)
{
    if(cMod>0)
    {
        constitutionModR = cMod;
        return true;
    }
    cout << "ERROR: Cannot set modifier to negative value" << endl;
    return false;
}

bool Race::setStrModR(double sMod)
{
    if(sMod>0)
    {
        strengthModR = sMod;
        return true;
    }
    cout << "ERROR: Cannot set modifier to negative value" << endl;
    return false;

}

bool Race::setDexModR(double dMod)
{
    if(dMod>0)
    {
        dexterityModR = dMod;
        return true;
    }
    cout << "ERROR: Cannot set modifier to negative value" << endl;
    return false;

}

bool Race::setIntModR(double iMod)
{
    if(iMod>0)
    {
        intelligenceModR = iMod;
        return true;
    }
    cout << "ERROR: Cannot set modifier to negative value" << endl;
    return false;

}

bool Race::setWisModR(double wMod)
{
    if(wMod>0)
    {
        wisdomModR = wMod;
        return true;
    }
    cout << "ERROR: Cannot set modifier to negative value" << endl;
    return false;

}

bool Race::setPerModR(double pMod)
{
    if(pMod>0)
    {
        perceptionModR = pMod;
        return true;
    }
    cout << "ERROR: Cannot set modifier to negative value" << endl;
    return false;

}

/**********************************************
// Accessors of stat modifiers and race name //
**********************************************/
string Race::getRaceName(){return raceName;}

double Race::getConstModR(){return constitutionModR;}

double Race::getStrModR(){return strengthModR;}

double Race::getDexModR(){return dexterityModR;}

double Race::getIntModR(){return intelligenceModR;}

double Race::getWisModR(){return wisdomModR;}

double Race::getPerModR(){return perceptionModR;}

/************
// Methods //
************/

void Race::printAllRaceMod()
{
    cout.precision(2);
    cout << fixed;
    cout << setfill('-') << setw(36) << "-" << endl;
    cout << setfill(' ') << setw(11) << right << "HUMAN" << setw(8) << right << " X " << setw(9) << right <<  "ELF" << endl;
    cout << "Cnst" << setw(6) << right << "Str" << setw(6) << right << "Dex" << " X "
        << "Cnst" << setw(6) << right << "Str" << setw(6) << right << "Dex" << endl;
    cout << 1.13 << setw(6) << right << 1.12 << setw(6) << right << 1.15 << " X "
        << 1.05 << setw(6) << right << 1.05 << setw(6) << right << 1.20 << endl;
    cout << " Int" << setw(6) << right << "Wis" << setw(6) << right << "Per" << " X "
        << " Int" << setw(6) << right << "Wis" << setw(6) << right << "Per" << endl;
    cout << 1.13 << setw(6) << right << 1.15 << setw(6) << right << 1.12 << " X "
        << 1.10 << setw(6) << right << 1.25 << setw(6) << right << 1.15 << endl;

    cout << setfill('-') << setw(36) << "-" << endl;
    cout << setfill(' ') << setw(10) << right << "ORC" << setw(9) << right << " X " << setw(13) << right <<  "DRAGONBORN" << endl;
    cout << "Cnst" << setw(6) << right << "Str" << setw(6) << right << "Dex" << " X "
        << "Cnst" << setw(6) << right << "Str" << setw(6) << right << "Dex" << endl;
    cout << 1.30 << setw(6) << right << 1.30 << setw(6) << right << 1.05 << " X "
        << 1.10 << setw(6) << right << 1.20 << setw(6) << right << 1.10 << endl;
    cout << " Int" << setw(6) << right << "Wis" << setw(6) << right << "Per" << " X "
        << " Int" << setw(6) << right << "Wis" << setw(6) << right << "Per" << endl;
    cout << 1.05 << setw(6) << right << 1.05 << setw(6) << right << 1.05 << " X "
        << 1.25 << setw(6) << right << 1.10 << setw(6) << right << 1.05 << endl;
    cout << setfill('-') << setw(36) << "-" << endl;
}
/**********************
// Private Functions //
**********************/

/*
*   raceCheck(string)
*
*   raceCheck returns an int to allow for switching based on
*   what race the user selects for their character.
*/
int Race::raceCheck(string raceChoice)
{
    int num = 0;
    int i;
    int length = raceChoice.length();

    // converts race to all lower for easier comparing
    for(i = 0; i < length; i++)
    {
        raceChoice[i] = tolower(raceChoice[i]);
    }

    // If else chain to assign numbers to race types
    if(raceChoice == "human")
        num = 1;
    else if(raceChoice == "elf")
        num = 2;
    else if(raceChoice == "orc")
        num = 3;
    else if(raceChoice == "dragonborn")
        num = 4;
    else
        num = -1;

    return num;
}
