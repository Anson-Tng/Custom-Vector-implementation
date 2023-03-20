#include<iostream>
#include<iomanip>
#include "WINDLOG.H"
#include<limits>
WindLog wl;

void printMenu()
{
    // MAIN MENU FOR THE PROGRAM
    std::cout <<"\n===================================================================="<< std::endl;
    std::cout <<"========================ICT 283 Assignment 1========================"<< std::endl;
    std::cout <<"===================================================================="<< std::endl << std::endl;
    std::cout <<"=============================== MENU ==============================="<< std::endl << std::endl;
    std::cout <<"= 1. Average and sample standard deviation of wind speed.          ="<< std::endl << std::endl;
    std::cout <<"= 2. Average and staple standard deviation of ambient temperature. ="<< std::endl << std::endl;
    std::cout <<"= 3. Total solar radiation in kWh/m2.                              ="<< std::endl << std::endl;
    std::cout <<"= 4. Display All data and write to data/WindTempSolar.csv.         ="<< std::endl << std::endl;
    std::cout <<"= 5. Exit.                                                         ="<< std::endl << std::endl;
    std::cout <<"===================================================================="<< std::endl;
}

std::string toMonthString(int m)
{
    // Change the month into word.
    switch(m)
    {
        case 1:
            return "January";
            break;
        case 2:
            return "February";
            break;
        case 3:
            return "March";
            break;
        case 4:
            return "April";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return "August";
            break;
        case 9:
            return "September";
            break;
        case 10:
            return "October";
            break;
        case 11:
            return "November";
            break;
        case 12:
            return "December";
            break;
        default  :
            return "FAULT";
            break;
    }
}

void feature1()
{
    // calculate the average wind speed and staple standard deviation for the wind speed
    // given specified month and year.
    int year = 0, month = 0;
    bool validDate = true;
    std::cout << "\nOption 1\n";

    std::cout << "\nPlease enter year: \n";
    std::cin >> year;
    std::cout << '\n';

    while(validDate)
    {
    // While loop for year validation check
        if(year < 1 || std::cin.fail())
        {
            std::cout << "\nPlease enter valid year\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> year;
            validDate = true;
        } else
        {
            validDate =false;
        }
    }

    validDate = true;

    std::cout << "\nPlease enter month: \n";
    std::cin >> month;

    while(validDate)
    {
    // while loop for month validation check

        if(month < 1 || month > 12 || std::cin.fail())
        {
            std::cout << "\nPlease enter valid month\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> month;
            validDate = true;
        } else
        {
            validDate = false;
        }
    }

    if(wl.existingCheck(year, month))
    {
    // if the entered year and month is exist in the data list, do the calculation and print out answers.
        if(wl.findAvg("S", year, month) == 0)
        {
            std::cout<< toMonthString(month) << ": No Data\n";

        } else
        {
            std::cout << '\n' << toMonthString(month) << ' ' << year << ": \n";
            std::cout << "Average speed: " << wl.findAvg("S", year, month) << " km/h\n";
            std::cout << "Sample stdev: "  << wl.findSd("S", year, month) << '\n';
        }
    } else
    {
        std::cout << '\n' << toMonthString(month) << ' ' << year << ": No Data\n";
    }
}

void feature2()
{
    // calculate the average ambient air temperature and staple standard deviation for each month of a
    // specified year.
    int year = 0;
    bool validDate = true;
    std::cout << "\nOption 2\n";
    std::cout << "\nPlease enter year: \n";
    std::cin >> year;
    std::cout << '\n';
    while(validDate)
    {
    // while loop for year validation check
        if(year < 1 || std::cin.fail())
        {
            std::cout << "\nPlease enter valid year\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> year;
            validDate = true;
        } else
        {
            validDate =false;
        }
    }
    std::cout << year << '\n';
    for(int i=0;i<12;i++)
    {
        if(wl.existingCheck(year, (i+1)))
        {
        // if the entered year and month is exist in the data list, do the calculation and print out answers.
            std::cout << toMonthString(i+1) << ": average: " << wl.findAvg("T",year,(i+1)) << " degrees C, stdev: "
                      << wl.findSd("T", year, (i+1)) << '\n';
        } else
        {
        // if not exist in the data list, print No Data.
            std::cout<< toMonthString(i+1) << ": No Data\n";
        }

    }
}

