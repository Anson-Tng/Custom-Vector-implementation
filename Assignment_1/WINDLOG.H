// WindLog.h

//---------------------------------------------------------------------------------
#ifndef WINDLOG_H
#define WINDLOG_H

//---------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

#include "DATE.H"
#include "TIME.H"
#include "VECTOR.H"

//---------------------------------------------------------------------------------

	/**
	 * @class WindLog
	 * @brief Manage all data, date and time
	 *
	 * This class included the calculation function of each result needed.
	 * Ex. find mean, find average, find standard deviation and round the number into
	 * one decimal.
	 *
	 * @author Anson Ting
	 * @version 01
	 * @date 20/04/2022 Anson Ting, Started
	 *
	 * @author Anson Ting
	 * @version 02
	 * @date 22/04/2022 Anson Ting, changed the algorithm of loadFile();
	 *
     * @author Anson Ting
	 * @version 03
	 * @date 25/04/2022 Anson Ting, added all calculation function into the class.
	 *
	 * @todo To ensure this class is able to handle reading file and do the calculation and output the file.
	 *
	 * @bug Not bug has found at the moment.
	 *
	 */

class WindLog{
public:
    WindLog();

        /**
        * @brief  Store all the variables into WindLog object
        *
        * Construct a WindLog from entering Date object, Time object,
        * wind speed, solar radiation, and temperature.
        *
        * @param d1 - Date, t1 - Time, s1 - float, sr1 - float, temp1 - float
        * @return New created WindLog object.
        */
    WindLog(Date d1, Time t1, float s1, float sr1, float temp1);

        /**
        * @brief  Set method for setting Date object.
        *
        *
        * @param nD - Date
        * @return void
        */
    void setDate(Date nD);

        /**
        * @brief  Set method for setting Time object.
        *
        *
        * @param nT - Time
        * @return void
        */
    void setTime(Time nT);

        /**
        * @brief  Set method for setting wind speed.
        *
        *
        * @param nS - float
        * @return void
        */
    void setSpeed(float nS);

        /**
        * @brief  Set method for setting solar radiation in kWh/m2.
        *
        *
        * @param nSR - float
        * @return void
        */
    void setSolarRadiation(float nSR);

        /**
        * @brief  Set method for setting temperature.
        *
        *
        * @param nTemp - float
        * @return void
        */
    void setTemperature(float nTemp);

        /**
        * @brief  Retrieves the Date object from WindLog object.
        *
        *
        * @return const Date
        */
    Date getDate() const;

        /**
        * @brief  Retrieves the Time object from WindLog object.
        *
        *
        * @return const Time
        */
    Time getTime() const;

        /**
        * @brief  Retrieves the wind speed from WindLog object.
        *
        *
        * @return const float
        */
    float getSpeed() const;

        /**
        * @brief  Retrieves the solar radiation from WindLog object.
        *
        *
        * @return const float
        */
    float getSolarRadiation() const;

        /**
        * @brief  Retrieves the temperature from WindLog object.
        *
        *
        * @return const float
        */
    float getTemperature() const;

        /**
        * @brief  A boolean to check if the year and month is existing in the data
        *
        * Ex. IF 2014 3(March) is exist in the data list, return true, else return false;
        *
        * @param year - int, month - int
        * @return const bool
        */
    bool existingCheck (int year, int month) const;

        /**
        * @brief  A function to find the column position of wanted data.
        *
        * Ex. Want to know which are the column position that stores wind speed(S),
        *     for loop from the begin of vector to find where is the "S" location
        *     and return the location.
        *
        * @param vName - vector<string>, hName - string
        * @return const int
        */
    int getHeaderIndex(Vector<std::string> vName, std::string hName) const;

        /**
        * @brief  This function handles reading data from the file and register all the data into the vector.
        *
        * First check if the file name is valid, if it's invalid then return invalid file,
        * if its valid then continue.
        *
        * The header will be first read and store into the header vector, in order to find which header is the wanted data to store in WindLog vector,
        * getHeaderIndex() function is called.
        *
        * Ex. In this case, four data are wanted from the file, WAST, S, SR, T. So the function will be used as
        *     getHeaderIndex(headerVector, "WAST")
        *     getHeaderIndex(headerVector, "S")
        *     getHeaderIndex(headerVector, "SR")
        *     getHeaderIndex(headerVector, "T")
        *
        * Now have the index of wanted data, read in data row by row and only store the wanted column data into the WindLog object.
        *
        *
        * @param fileName - string
        * @return const void
        */
    void loadFile(std::string fileName) const;

        /**
        * @brief  A function to round the float number into one decimal place
        *
        *
        * @param f - float
        * @return const flat
        */
    float round(float f) const;

        /**
        * @brief  A function calculate the average.
        *
        * calculate the average from selected data type and year and month.
        *
        * Ex. dataType = S, year = 2014, month = 3
        *     return 5.6 km/h
        *
        * @param dataType - string, year - int, month - int
        * @return const float
        */
    float findAvg(std::string dataType, int year, int month) const;

        /**
        * @brief  A function calculate the mean.
        *
        * calculate the mean from selected vector.
        *

        *
        * @param l - Vector<float>
        * @return const float
        */
    float findMean(Vector<float> l) const;

        /**
        * @brief  A function calculate the standard deviation.
        *
        * calculate the standard deviation from selected data type and year and month.
        *
        * Ex. dataType = S, year = 2014, month = 3
        *     return 3
        *
        * @param dataType - string, year - int, month - int
        * @return const float
        */
    float findSd(std::string dataType, int year, int month) const;

        /**
        * @brief  A function calculate the sum.
        *
        * calculate the sum from selected data type and year and month.
        *
        * Ex. dataType = S, year = 2014, month = 3
        *     return 5.6 km/h
        *
        * @param dataType - string, year - int, month - int
        * @return const float
        */
    float findTotal(std::string dataType, int year, int month) const;

        /**
        * @brief  A function to clear all the vector and print exit message
        *
        *
        * @return const void
        */
    void exitProgram() const;


private:
    Date nDate;             /// Date class object
    Time nTime;             /// Time class object
    float nSpeed;           /// Speed with Km/h
    float nSolarRadiation;  /// Solar Radiation with kWh/m2
    float nTemperature;     /// Temperature with degrees C


};

    /**
    * @brief  output the data with designed format.
    *
    *
    * @return ostream
    */
std::ostream& operator << (std::ostream& os, WindLog& wl);

#endif // WINDLOG_H
