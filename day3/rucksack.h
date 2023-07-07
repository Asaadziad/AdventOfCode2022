#ifndef RUCKSACK_H
#define RUCKSACK_H
#include "compartment.h"
#include <string>

class rucksack {
    compartment c1;
    compartment c2;
    public:
    /*
    * Returns: an item type prio (int) of the item that is shared between two compartments
    *
    */
    rucksack(){}
    rucksack(const rucksack& r);
    rucksack(const std::string literal);
    int comapreCompartments();
    compartment& getFirstCompartment();
    compartment& getSecondCompartment();
};

#endif