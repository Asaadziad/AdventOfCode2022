#include "section.h"
#include <iostream>

static int getRangePoint(std::string range_point){
    int r = 0;
    
    for(int i = 0;i < range_point.size(); i++){
        r *= 10;
        r += (range_point[i] - '0');
    }

    return r;
}

Section::Section(std::string assignment){
    int i = assignment.find("-");
    std::string first_point = assignment.substr(0,i);
    std::string second_point = assignment.substr(i+1);

    start_point = getRangePoint(first_point);
    end_point = getRangePoint(second_point);
}


bool Section::operator<(const Section& s){
    return start_point <= s.start_point && end_point >= s.end_point;
}

bool Section::operator<=(const Section& s){
    return (*this < s) ||
    ((start_point <= s.start_point && start_point <= s.end_point) && 
    (end_point >= s.start_point && end_point <= s.end_point)) ;
}
