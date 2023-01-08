#ifndef DICEROLL_H
#define DICEROLL_H
#define NUM_ROLLS 4
#define DICE_SIZE 6
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class DiceRoll
{
    public:
        // Mutators
        void setAttributePoints(int);

        // Accessors
        int getAttributePoints();

        //Methods
        void setAttRollMinusLow(); 
        // Rolls NUM_ROLLS dice of size DICE_SIZE
        // then subtracts the lowest roll.  Sets AttPoints
        // to equal the total of the remaining dice

    private:
        int AttPoints;
};

#endif // DICEROLL_H
