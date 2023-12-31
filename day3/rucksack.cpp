#include "rucksack.h"

int rucksack::comapreCompartments(){
    int* first_prios = this->c1.getPrios();
    int* second_prios = this->c2.getPrios();
    for(int i = 1;i < 53;i++){
        if(first_prios[i] && second_prios[i]){
            return i;
        }
    }
    return 0;
}

rucksack::rucksack(const std::string literal){
    int size = literal.size();
    this->c1 = compartment(literal.substr(0,(size/2)));
    this->c2 = compartment(literal.substr((size/2)));
}

rucksack::rucksack(const rucksack& r){
    this->c1 = compartment(r.c1);
    this->c2 = compartment(r.c2);
}


    compartment& rucksack::getFirstCompartment(){
        return this->c1;
    }
    compartment& rucksack::getSecondCompartment(){
        return this->c2;
    }
