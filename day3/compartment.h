#ifndef COMPARMENT_H
#define COMPARMENT_H

#include <string>
#define MAP(x) ((x) >= 'a' ? ((x) - 'a' + 1) : ((x) - 'A' + 27) )

class compartment{
    std::string literal;
    int prios[53];
    public:
    compartment();
    compartment(const compartment& c);
    compartment(const std::string literal);
    int* getPrios();
    
};

#endif