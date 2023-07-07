#include "group.h"
#include <iostream>
void Group::addRuckSack(const rucksack& r){
    
    //this->group[this->current_pos] = rucksack(r);
    if(current_pos >= 3) {current_pos = 0;};
    this->group[this->current_pos] = rucksack(r);
    this->current_pos++;
}

int Group::getBadge(){
    for(int i =0;i<53;i++){ prios[i] = 0;}
    for(int i = 0;i < 3;i++){ // for each rucksack ( 3 )
        for(int j = 0 ; j < 53;j++){
        if(group[i].getFirstCompartment().getPrios()[j] || 
            group[i].getSecondCompartment().getPrios()[j]){
                prios[j]++; // for each line ( elf ) adds 1
            }
        }
    }
    for(int k = 0; k < 53;k++){
        if(prios[k] >= 3 ) {return k;} // return the prio that appeared in 3 lines
    }
    return 0;
}