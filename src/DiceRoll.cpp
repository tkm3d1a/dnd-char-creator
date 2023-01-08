/*************
DiceRoll.cpp
Dice Rolling Mechanics/Class

by: Tim Klimpel
version Date: 07.24.2015
version num: 0.1
**************/
#include "DiceRoll.h"

// Mutators
void DiceRoll::setAttributePoints(int totalPoints)
{
    AttPoints = totalPoints;
}

void DiceRoll::setAttRollMinusLow()
{
    int rolls[NUM_ROLLS];
    int rollTotal = 0, lowRoll = DICE_SIZE;
    int i;

    srand(time(NULL));

    // Make NUM_ROLLS dice rolls of a DICE_SIZE faced dice
    for(i = 0; i < NUM_ROLLS; i++)
    {
        rolls[i] = rand()%DICE_SIZE + 1;
        if(rolls[i] < lowRoll)
            lowRoll = rolls[i];
        rollTotal += rolls[i];
        //cout << "Roll #" << i << ": " << rolls[i] << endl; //debug check
    }
    //cout << "lowRoll: " << lowRoll << endl; // debug check


    // Subtract lowest roll from roll total
    rollTotal -= lowRoll;

    // Set available attribute points to the total from the rolls
    AttPoints = rollTotal;
}

// Accessors
int DiceRoll::getAttributePoints()
{
    return AttPoints;
}
