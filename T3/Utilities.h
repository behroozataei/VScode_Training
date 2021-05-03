#ifndef UTILITIES_H
#define UTILITIES_H
 
#include <iostream>
#include <string>
#include <time.h>
#include <chrono>
//#include <boost/chrono/io/time_point_io.hpp>

namespace Util
{    
  
    const std::string CurrentDateTime()
    {

        typedef std::chrono::system_clock Clock;
        auto now1 = Clock::now();
        auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(now1);
        auto fraction = now1 - seconds;
        time_t cnow = Clock::to_time_t(now1);
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(fraction);
     
       // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
        time_t     now = time(NULL);
        struct tm  tstruct;
        char       buf[80];
        localtime_s(&tstruct, &now);
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
        sprintf(buf,"%s:%0.3d",buf,milliseconds.count()) ;            
        return buf;
        
       
        
    }
}


#endif