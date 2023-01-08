/*************
Race.h
Race Class

by: Tim Klimpel
version Date: 07.28.2015
version num: 0.3
**************/

#ifndef RACE_H
#define RACE_H
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Race
{
    public:
        // Constructors
        Race();
        Race(string);

        // Mutators
        void setRaceName(string);
        bool setConstModR(double);
        bool setStrModR(double);
        bool setDexModR(double);
        bool setIntModR(double);
        bool setWisModR(double);
        bool setPerModR(double);

        // Accessors
        string getRaceName();
        double getConstModR();
        double getStrModR();
        double getDexModR();
        double getIntModR();
        double getWisModR();
        double getPerModR();

        // Methods
        void printAllRaceMod();

    private:
        string raceName;
        double constitutionModR;
        double strengthModR;
        double dexterityModR;
        double intelligenceModR;
        double wisdomModR;
        double perceptionModR;

        // Private method
        // Used to change a race string into an Int to allow use of switch in constructor
        // Easier to handle and write statement for setting default mod values
        int raceCheck(string);
};

#endif // RACE_H
