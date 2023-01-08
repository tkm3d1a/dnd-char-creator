/*************
Job.cpp
Job Class

by: Tim Klimpel
version Date: 07.29.2015
version num: 0.4
**************/

#include "Job.h"

/*******************
/// Constructors ///
*******************/
Job::Job()
{
    // Base "no job" with 0% total modifiers
    jobName = "BASE_JOB_MODIFIERS";
    constitutionModJ = 1;
    strengthModJ = 1;
    dexterityModJ = 1;
    intelligenceModJ = 1;
    wisdomModJ = 1;
    perceptionModJ = 1;
}

Job::Job(string choice)
{
    int jobNum = jobCheck(choice);
    int i;
    int length = choice.length();

    for(i = 0; i < length ; i++)
    {
        choice[i] = tolower(choice[i]);
    }

    choice[0] = toupper(choice[0]);
    jobName = choice;

    // Use switch to assign modifiers.  All jobs have a total
    // of 80% bonus between all modifiers.  If an invalid job
    // is selected, the user will receive no modifiers
    switch(jobNum)
    {
        case 1: //Warrior Modifiers
            constitutionModJ = 1.1;
            strengthModJ = 1.5;
            dexterityModJ = 1.1;
            intelligenceModJ = 1;
            wisdomModJ = 1;
            perceptionModJ = 1.1;
            break;
        case 2: //Mage Modifiers
            constitutionModJ = .8;
            strengthModJ = .9;
            dexterityModJ = 1;
            intelligenceModJ = 1.55;
            wisdomModJ = 1.45;
            perceptionModJ = 1.1;
            break;
        case 3: //Priest Modifiers
            constitutionModJ = 1;
            strengthModJ = .7;
            dexterityModJ = 1;
            intelligenceModJ = 1.4;
            wisdomModJ = 1.6;
            perceptionModJ = 1.1;
            break;
        case 4: //Paladin Modifiers
            constitutionModJ = 1.5;
            strengthModJ = 1.3;
            dexterityModJ = .6;
            intelligenceModJ = 1.2;
            wisdomModJ = 1.2;
            perceptionModJ = 1;
            break;
        default: //Default job if an invalid job is selected
            constitutionModJ = 1;
            strengthModJ = 1;
            dexterityModJ = 1;
            intelligenceModJ = 1;
            wisdomModJ = 1;
            perceptionModJ = 1;
            cout << "ERROR: Invalid job selection.  All mods set to 0" << endl;
            break;
    }
}

/********************************************
// Mutators of stat modifiers and job name //
********************************************/
void Job::setJobName(string enterName)
{
    jobName = enterName;
}

bool Job::setConstModJ(double cMod)
{
    if(cMod>0)
    {
        constitutionModJ = cMod;
        return true;
    }
    cout << "ERROR: Cannot set modifier to negative value" << endl;
    return false;
}

bool Job::setStrModJ(double sMod)
{
    if(sMod>0)
    {
        strengthModJ = sMod;
        return true;
    }
    cout << "ERROR: Cannot set modifier to negative value" << endl;
    return false;
}

bool Job::setDexModJ(double dMod)
{
    if(dMod > 0)
    {
        dexterityModJ = dMod;
        return true;
    }
    cout << "ERROR: Cannot set modifier to negative value" << endl;
    return false;
}

bool Job::setIntModJ(double iMod)
{
    if(iMod>0)
    {
        intelligenceModJ = iMod;
        return true;
    }
    cout << "ERROR: Cannot set modifier to negative value" << endl;
    return false;
}

bool Job::setWisModJ(double wMod)
{
    if(wMod > 0)
    {
        wisdomModJ = wMod;
        return true;
    }
    cout << "ERROR: Cannot set modifier to negative value" << endl;
    return false;
}

bool Job::setPerModJ(double pMod)
{
    if(pMod > 0)
    {
        perceptionModJ = pMod;
        return true;
    }
    cout << "ERROR: Cannot set modifier to negative value" << endl;
    return false;
}

/*********************************************
// Accessors of stat modifiers and job name //
*********************************************/
string Job::getJobName(){return jobName;}

double Job::getConstModJ(){return constitutionModJ;}

double Job::getStrModJ(){return strengthModJ;}

double Job::getDexModJ(){return dexterityModJ;}

double Job::getIntModJ(){return intelligenceModJ;}

double Job::getWisModJ(){return wisdomModJ;}

double Job::getPerModJ(){return perceptionModJ;}

/************
// Methods //
************/
void Job::printAllJobMods()
{
    cout.precision(2);
    cout << fixed;
    cout << setfill('-') << setw(36) << "-" << endl;
    cout << setfill(' ') << setw(12) << right << "WARRIOR" << setw(7) << right << " X " << setw(9) << right <<  "MAGE" << endl;
    cout << "Cnst" << setw(6) << right << "Str" << setw(6) << right << "Dex" << " X "
        << "Cnst" << setw(6) << right << "Str" << setw(6) << right << "Dex" << endl;
    cout << 1.10 << setw(6) << right << 1.50 << setw(6) << right << 1.10 << " X "
        << 0.80 << setw(6) << right << 0.90 << setw(6) << right << 1.00 << endl;
    cout << " Int" << setw(6) << right << "Wis" << setw(6) << right << "Per" << " X "
        << " Int" << setw(6) << right << "Wis" << setw(6) << right << "Per" << endl;
    cout << 1.00 << setw(6) << right << 1.00 << setw(6) << right << 1.10 << " X "
        << 1.55 << setw(6) << right << 1.45 << setw(6) << right << 1.10 << endl;

    cout << setfill('-') << setw(36) << "-" << endl;
    cout << setfill(' ') << setw(11) << right << "PRIEST" << setw(8) << right << " X " << setw(11) << right <<  "PALADIN" << endl;
    cout << "Cnst" << setw(6) << right << "Str" << setw(6) << right << "Dex" << " X "
        << "Cnst" << setw(6) << right << "Str" << setw(6) << right << "Dex" << endl;
    cout << 1.00 << setw(6) << right << .700 << setw(6) << right << 1.00 << " X "
        << 1.50 << setw(6) << right << 1.30 << setw(6) << right << 0.60 << endl;
    cout << " Int" << setw(6) << right << "Wis" << setw(6) << right << "Per" << " X "
        << " Int" << setw(6) << right << "Wis" << setw(6) << right << "Per" << endl;
    cout << 1.40 << setw(6) << right << 1.60 << setw(6) << right << 1.10 << " X "
        << 1.20 << setw(6) << right << 1.20 << setw(6) << right << 1.00 << endl;
    cout << setfill('-') << setw(36) << "-" << endl;
}
/**********************
// Private Functions //
**********************/
int Job::jobCheck(string jobChoice)
{
    int num = 0;
    int i;
    int length = jobChoice.length();

    for(i = 0; i < length ; i++)
    {
        jobChoice[i] = tolower(jobChoice[i]);
    }

    if(jobChoice == "warrior")
        num = 1;
    else if(jobChoice == "mage")
        num = 2;
    else if(jobChoice == "priest")
        num = 3;
    else if(jobChoice == "paladin")
        num = 4;
    else
        num = -1;

    return num;
}
