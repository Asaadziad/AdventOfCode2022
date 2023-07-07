#ifndef SECTION_H
#define SECTION_H
#include <string>

class Section{
    int start_point;
    int end_point;
    public:
    Section(){}
    Section(std::string assignment);
    bool operator<(const Section& s); // section is fully contained
    bool operator<=(const Section& s); // section is partly contained
};

#endif