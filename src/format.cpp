#include <string>
#include "format.h"

using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long input) { 
    long hours_long = input/3600;
    string hours_str = to_string(hours_long);
    if(hours_str.length() == 1){
        hours_str = "0" + hours_str;
    }
    //Truncate hours_str if its length is more than 2
    if(hours_str.length() > 2){
        hours_str = hours_str.substr(hours_str.length()-2,2);
    }

    long minutes_long = (input - hours_long*3600)/60;
    string minutes_str = to_string(minutes_long);
    if(minutes_str.length() == 1){
        minutes_str = "0" + minutes_str;
    }
    long seconds_long = input - hours_long*3600 - minutes_long*60;
    string seconds_str = to_string(seconds_long);
    if(seconds_str.length() == 1){
        seconds_str = "0" + seconds_str;
    }

    return hours_str + ":" + minutes_str + ":" + seconds_str; 

}