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

    for(i = 0; i < NUM_ROLLS; i++)
    {
        rolls[i] = rand()%DICE_SIZE + 1;
        if(rolls[i] < lowRoll)
            lowRoll = rolls[i];
        rollTotal += rolls[i];
    }

    rollTotal -= lowRoll;
    AttPoints = rollTotal;
}

// Accessors
int DiceRoll::getAttributePoints()
{
    return AttPoints;
}
