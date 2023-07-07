#ifndef PAIR_H
#define PAIR_H

#include <string>
#include "section.h"

class Pair{
    Section first_section;
    Section second_section;
    public:
    Pair(std::string assignment);
    bool isSectionsOverlaped();
    bool isSectionParlyOverlaped();
};

#endif