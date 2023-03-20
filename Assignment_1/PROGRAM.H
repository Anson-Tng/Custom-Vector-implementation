#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "DATE.H"
#include "TIME.H"
#include "VECTOR.H"

class Program{

public:
    void loadData(std::string fileName);
    void saveData();
    int getHeaderIndex(vectorC<std::string> vName, std::string hName);

private:
    typedef struct {
    Date d;
    Time t;
    float speed;
    float solarR;
    float temperature;

    WindLogType(Date d1, Time t1, float s1, float sr1, float temp1)
    {
        d = d1;
        t = t1;
        speed = s1;
        solarR = sr1;
        temperature =temp1;
    }
    }WindLogType;


};
#endif

