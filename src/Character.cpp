/*************
Character.cpp
Character Class

by: Tim Klimpel
version Date: 07.29.2015
version num: 0.5
**************/

#include "Character.h"

/*******************
/// Constructors ///
*******************/
Character::Character():Job(),Race() //Default character
{
    race = getRaceName();
    job = getJobName();
    name = "BASE_CHAR";
    setConst(10);
    setStr(10);
    setDex(10);
    setInt(10);
    setWis(10);
    setPer(10);
}

Character::Character(string charName):Job(),Race()
{
    race = getRaceName();
    job = getJobName();
    name = charName;
    setConst(10);
    setStr(10);
    setDex(10);
    setInt(10);
    setWis(10);
    setPer(10);
}

Character::Character(string charName, string jobName, string raceName):Job(jobName),Race(raceName)
{
    race = getRaceName();
    job = getJobName();
    name = charName;
    setConst(10);
    setStr(10);
    setDex(10);
    setInt(10);
    setWis(10);
    setPer(10);
}


// Mutators
void Character::setRace(string charRace)
{
    race = charRace;
}

void Character::setJob(string charJob)
{
    job = charJob;
}

void Character::setCharName(string charName)
{
    name = charName;
}

void Character::setConst(double charConst)
{
    double modifiedConst, totalCMod;

    totalCMod = getConstModJ()*getConstModR();
    modifiedConst = totalCMod*charConst;

    constitution = modifiedConst;
}

void Character::setStr(double charStr)
{
    double modifiedStr, totalSMod;

    totalSMod = getStrModJ()*getStrModR();
    modifiedStr = totalSMod*charStr;

    strength = modifiedStr;
}

void Character::setDex(double charDex)
{
    double modifiedDex, totalDMod;

    totalDMod = getDexModJ()*getDexModR();
    modifiedDex = totalDMod*charDex;

    dexterity = modifiedDex;
}

void Character::setInt(double charInt)
{
    double modifiedInt, totalIMod;

    totalIMod = getIntModJ()*getIntModR();
    modifiedInt = totalIMod*charInt;

    intelligence = modifiedInt;
}

void Character::setWis(double charWis)
{
    double modifiedWis, totalWMod;

    totalWMod = getWisModJ()*getWisModR();
    modifiedWis = totalWMod*charWis;

    wisdom = modifiedWis;
}

void Character::setPer(double charPer)
{
    double modifiedPer, totalPMod;

    totalPMod = getPerModJ()*getPerModR();
    modifiedPer = totalPMod*charPer;

    perception = modifiedPer;
}

// Accessors
string Character::getRace()
{
    return race;
}

string Character::getJob()
{
    return job;
}

string Character::getCharName()
{
    return name;
}
double Character::getConst()
{
    return constitution;
}

double Character::getStr()
{
    return strength;
}

double Character::getDex()
{
    return dexterity;
}

double Character::getInt()
{
    return intelligence;
}

double Character::getWis()
{
    return wisdom;
}

double Character::getPer()
{
    return perception;
}

// Methods
string Character::printCharInfo() //Printing charinfo to the screen for the user
{
    stringstream ss;
    ss.precision(2);
    ss << fixed;
    ss << "Name: " << getCharName() << "\nRace: " << getRace() << "\nJob: " << getJob()
        << "\nStats...\nConst\tStr\tDex\n" << constitution << "\t" << strength << "\t" << dexterity
        << "\n\nInt\tWis\tPer\n" << intelligence << "\t" << wisdom << "\t" << perception << "\n\n";
    return ss.str();
}

string Character::printCharInfo(string charName) //Printing charinfo to a file with the characters name
{
    string fileName;
    stringstream fN, oF;
    ofstream outputFile;

    oF << charName << ".txt";
    fileName = oF.str();

    outputFile.open(fileName.c_str());

    fN.precision(3);
    fN << fixed;
    fN << "Name: " << getCharName() << "\nRace: " << getRace() << "\nJob: " << getJob()
        << "\nStats...\nConst\tStr\tDex\n" << constitution << "\t" << strength << "\t" << dexterity
        << "\n\nInt\tWis\tPer\n" << intelligence << "\t" << wisdom << "\t" << perception << "\n\n";

    outputFile << fN.str();
    outputFile.close();
    return fileName;
}

string Character::exportCharInfo() // Exporting character info to an easier to read file for other programs
{
    string fileName;
    stringstream modFN;
    int fNLength,i;
    ofstream exportFile;
    //charExportCount++;

    fileName = getCharName();
    fNLength = fileName.length();

    for(i = 0; i<fNLength; i++)
    {
        if(fileName[i] == ' ')
            fileName[i] = '_';
    }

    modFN << fileName << "EXPORT.txt";
    fileName = modFN.str();

    exportFile.open(fileName.c_str());

    exportFile << getCharName() << endl;
    exportFile << getRace() << endl;
    exportFile << getJob() << endl;
    exportFile << constitution << endl;
    exportFile << strength << endl;
    exportFile << dexterity << endl;
    exportFile << intelligence << endl;
    exportFile << wisdom << endl;
    exportFile << perception << endl;

    exportFile.close();

    return fileName;
}

void Character::assignAttPoints(int c,int s, int d, int i, int w, int p)
{
    setConst((double)c);
    setStr((double)s);
    setDex((double)d);
    setInt((double)i);
    setWis((double)w);
    setPer((double)p);
}
