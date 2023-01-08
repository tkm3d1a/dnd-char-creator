/*************
Job.h
Job Class

by: Tim Klimpel
version Date: 07.29.2015
version num: 0.4
**************/

#ifndef JOB_H
#define JOB_H
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

class Job
{
    public:
        // Constructors
        Job(); // Default, no job
        Job(string); // Job choice selected

        // Mutators
        void setJobName(string);
        bool setConstModJ(double);
        bool setStrModJ(double);
        bool setDexModJ(double);
        bool setIntModJ(double);
        bool setWisModJ(double);
        bool setPerModJ(double);

        // Accessors
        string getJobName();
        double getConstModJ();
        double getStrModJ();
        double getDexModJ();
        double getIntModJ();
        double getWisModJ();
        double getPerModJ();

        // Methods
        void printAllJobMods();

    private:
        string jobName;
        double constitutionModJ;
        double strengthModJ;
        double dexterityModJ;
        double intelligenceModJ;
        double wisdomModJ;
        double perceptionModJ;

        // Private method
        // Used to change a job string into an Int to allow use of switch in constructor
        // Easier to handle and write statement for setting default mod values
        int jobCheck(string);
};

#endif // JOB_H
