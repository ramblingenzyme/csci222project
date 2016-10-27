#ifndef TIME_UTILITY_H
#define TIME_UTILITY_H

#include <ctime>
#include <string>
#include <exception>

class timeUt{
    public:
	    timeUt(){};
	    ~timeUt(){};
	    std::string get_current_time();
};

std::string timeUt::get_current_time(){
    try {
    time_t rawtime;
    struct tm *timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    mktime ( timeinfo );

    std::string result;

    result = std::to_string(timeinfo->tm_year + 1900) + "-"
	    + std::to_string(timeinfo->tm_mon + 1) + "-"
	    + std::to_string(timeinfo->tm_mday) +" "
	    + std::to_string(timeinfo->tm_hour) + ":"
	    + std::to_string(timeinfo->tm_min) + ":"
	    + std::to_string(timeinfo->tm_sec);
    return result;
    } catch (std::exception &e) {
	return e.what();
    }
}
#endif
