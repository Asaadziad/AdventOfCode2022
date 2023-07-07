#include "compartment.h"
#include <iostream>

static void setPriosToZero(int* prios,int size){
    for(int i = 0; i < size;i++){
        prios[i] = 0;
    }
}

compartment::compartment(){
    setPriosToZero(this->prios, 53);
    
}

compartment::compartment(const std::string literal): literal(literal){
    setPriosToZero(this->prios, 53);
    for(int i = 0; i < literal.size(); i++){
        this->prios[MAP(literal.at(i))]++;
    }
};

compartment::compartment(const compartment& c){

    this->literal = std::string(c.literal);
    setPriosToZero(this->prios, 53);
    for(int i = 0; i < 53;i++){
        
        prios[i] = c.prios[i];
    }
}

int* compartment::getPrios(){
    return this->prios;
}