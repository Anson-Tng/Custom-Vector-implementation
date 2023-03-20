#include "WINDLOG.H"

// Header Vector
Vector<std::string> header;

// Column Vector
Vector<std::string> col;

// Vector of WindLog object
Vector<WindLog> windLog;


// Default constructor
WindLog::WindLog()
{
    nDate = Date();
    nTime = Time();
    nSpeed = 0;
    nSolarRadiation = 0;
    nTemperature = 0;
}

// constructor with parameters
WindLog::WindLog(Date d1, Time t1, float s1, float sr1, float temp1)
{
    nDate = d1;
    nTime = t1;
    nSpeed = s1;
    nSolarRadiation = sr1 / 6000;
    nTemperature = temp1;
}

// setter
void WindLog::setDate(Date nD)
{
    nDate = nD;
}

// setter
void WindLog::setTime(Time nT)
{
    nTime = nT;
}

// setter
void WindLog::setSpeed(float nS)
{
    nSpeed = nS;
}

// setter
void WindLog::setSolarRadiation(float nSR)
{
    nSolarRadiation = nSR / 6000;
}

// setter
void WindLog::setTemperature(float nTemp)
{
    nTemperature = nTemp;
}

// getter
Date WindLog::getDate() const
{
    return nDate;
}

// getter
Time WindLog::getTime() const
{
    return nTime;
}

// getter
float WindLog::getSpeed() const
{
    return nSpeed;
}

// getter
float WindLog::getSolarRadiation() const
{
    return nSolarRadiation;
}

// getter
float WindLog::getTemperature() const
{
    return nTemperature;
}

// Boolean for checking if the given year and month exist in the vector of WindLog.
bool WindLog::existingCheck (int year, int month) const
{
    for(int i=0;i<windLog.size();i++)
    {
        if(windLog.get(i).getDate().GetYear() == year && windLog.get(i).getDate().GetMonth() == month)
        {
            return true;
        }
    }
    return false;
}

// Return the index of wanted column position. Ex. Looking for WAST, Return index 0 ( First column data).
int WindLog::getHeaderIndex(Vector<std::string> vName, std::string hName) const
{
    int index = 0;
    for(int i=0;i<vName.size();i++)
    {
        if(vName.get(i) == hName)
        {
            index = i;
        }
    }
    return index;
}

// Load file function
void WindLog::loadFile(std::string fileName) const
{
    // print out which file is read.
    std::cout << "Loaded file: "+ fileName + '\n';
    std::ifstream newFile;
    newFile.open(fileName);

    // if the file can be open
    if(newFile.is_open())
    {
        WindLog newWL;
        Date newDate;
        Time newTime;
        std::string day, month, year, hour, minute, temp, headerList, hder;
        float nspeed = 0, nsolar = 0, ntemp = 0;
        int nday = 0, nmonth = 0, nyear = 0, nhour = 0, nminute = 0;

        getline(newFile, headerList,'\n');

        std::istringstream headerStream(headerList);

        // Read all the header into header vector
        while(headerStream.good() && getline(headerStream,hder,','))
        {
            header.pushBack(hder);
        }

        // find the index of wanted column from header vector
        int wastPos = getHeaderIndex(header, "WAST");
        int sPos = getHeaderIndex(header,"S");
        int srPos = getHeaderIndex(header,"SR");
        int tPos = getHeaderIndex(header,"T");

        // Read all the data from row by row
        while(newFile.good() && getline(newFile, temp,','))
        {
            col.pushBack(temp);

            for(int i=0;i<header.size()-2;i++)
            {
                getline(newFile,temp,',');
                col.pushBack(temp);
            }

            getline(newFile,temp,'\n');
            col.pushBack(temp);

            // get the WAST data and put it into istringstream
            std::string dNt = col.get(wastPos);
            std::istringstream dNtStream(dNt);

            // Read and store into WindLog if its not empty
            if(!dNtStream.str().empty())
            {
                getline(dNtStream, day, '/');
                getline(dNtStream, month, '/');
                getline(dNtStream, year, ' ');
                getline(dNtStream, hour, ':');
                getline(dNtStream, minute, ',');

                // String to Int
                nday = stoi(day);
                nmonth = stoi(month);
                nyear = stoi(year);
                nhour = stoi(hour);
                nminute = stoi(minute);

                if(col.get(sPos) == "")
                {
                    nspeed = 0;

                }else
                {
                    nspeed = stof(col.get(sPos));
                }
                if(col.get(srPos) == "")
                {
                    nsolar = 0;

                }else
                {
                    nsolar = stof(col.get(srPos));
                }
                if(col.get(tPos) == "")
                {
                    ntemp = 0;
                }else
                {

                    ntemp  = stof(col.get(tPos));
                }

                // Creating objects and pushback WindLog Vector
                newDate = Date(nday, nmonth, nyear); // <- LINE 214
                //newDate = Date(nmonth, nday, nyear); // <- LINE 215
                newTime = Time(nhour, nminute);
                newWL = WindLog(newDate, newTime, nspeed, nsolar, ntemp);
                windLog.pushBack(newWL);
                dNtStream.clear();
            }
            col.clearAll();
        }
        col.clearAll();
    } else
    {
        // if file cant be read, print invalid file.
        std::cout << "Invalid File.";
    }
    newFile.close();
}

