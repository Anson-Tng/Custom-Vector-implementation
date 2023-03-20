#include "DATE.H"

// Default constructor
Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

// Constructor with parameters
Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

// Setter
void Date::SetDay(int d)
{
    if(d <=1 || d >=31)
        std::cout << "Invalid day entered.";
    else
        day = d;
}

// Setter
void Date::SetMonth(int m)
{
    if(m <= 1 || m >= 12)
        std::cout << "Invalid month entered.";
    else
        month = m;
}

// Stter
void Date::SetYear(int y)
{
    if(y <=1974 || y >=2022)
        std::cout << "Invalid year entered.";
    else
        year = y;
}

// Getter
int Date::GetDay() const
{
    return day;
}

// Getter
int Date::GetMonth() const
{
    return month;
}

// Getter
int Date::GetYear() const
{
    return year;
}

// Print date
void Date::print() const
{
    std::cout << day << "/" << month << "/" << year;
}

// default format of printing Date object.
std::ostream & operator <<(std::ostream& os, const Date& d )
{
  os << "Date: " << d.GetDay()
     << " / " << d.GetMonth()<< " / "
     << d.GetYear() <<'\n';
     return os;
}
