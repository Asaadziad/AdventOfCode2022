#include "compartment.h"

static void setPriosToZero(int* prios,int size){
    for(int i = 0; i < size;i++){
        prios[i] = 0;
    }
}

compartment::compartment(const std::string literal): literal(literal){
    setPriosToZero(this->prios, 53);
    for(int i = 0; i < literal.size(); i++){
        this->prios[MAP(literal.at(i))]++;
    }
};

int* compartment::getPrios(){
    return this->prios;
}