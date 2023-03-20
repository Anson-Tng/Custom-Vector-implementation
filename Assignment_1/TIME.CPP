#include "TIME.H"

// Default constructor
Time::Time()
{
    h = 0;
    m = 0;
}

// Constructor with parameters
Time::Time(int hours, int minutes)
{
    h = hours;
    m = minutes;
}

// Setter
void Time::setHours(int hrs)
{
    if(hrs >= 24 || hrs <= 1)
    {
        std::cout << "invalid hours";
    } else
    {
    h = hrs;
    }
}

// Setter
void Time::setMinutes(int mins)
{
    if(mins >= 59 || mins <= 0)
    {
        std::cout << "invalid minutes";
    } else
    {
    m = mins;
    }
}

// Getter
int Time::getHours() const
{
    return h;
}

// Getter
int Time::getMinutes() const
{
    return m;
}

// default format of printing Time object.
std::ostream& operator <<(std::ostream& os, const Time& t)
{
    os << "Time: " << std::setw(2) << std::setfill('0') << t.getHours() << ':'
       << std::setw(2) << std::setfill('0') << t.getMinutes() << std::endl;
    return os;
}