void feature3()
{
    // calculate total solar radiation in kWh/m2 for each month of a specified year.
    int year = 0;
    bool validDate = true;
    std::cout << "\nOption 3\n";
    std::cout << "\nPlease enter year: \n";
    std::cin >> year;
    std::cout << '\n';
    while(validDate)
    {
    // while loop for year validation check
        if(year < 1 || std::cin.fail())
        {
            std::cout << "\nPlease enter valid year\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> year;
            validDate = true;
        } else
        {
            validDate =false;
        }
    }
    std::cout << year << '\n';
    for(int i=0;i<12;i++)
    {
        if(wl.existingCheck(year, (i+1)))
        {
        // if the entered year and month is exist in the data list, do the calculation and print out answers.
            std::cout << toMonthString(i+1) << ": " << wl.findTotal("SR",year,(i+1)) << " kWh/m2 \n";
        } else
        {
        // if not exist in the data list, print No Data.
            std::cout<< toMonthString(i+1) << ": No Data\n";
        }
    }
}

void feature4()
{
    // print out the average wind speed, average ambient air temperature and total solar radiation for each month
    // of a specified year, and print to a file called WindTempSolar.csv .
    int year = 0;
    bool validDate = true;
    std::ofstream toFile("data/WindTempSolar.csv");
    std::cout << "\nOption 4\n";
    std::cout << "\nPlease enter year: \n";
    std::cin  >> year;
    std::cout << std::endl;
    while(validDate)
    {
    // while loop for year validation check
        if(year < 1 || std::cin.fail() )
        {
            std::cout << "\nPlease enter valid year\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> year;
            validDate = true;
        } else
        {
            validDate =false;
        }
    }

    std::cout << year << '\n';
    toFile << year << '\n';
    for(int i=0;i<12;i++)
    {
        if(wl.existingCheck(year, (i+1)))
        {
        // if the entered year and month is exist in the data list, do the calculation and print out answers.
        // at the same time, print into the WindTempSolar.csv
            std::cout << toMonthString(i+1) << ',';
            toFile    << toMonthString(i+1) << ',';
            if(wl.findAvg("S",year, (i+1)) != 0)
            {
                std::cout << wl.findAvg("S",year, (i+1)) << '(' << wl.findSd("S", year, (i+1)) << ')' << ',';
                toFile    << wl.findAvg("S",year, (i+1)) << '(' << wl.findSd("S", year, (i+1)) << ')' << ',';
            } else
            {
                std::cout << ',';
                toFile    << ',';
            }
            if(wl.findAvg("T",year, (i+1)) != 0)
            {
                std::cout << wl.findAvg("T",year, (i+1)) << '(' << wl.findSd("T", year, (i+1)) << ')' << ',';
                toFile    << wl.findAvg("T",year, (i+1)) << '(' << wl.findSd("T", year, (i+1)) << ')' << ',';
            }else
            {
                std::cout << ',';
                toFile    << ',';
            }
            if(wl.findTotal("SR",year, (i+1)) != 0)
            {
                std::cout << wl.findTotal("SR",year,(i+1)) << '\n';
                toFile    << wl.findTotal("SR",year,(i+1)) << '\n';
            }else
            {
                std::cout << ',';
                toFile    << ',';
            }

        } else
        {
            // if not exist in the data list, print month and leave blank.
            std::cout << toMonthString(i+1) << '\n';
            toFile    << toMonthString(i+1) << '\n';

        }
    }
    toFile.close();
    std::cout << "\nThe data successfully printed into data/WindTempSolar.csv.\n";
}

int main()
{
    //wl.loadFile("data/MetData-31-3b.csv");
    wl.loadFile("data/MetData_Mar01-2014-Mar01-2015-ALL.csv");



    //====================================================================================================
    // The two files below are downloaded from http://wwwmet.murdoch.edu.au/downloads.
    // Due to those files have different Date format,
    // in order to test run the files below, Please go to WINDLOG.CPP comment out line 214 and uncomment line 215.
    // (Manually change the read in date format.)
    //====================================================================================================
    //-------------------------------------------------------------

    //wl.loadFile("data/MurdochMetData_27Apr2022-28Apr2022.csv");

    //wl.loadFile("data/MurdochMetData_01Jan2022-01Apr2022.csv");

    //-------------------------------------------------------------

    bool menuLoop = true;
    int ans = 0;

    do
    {
    // MENU LOOP
        printMenu();
        std::cout << "\n Enter: ";
        std::cin >> ans;

        if(std::cin.fail())
        {
        // User input validation check, only enter 1 - 5.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ans = 99;
        }

        switch(ans)
        {
            case 1:
                feature1();
                break;
            case 2:
                feature2();
                break;
            case 3:
                feature3();
                break;
            case 4:
                feature4();
                break;
            case 5:
                wl.exitProgram();
                return 0;
            default:
                    std::cout << "\nPlease enter only numbers (1-5)\n\n";
        }
    } while(menuLoop);

    return 0;
}
