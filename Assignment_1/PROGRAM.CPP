#include "PROGRAM.H"

int Program::getHeaderIndex (vectorC<std::string> vName, std::string hName)
{
    for(int i=0;i<vName.size();i++)
    {
        if (vName.get(i) == hName)
        {
            return i;
        }
    }
}
void Program::loadData()
{
    vectorC<std::string> header;
    vectorC<WindLogType> windlog;
    WindLogType newWLG;
    Date nDate;
    Time nTime;
    std::string dateTime,temp,speed,solarR,temperature,day,month,year,hour,minute,hderlist,hder;
    float ns,nsr,nt;
    int nd,nm,ny,nh,nmin,wastPos,sPos,srPos,tPos;

    std::ifstream newFile;
    newFile.open("MetData-31-3b.csv");
    //newFile.open("MetData_Mar01-2014-Mar01-2015-ALL.csv");


    getline(newFile,hderlist,'\n');
    std::istringstream iss(hderlist);

    while(iss.good()){
            getline(iss,hder,',');
            header.pushBack(hder);
    }

    while(newFile.good() && getline(newFile, day, '/')){
        getline(newFile, month, '/');
        getline(newFile, year, ' ');
        getline(newFile, hour, ':');
        getline(newFile, minute, ',');

        wastPos = getHeaderIndex(header,"WAST");
        sPos = getHeaderIndex(header,"S");
        srPos = getHeaderIndex(header,"SR");
        tPos = getHeaderIndex(header,"T");


        for(int i=0;i<sPos-1;i++)
        {
            getline(newFile, temp, ',');
        }

        getline(newFile, speed, ',');

        if(srPos - sPos == 1){
            getline(newFile, solarR, ',');
        }

        if(tPos - srPos == 1){
            getline(newFile, temperature, ',');
        } else if(tPos == header.size()-1){
            for(int i=0;i<tPos-srPos-1;i++){
                getline(newFile,temp,',');
            }
            getline(newFile,temperature,'\n');

        }

        if(day.find(',')){
            ns = stof(speed);
            nsr = stof(solarR);
            nt = stof(temperature);
            nd = stoi(day);
            nm = stoi(month);
            ny = stoi(year);
            nh = stoi(hour);
            nmin = stoi(minute);

            nDate = Date(nd, nm, ny);
            nTime = Time(nh, nmin);
            newWLG = WindLogType{nDate, nTime, ns, nsr, nt};
            windlog.pushBack(newWLG);
        }
    }


    newFile.close();
}
