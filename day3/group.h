#ifndef GROUP_H
#define GROUP_H

#include "rucksack.h"

class Group {
    rucksack group[3];
    int prios[53];
    int current_pos;
    public:
    Group():current_pos(0){}
    void addRuckSack(const rucksack& r);
    int getBadge(); // returns the points required from the badge
};

#endif