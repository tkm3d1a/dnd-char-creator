/*************
Fucntions.h
functions header file

by: Tim Klimpel
version Date: 07.29.2015
version num: 0.4
**************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "DiceRoll.h"
#include "Character.h"
#include "Job.h"
#include "Race.h"
#include "Functions.h"
#include <new>
#include <windows.h>

#define NUM_ATTS 6

using namespace std;

Character createNewCharacter();
Character diceRollForStats(Character *testCharPtr);

#endif // FUNCTIONS_H