// Round the float number into one decimal place
float WindLog::round(float f) const
{
    return ((float)((int)(f * 10 + 0.5))) / 10.0;
}

// Calculate the average of selected data type and specific year and month.
float WindLog::findAvg(std::string dataType, int year, int month) const
{
    int counter = 0;
    float sum = 0;

    if(dataType == "s" || dataType == "S")
    {
        for(int i=0;i<windLog.size();i++)
        {
            if(windLog.get(i).getDate().GetYear() == year && windLog.get(i).getDate().GetMonth() == month)
            {
                sum += windLog.get(i).getSpeed();
                counter++;
            }
        }
    } else if(dataType == "sr" || dataType == "SR")
    {
        for(int i=0;i<windLog.size();i++)
        {
            if(windLog.get(i).getDate().GetYear() == year && windLog.get(i).getDate().GetMonth() == month)
            {
                sum += windLog.get(i).getSolarRadiation();
                counter++;
            }
        }
    } else if(dataType == "t" || dataType == "T")
    {
        for(int i=0;i<windLog.size();i++)
        {
            if(windLog.get(i).getDate().GetYear() == year && windLog.get(i).getDate().GetMonth() == month)
            {
                sum += windLog.get(i).getTemperature();
                counter++;
            }
        }
    }
    return round(sum / counter);
}

// Calculate the mean of selected vector.
float WindLog::findMean(Vector<float> l) const
{
    float sum = 0;
    for(int i=1;i<l.size();i++)
    {
        sum += l.get(i);
    }
    return sum/l.size();
}

// Calculate the Standard deviation of selected data type and specific year and month.
float WindLog::findSd(std::string dataType, int year, int month) const
{
    Vector<float> dataList;
    float sum = 0, mean = 0;

    if(dataType == "s" || dataType == "S")
    {
        for(int i=0;i<windLog.size();i++)
        {
            if(windLog.get(i).getDate().GetYear() == year && windLog.get(i).getDate().GetMonth() == month)
            {
                dataList.pushBack(windLog.get(i).getSpeed());
            }
        }
    } else if(dataType == "sr" || dataType == "SR")
    {
        for(int i=0;i<windLog.size();i++)
        {
            if(windLog.get(i).getDate().GetYear() == year && windLog.get(i).getDate().GetMonth() == month)
            {
                dataList.pushBack(windLog.get(i).getSolarRadiation());
            }
        }
    } else if(dataType == "t" || dataType == "T")
    {
        for(int i=0;i<windLog.size();i++)
        {
            if(windLog.get(i).getDate().GetYear() == year && windLog.get(i).getDate().GetMonth() == month)
            {
                dataList.pushBack(windLog.get(i).getTemperature());
            }
        }
    }

    mean = findMean(dataList);

    for(int i=1;i<dataList.size();i++)
    {
        sum += (dataList.get(i) - mean) * (dataList.get(i) - mean);
    }
    return round(sqrt (sum / (dataList.size()-1)));
}

// Caluclate the sum of selected Data type and specific year and month
float WindLog::findTotal(std::string dataType, int year, int month) const
{
    float sum = 0;

        if(dataType == "s" || dataType == "S")
    {
        for(int i=0;i<windLog.size();i++)
        {
            if(windLog.get(i).getDate().GetYear() == year && windLog.get(i).getDate().GetMonth() == month)
            {
                sum += windLog.get(i).getSpeed();
            }
        }
    } else if(dataType == "sr" || dataType == "SR")
    {
        for(int i=0;i<windLog.size();i++)
        {
            if(windLog.get(i).getDate().GetYear() == year && windLog.get(i).getDate().GetMonth() == month)
            {
                sum += windLog.get(i).getSolarRadiation();
            }
        }
    } else if(dataType == "t" || dataType == "T")
    {
        for(int i=0;i<windLog.size();i++)
        {
            if(windLog.get(i).getDate().GetYear() == year && windLog.get(i).getDate().GetMonth() == month)
            {
                sum += windLog.get(i).getTemperature();
            }
        }
    }

    return round(sum);
}

// clear all unused vector and print exiting message.
void WindLog::exitProgram() const
{
    windLog.clearAll();
    col.clearAll();
    header.clearAll();
    std::cout << "\nThanks for using this program.\n";
}

// default format of printing WindLog object.
std::ostream& operator << (std::ostream& os, WindLog& wl)
{
    os << std::endl << std::endl;
    os << wl.getDate() << std::endl;
    os << wl.getTime() << std::endl;
    os << "Speed: " << wl.getSpeed() << " km/h" << std::endl;
    os << "\nSolar Radiation: " << wl.getSolarRadiation() << " kWh/m2" << std::endl;
    os << "\nTemperature: " << wl.getTemperature() << " Degree C" << std::endl;
    return os;
}

