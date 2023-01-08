/*************
Character.h
Character Class

by: Tim Klimpel
version Date: 07.28.2015
version num: 0.3
**************/

#ifndef CHARACTER_H
#define CHARACTER_H
#include <sstream>
#include <fstream>
#include "Job.h"
#include "Race.h"

/*****
* Character class
* inherits: Job, Race
*
* Used to create final characters using modification values from
* both the job and race class
******/

class Character:public Job, public Race
{
    public:
        // Constructors
        Character(); // Default character with no race,no job, and no name
        Character(string); //default character with no race or job, but a char name
        Character(string,string,string); //fully fleshed out character, with base stats of 10

        // Mutators
        // All these mutators get the stats WITH modification values from
        // job and race selection
        void setRace(string);
        void setJob(string);
        void setCharName(string);
        void setConst(double);
        void setStr(double);
        void setDex(double);
        void setInt(double);
        void setWis(double);
        void setPer(double);

        // Accessors
        string getRace();
        string getJob();
        string getCharName();
        double getConst();
        double getStr();
        double getDex();
        double getInt();
        double getWis();
        double getPer();
//        int getExportCount() const
//            {return charExportCount;}

        // Methods
        string printCharInfo();//formatted for a user to read in console
        string printCharInfo(string);//charName, same format as no param but prints to file
        string exportCharInfo();//fileName, format designed for ease of reading by another program
        void assignAttPoints(int,int,int,int,int,int);//const,str,dex,int,wis,per



    private:
        string race;
        string job;
        string name;
        double constitution;
        double strength;
        double dexterity;
        double intelligence;
        double wisdom;
        double perception;

        // Static member variable
        //static int charExportCount;
};

//int Character::charExportCount = 0;

#endif // CHARACTER_H
