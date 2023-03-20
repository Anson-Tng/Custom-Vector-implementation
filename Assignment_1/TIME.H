// Time.h

//---------------------------------------------------------------------------------

#ifndef TIME_H
#define TIME_H

//---------------------------------------------------------------------------------

#include<iostream>
#include<iomanip>

//---------------------------------------------------------------------------------

	/**
	 * @class Time
	 * @brief Manage all time variables, and able to display time with hours and minutes
	 *
	 *
	 *
	 * @author Anson Ting
	 * @version 01
	 * @date 10/04/2022 Anson Ting, Started
	 *
	 * @author Anson Ting
	 * @version 02
	 * @date 26/04/2022 Anson Ting, removed the seconds variable.
	 *
     * @author Anson Ting
	 * @version 03
	 * @date 26/04/2022 Anson Ting, validation check for hours and minutes.
	 *
	 * @todo To ensure this class is able to display time.
	 *
	 * @bug Not bug has found at the moment.
	 *
	 */

class Time{
public:
    Time();

        /**
        * @brief  Store all the variables into Time object
        *
        * Construct a time from entering hour and minutes.
        *
        * @param hours - hour, minutes - minute
        * @return New created Time object.
        */
    Time(int hours, int minutes);

        /**
        * @brief  Set method for setting hour.
        *
        *
        * @param hrs - hour
        * @return void
        * @pre only 1 to 24 are acceptable.
        */
    void setHours(int hrs);

        /**
        * @brief  Set method for setting minute.
        *
        *
        * @param mins - minutes
        * @return void
        * @pre only 0 to 59 are acceptable.
        */
    void setMinutes(int mins);

        /**
        * @brief  Retrieves the hours from time object.
        *
        *
        * @return const int
        */
    int getHours() const;

        /**
        * @brief  Retrieves the minutes from time object.
        *
        *
        * @return const int
        */
    int getMinutes() const;

private:
    int h; /// hours
    int m; /// minutes
};

    /**
    * @brief  output the data with designed format.
    *
    *
    * @return ostream
    */
std::ostream& operator <<(std::ostream& os, const Time& t);

#endif // TIME_H

