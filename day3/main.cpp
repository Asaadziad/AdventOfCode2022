#include <iostream>
#include <fstream>
#include <string>
#include "rucksack.h"

void parseComparments(std::string comparment, int* prios);


int main(){
    std::fstream file("input.txt");
    std::string buffer;
    int sum = 0;
    while (getline(file,buffer))
    {
        rucksack r(buffer);
        sum += r.comapreCompartments();
    }
    std::cout << std::to_string(sum);
    return 0;
}



void parseComparments(std::string comparment, int* prios){
    
}