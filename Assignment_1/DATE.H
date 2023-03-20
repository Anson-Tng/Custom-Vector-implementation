// Date.h

//---------------------------------------------------------------------------------

#ifndef DATE_H
#define DATE_H

//---------------------------------------------------------------------------------

#include<iostream>
#include<iomanip>

//---------------------------------------------------------------------------------
	/**
	 * @class Date
	 * @brief Manage all date variables, and able to display date with day,month,year
	 *
	 *
	 *
	 *
	 *
	 * @author Anson Ting
	 * @version 01
	 * @date 14/03/2022 Anson Ting, Started
	 *
	 * @author Anson Ting
	 * @version 02
	 * @date 21/03/2022 Anson Ting, Add more details for Lab 3 and 4
	 *
	 * @author Anson Ting
	 * @version 03
	 * @date 26/04/2022 Anson Ting, Add more details for Assignment 1
	 *
	 *
	 * @todo To ensure this class is able to display date.
	 *
	 * @bug Not bug has found at the moment.
	 *
	 */

class Date
{
public:
    Date();

        /**
        * @brief  Store all the variables into Date object
        *
        * Construct a date from entering day, month and year.
        *
        * @param d - day, m - month, y - year
        * @return New created Date object.
        */
    Date(int d, int m, int y);

        /**
        * @brief  Set method for setting day.
        *
        *
        * @param d - day
        * @return void
        * @pre only 1 to 31 are acceptable.
        */
    void SetDay(int d);

        /**
        * @brief  Set method for setting month.
        *
        * @param m - month
        * @return void
        * @pre only 1 to 12 are acceptable.
        */
    void SetMonth(int m);

        /**
        * @brief  Set method for setting year.
        *
        * @param y - year
        * @return void
        */
    void SetYear(int y);

        /**
        * @brief  Retrieves the day from date object.
        *
        *
        * @return const int
        */
    int GetDay() const;

        /**
        * @brief  Retrieves the month from date object.
        *
        *
        *
        * @return const string
        */
    int GetMonth() const;

        /**
        * @brief  Retrieves the year from date object.
        *
        *
        * @return const int
        */
    int GetYear() const;

        /**
        * @brief  Print out the day, month and year of the date object
        *
        * Ex.  day / month / year
        *
        * @return void
        */
    void print() const;

private:
    int day;   /// day
    int month; /// month
    int year;  /// year


};

    /**
    * @brief  output the data with designed format.
    *
    *
    * @return ostream
    */
std::ostream & operator <<(std::ostream& os, const Date& d );

#endif
